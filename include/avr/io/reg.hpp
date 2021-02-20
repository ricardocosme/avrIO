#pragma once

#include "avr/io/detail/reg.hpp"
#include "avr/io/detail/type_traits/enable_if.hpp"
#include "avr/io/detail/type_traits/is_base_of.hpp"
#include "avr/io/detail/type_traits/is_same.hpp"

#include <stdint.h>

namespace avr { namespace io {
struct reg_bit_base {};
struct reg_base {};

template<typename Reg>
struct reg_value_t {
    using reg = Reg;
    uint8_t value;
    reg_value_t operator~() const noexcept
    { return {static_cast<uint8_t>(~value)}; }
};

template<typename Reg, uint8_t Bit>
struct var_reg_bit_t;

template<typename Reg, uint8_t Bit>
struct reg_bit_t : reg_bit_base {
    using reg = Reg;
    static constexpr uint8_t bit{Bit};
    uint8_t bv() const noexcept { return 1<<bit; }
    bool state() const noexcept { return true; }
    var_reg_bit_t<Reg, bit> operator()(bool b) const noexcept
    { return {b}; }
    var_reg_bit_t<Reg, bit> operator~() const noexcept
    { return {false}; }
};

template<typename Reg, uint8_t Bit>
class var_reg_bit_t : public reg_bit_t<Reg, Bit> {
    bool _state;
public:
    using base = reg_bit_t<Reg, Bit>;
    var_reg_bit_t(bool v) : _state(v) {}
    uint8_t bv() const noexcept { return _state ? 1<<base::bit : ~(1<<base::bit); }
    bool state() const noexcept { return _state; }
    var_reg_bit_t& operator()(bool b) noexcept {
        _state = b;
        return *this;
    }
    var_reg_bit_t operator~() noexcept {
        _state = !state;
        return *this;
    }
};

template<uint8_t addr_>
struct reg_t : reg_base {
    static volatile uint8_t& addr() noexcept
    { return *reinterpret_cast<volatile uint8_t*>(addr_); }

    struct bits_t {
        uint8_t v;
        template<typename... RegBits>
        bits_t(RegBits... regbits) noexcept : v(detail::or_(regbits...)) {}
    };
    
    const reg_t& operator=(const bits_t& o) const noexcept {
        addr() = o.v;
        return *this;
    }
    
    const reg_t& operator=(uint8_t o) const noexcept {
        addr() = o;
        return *this;
    }
    
    template<typename T,
             typename E = detail::enable_if_t<
                 detail::is_base_of<reg_bit_base, T>::value>
             >
    const reg_t&
    operator=(const T& o) const noexcept {
        addr() = o.bv();
        return *this;
    }
    
    template<typename Reg>
    const reg_t& operator=(reg_value_t<Reg> o) const noexcept {
        addr() = o.value;
        return *this;
    }
    
    const reg_t& operator|=(uint8_t o) const noexcept {
        addr() = addr() | o;
        return *this;
    }

    template<typename T,
             typename E = detail::enable_if_t<
                 detail::is_base_of<reg_bit_base, T>::value>
             >
    const reg_t&
    operator|=(const T& o) const noexcept {
        addr() = addr() | o.bv();
        return *this;
    }
    
    template<typename T,
             typename E = detail::enable_if_t<
                 detail::is_same<T, reg_t>::value>
             >
    const reg_t& operator|=(const reg_value_t<T>& o) const noexcept {
        addr() = addr() | o.value;
        return *this;
    }
        
    const reg_t& operator&=(uint8_t o) const noexcept {
        addr() = addr() & o;
        return *this;
    }

    template<typename T,
             typename E = detail::enable_if_t<
                 detail::is_base_of<reg_bit_base, T>::value>
             >
    const reg_t&
    operator&=(const T& o) const noexcept {
        addr() = addr() & o.bv();
        return *this;
    }
    
    template<typename T,
             typename E = detail::enable_if_t<
                 detail::is_same<T, reg_t>::value>
             >
    const reg_t& operator&=(const reg_value_t<T>& o) const noexcept {
        addr() = addr() & o.value;
        return *this;
    }
    
    template<typename... RegBit>
    [[gnu::always_inline]] static void set(RegBit... regbits) noexcept
    { detail::set<reg_t>(false, regbits...); }

    template<typename... RegBit>
    [[gnu::always_inline]] static void clear(RegBit... regbits) noexcept
    {
        auto clr = detail::clear_aux<reg_t>(true, regbits...);
        if(clr != 0xff)
            addr() = addr() & clr;
    }
};

template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<reg_base, Reg>::value,
    reg_value_t<Reg>>
operator|(const Reg& lhs, uint8_t rhs)
{ return {static_cast<uint8_t>(lhs.addr() | rhs)}; }

template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<reg_base, Reg>::value,
    reg_value_t<Reg>>
operator|(uint8_t lhs, const Reg& rhs)
{ return {static_cast<uint8_t>(lhs | rhs.addr())}; }

template<typename LReg, typename RRegBit>
detail::enable_if_t<
    detail::is_base_of<reg_bit_base, RRegBit>::value
    && detail::is_base_of<reg_base, LReg>::value,
    reg_value_t<typename RRegBit::reg>>
operator|(const LReg& lhs, const RRegBit& rhs) {
    static_assert(detail::is_same<LReg, typename RRegBit::reg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.addr() | rhs.bv())};
}

template<typename LRegBit, typename RReg>
detail::enable_if_t<
    detail::is_base_of<reg_bit_base, LRegBit>::value
    && detail::is_base_of<reg_base, RReg>::value,
    reg_value_t<typename LRegBit::reg>>
operator|(const LRegBit& lhs, const RReg& rhs) {
    static_assert(detail::is_same<typename LRegBit::reg, RReg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.bv() | rhs.addr())};
}

template<typename LRegBit, typename RRegBit>
detail::enable_if_t<
    detail::is_base_of<reg_bit_base, LRegBit>::value
    && detail::is_base_of<reg_bit_base, RRegBit>::value,
    reg_value_t<typename LRegBit::reg>>
operator|(const LRegBit& lhs, const RRegBit& rhs) {
    static_assert(detail::is_same<typename LRegBit::reg, typename RRegBit::reg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.bv() | rhs.bv())};
}

template<typename LRegBit, typename Reg>
detail::enable_if_t<
    detail::is_base_of<reg_bit_base, LRegBit>::value,
    reg_value_t<typename LRegBit::reg>>
operator|(const LRegBit& lhs, reg_value_t<Reg> rhs) {
    static_assert(detail::is_same<typename LRegBit::reg, typename reg_value_t<Reg>::reg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.bv() | rhs.value)};
}
template<typename RRegBit, typename Reg>
detail::enable_if_t<
    detail::is_base_of<reg_bit_base, RRegBit>::value,
    reg_value_t<typename RRegBit::reg>>
operator|(reg_value_t<Reg> lhs, const RRegBit& rhs) {
    static_assert(detail::is_same<typename reg_value_t<Reg>::reg, typename RRegBit::reg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.value | rhs.bv())};
}

template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<reg_base, Reg>::value,
    reg_value_t<Reg>>
operator&(const Reg& lhs, uint8_t rhs)
{ return {static_cast<uint8_t>(lhs.addr() & rhs)}; }

template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<reg_base, Reg>::value,
    reg_value_t<Reg>>
operator&(uint8_t lhs, const Reg& rhs)
{ return {static_cast<uint8_t>(lhs & rhs.addr())}; }

template<typename LReg, typename RRegBit>
detail::enable_if_t<
    detail::is_base_of<reg_bit_base, RRegBit>::value
    && detail::is_base_of<reg_base, LReg>::value,
    reg_value_t<typename RRegBit::reg>>
operator&(const LReg& lhs, const RRegBit& rhs){
    static_assert(detail::is_same<LReg, typename RRegBit::reg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.addr() & rhs.bv())};
}

template<typename LRegBit, typename RReg>
detail::enable_if_t<
    detail::is_base_of<reg_bit_base, LRegBit>::value
    && detail::is_base_of<reg_base, RReg>::value,
    reg_value_t<typename LRegBit::reg>>
operator&(const LRegBit& lhs, const RReg& rhs) {
    static_assert(detail::is_same<typename LRegBit::reg, RReg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.bv() & rhs.addr())};
}

template<typename LRegBit, typename RRegBit>
detail::enable_if_t<
    detail::is_base_of<reg_bit_base, LRegBit>::value
    && detail::is_base_of<reg_bit_base, RRegBit>::value,
    reg_value_t<typename LRegBit::reg>>
operator&(const LRegBit& lhs, const RRegBit& rhs) {
    static_assert(detail::is_same<typename LRegBit::reg, typename RRegBit::reg>::value,
                  "Bits related to different registers.");
    return {lhs.bv() & rhs.bv()};
}

template<typename LRegBit, typename Reg>
detail::enable_if_t<
    detail::is_base_of<reg_bit_base, LRegBit>::value,
    reg_value_t<typename LRegBit::reg>>
operator&(const LRegBit& lhs, reg_value_t<Reg> rhs) {
    static_assert(detail::is_same<typename LRegBit::reg, typename reg_value_t<Reg>::reg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.bv() & rhs.value)};
}
template<typename RRegBit, typename Reg>
detail::enable_if_t<
    detail::is_base_of<reg_bit_base, RRegBit>::value,
    reg_value_t<typename RRegBit::reg>>
operator&(reg_value_t<Reg> lhs, const RRegBit& rhs) {
    static_assert(detail::is_same<typename reg_value_t<Reg>::reg, typename RRegBit::reg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.value & rhs.bv())};
}

}}

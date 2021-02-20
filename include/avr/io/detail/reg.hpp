#pragma once

#include "avr/io/detail/type_traits/is_same.hpp"

#include <stdint.h>

namespace avr { namespace io { namespace detail {

template<typename Reg>
inline uint8_t clear_aux(bool) noexcept { return 0xff; }
    
template<typename Reg, typename RegBit, typename... RegBits>
inline uint8_t clear_aux(bool inv, RegBit b, RegBits... regbits) noexcept {
    static_assert(detail::is_same<Reg, typename RegBit::reg>::value,
                  "The bit isn't related to the register.");
    uint8_t mask{0xff};
    if(!inv && !b.state()) mask &= b.bv();
    if(inv && b.state()) mask &= ~b.bv();
    return mask & clear_aux<Reg>(inv, regbits...);
}
        
template<typename Reg>
inline uint8_t set_aux(bool) noexcept { return 0x00; }
    
template<typename Reg, typename RegBit, typename... RegBits>
inline uint8_t set_aux(bool inv, RegBit b, RegBits... regbits) noexcept {
    static_assert(detail::is_same<Reg, typename RegBit::reg>::value,
                  "The bit isn't related to the register.");
    uint8_t mask{0x00};
    if(b.state()) mask |= b.bv();
    return mask | set_aux<Reg>(inv, regbits...);
}
    
template<typename Reg, typename... RegBits>
inline void set(bool inv, RegBits... regbits) noexcept {
    auto clr = detail::clear_aux<Reg>(inv, regbits...);
    auto set_ = detail::set_aux<Reg>(inv, regbits...);
    if(clr != 0xff && set_ != 0x00)
        Reg::addr() = (Reg::addr() & clr) | set_;
    else if(clr == 0xff && set_ != 0x00)
        Reg::addr() = Reg::addr() | set_;
    else if(clr != 0xff && set_ == 0x00)
        Reg::addr() = Reg::addr() & clr;
    else if(clr == 0xff && set_ == 0x00){}
}

#if __cplusplus >= 201703L
template<typename... RegBits>
constexpr uint8_t or_(RegBits... bits) noexcept
{ return (bits.bv() | ...); }
#else
constexpr uint8_t or_() noexcept {
    return 0xFF;
}
        
template<typename RegBit, typename... RegBits>
constexpr uint8_t or_(RegBit b, RegBits... bits) noexcept {
    return or_(b.bv() | or_(bits...));
}
#endif

}}}

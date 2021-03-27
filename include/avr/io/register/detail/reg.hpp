#pragma once

#include "avr/io/register/detail/all_represents_bit_on.hpp"
#include "avr/io/register/detail/all_state_representation_at_compiletime.hpp"
#include "avr/io/detail/type_traits/enable_if.hpp"
#include "avr/io/detail/type_traits/is_base_of.hpp"
#include "avr/io/detail/type_traits/is_same.hpp"

#include <stdint.h>

namespace avr { namespace io { namespace detail {

template<typename Reg>
struct reg_value_t {
    using reg = Reg;
    uint8_t value;
    reg_value_t operator~() const noexcept
    { return {static_cast<uint8_t>(~value)}; }
    operator bool() const noexcept { return value; }
};

struct reg_base {};

template<typename Reg, typename RegBit>
struct bit_belongs_to_reg {
    constexpr static bool value = detail::is_same<typename RegBit::reg, Reg>::value;
};

#if __cplusplus >= 201703L
template<typename... RegBits>
constexpr uint8_t or_(RegBits... bits) noexcept
{ return (bits.bv() | ...); }
#else
constexpr uint8_t or_() noexcept {
    return 0x00;
}
        
template<typename RegBit, typename... RegBits>
constexpr uint8_t or_(RegBit b, RegBits... bits) noexcept {
    return b.bv() | or_(bits...);
}
#endif

template<typename reg>
struct bits_t {
    uint8_t v;
    template<typename Bit>
    bits_t(Bit bit) noexcept : v(or_(bit)) {
        static_assert(all_state_representation_at_compiletime<Bit>::value,
                      "The state represented by each bit must be know at compile-time.");
        static_assert(bit_belongs_to_reg<reg, Bit>::value,
                      "The bit doesn't belongs to the register.");
    }
    template<typename Bit, typename... Bits>
    bits_t(Bit bit, Bits... bits) noexcept : v(or_(bit, bits...)) {
        static_assert(all_represents_bit_on<Bit, Bits...>::value,
                      "Each bit must represent the state 'on'.");
        static_assert(all_state_representation_at_compiletime<Bit, Bits...>::value,
                      "The state represented by each bit must be know at compile-time.");
        static_assert(bit_belongs_to_reg<reg, Bit>::value,
                      "The bit doesn't belongs to the register.");
    }
};

}}}

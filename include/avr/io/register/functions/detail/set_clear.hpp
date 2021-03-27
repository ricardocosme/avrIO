#pragma once

#include "avr/io/detail/macros.hpp"
#include "avr/io/detail/type_traits/enable_if.hpp"
#include "avr/io/register/bit.hpp"
#include "avr/io/register/detail/all_state_representation_at_compiletime.hpp"
#include "avr/io/register/detail/belongs_same_reg.hpp"
#include "avr/io/register/detail/belongs_to_reg.hpp"

#include <stdint.h>

namespace avr { namespace io { namespace detail {

//base case
template<typename Reg>
AVR_IO_ALWAYS_INLINE uint8_t clear_mask(bool) noexcept { return 0xff; }
    
template<typename Reg, typename Bit, typename... Bits>
AVR_IO_ALWAYS_INLINE
uint8_t clear_mask(bool inv, Bit b, Bits... bits) noexcept {
    uint8_t mask{0xff};
    if(!inv && !b.represents_bit_on()) mask &= b.bv();
    if(inv && b.represents_bit_on()) mask &= ~b.bv();
    return mask & clear_mask<Reg>(inv, bits...);
}

//base case
template<typename Reg>
AVR_IO_ALWAYS_INLINE uint8_t set_mask(bool) noexcept { return 0x00; }
    
template<typename Reg, typename Bit, typename... Bits>
AVR_IO_ALWAYS_INLINE
uint8_t set_mask(bool inv, Bit b, Bits... bits) noexcept {
    uint8_t mask{0x00};
    if(!inv && b.represents_bit_on()) mask |= b.bv();
    if(inv && !b.represents_bit_on()) mask |= ~b.bv();
    return mask | set_mask<Reg>(inv, bits...);
}
    
template<typename Reg, typename... Bits>
AVR_IO_ALWAYS_INLINE
void set_using_or_and(bool inv, Bits... bits) noexcept {
    auto clr = clear_mask<Reg>(inv, bits...);
    auto set_ = set_mask<Reg>(inv, bits...);
    if(clr != 0xff && set_ != 0x00)
        Reg::ref() = (Reg::ref() & (clr & ~set_)) | set_;
    else if(clr == 0xff && set_ != 0x00)
        Reg::ref() = Reg::ref() | set_;
    else if(clr != 0xff && set_ == 0x00)
        Reg::ref() = Reg::ref() & clr;
    else if(clr == 0xff && set_ == 0x00){}
}

//When we have three or more bits than we use or/and instructions.
template<typename Reg, typename... Bits>
AVR_IO_ALWAYS_INLINE
void set_compiletime(bool inv, Bits... bits) noexcept
{ set_using_or_and<Reg>(inv, bits...); }

//When we have two bits and the register has an address greater than
//31+0x20 than we use or/and instructions.
template<typename Reg, typename Bit, typename Bit1>
AVR_IO_ALWAYS_INLINE
enable_if_t<!(Bit::reg::addr <= 31+0x20)>
set_compiletime(bool inv, Bit b, Bit1 b1) noexcept
{ set_using_or_and<Reg>(inv, b, b1); }

//When we have two bits and the register has an address less than
//31+0x20 than we ask the compiler optimizer to use sbi/cbi
//instructions.
template<typename Reg, typename Bit, typename Bit1>
AVR_IO_ALWAYS_INLINE
enable_if_t<Bit::reg::addr <= 31+0x20>
set_compiletime(bool inv, Bit b, Bit1 b1) noexcept {
    set_compiletime<Reg>(inv, b);
    set_compiletime<Reg>(inv, b1);
}

//base case
AVR_IO_ALWAYS_INLINE void set_runtime(bool, uint8_t&, uint8_t&) {}

template<typename Bit, typename... Bits>
AVR_IO_ALWAYS_INLINE
void set_runtime(bool inv, uint8_t& clear_mask, uint8_t& mask,
                 Bit b, Bits... bits)
{
    auto bv = (1<<Bit::value);
    if(!inv ? b.represents_bit_on() : !b.represents_bit_on()) mask |= bv;
    clear_mask |= bv;
    set_runtime(inv, clear_mask, mask, bits...);
}

template<typename Reg, typename Bit>
AVR_IO_ALWAYS_INLINE
enable_if_state_representation_at_compiletime<Bit>
set_impl(bool inv, Bit  bit) noexcept
{ set_compiletime<Reg>(inv, bit); }

template<typename Reg, typename Bit>
AVR_IO_ALWAYS_INLINE
enable_if_state_representation_at_runtime<Bit>
set_impl(bool inv, Bit b) noexcept {
    if(b.represents_bit_on())
        set_compiletime<Reg>(inv, bit<Reg, Bit::value, true>{});
    else
        set_compiletime<Reg>(inv, bit<Reg, Bit::value, false>{});
}

//TODO: Handle the case when there are some bits with state defined at
//runtime and other ones defined at compile-time.

//When all bits have a state represented at compile-time.
template<typename Reg, typename Bit, typename Bit2, typename... Bits>
AVR_IO_ALWAYS_INLINE
enable_if_state_representation_at_compiletime<Bit, Bit2, Bits...>
set_impl(bool inv, Bit bit, Bit2 bit2, Bits... bits) noexcept
{ set_compiletime<Reg>(inv, bit, bit2, bits...); }

//When at least one bit has a state represented at runtime.
template<typename Reg, typename Bit, typename Bit2, typename... Bits>
AVR_IO_ALWAYS_INLINE
enable_if_state_representation_at_runtime<Bit, Bit2, Bits...>
set_impl(bool inv, Bit bit, Bit2 bit2, Bits... bits) noexcept {
    uint8_t clear_mask{0x00}, mask;
    asm volatile("ldi %0,0x00" :"=r"(mask)::);
    set_runtime(inv, clear_mask, mask, bit, bit2, bits...);
    Reg::ref() = (Reg::ref() & ~clear_mask) | mask;
}

template<typename Bit, typename... Bits>
AVR_IO_ALWAYS_INLINE
void set(bool inv, Bit bit, Bits... bits) noexcept {
    static_assert(belongs_same_reg<Bit, Bits...>::value,
                  "All bits should belong to the same register.");
    set_impl<typename Bit::reg>(inv, bit, bits...);
}

template<typename LhsReg, typename... Bits>
AVR_IO_ALWAYS_INLINE
void set(bool inv, Bits... bits) noexcept {
    static_assert(belongs_to_reg<LhsReg, Bits...>::value,
                  "All bits should belong to the register that "
                  "is being modified.");
    set_impl<LhsReg>(inv, bits...);
}

template<typename LhsReg, typename RhsReg, typename... Bits>
AVR_IO_ALWAYS_INLINE
void set(bool inv, Bits... bits) noexcept {
    static_assert(belongs_to_reg<RhsReg, Bits...>::value,
                  "All bits should belong to the register that "
                  "is being modified.");
    set_impl<LhsReg>(inv, bits...);
}

}}}

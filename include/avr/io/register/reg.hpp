#pragma once

#include "avr/io/detail/type_traits/enable_if.hpp"
#include "avr/io/detail/type_traits/is_base_of.hpp"
#include "avr/io/detail/type_traits/is_same.hpp"
#include "avr/io/register/bit.hpp"
#include "avr/io/register/bit_state_as_func.hpp"
#include "avr/io/register/detail/reg.hpp"

#include <stdint.h>

namespace avr { namespace io {

/** Represents an IO register 
    
    address: memory address of the register.
 */
template<uint8_t address>
struct reg : detail::reg_base {
    /** Memory address of the register. */
    static constexpr uint8_t addr = address;

    /** Returns a reference to read/write. */
    static volatile uint8_t& ref() noexcept
    { return *reinterpret_cast<volatile uint8_t*>(addr); }

    /** see ref() */
    volatile uint8_t& operator*() const noexcept
    { return ref(); }
    
    /** Define the state of a sequence of bits

        This method defines the state of each bit that is passed as an
        argument. The bit assumes the same state as defined by its
        representation. If the bit is represented by an abstraction
        that represents the state 'on', the state will be 'on', if the
        representation is 'off' then the state will be 'off'. For
        example, the abstraction 'pb3' represents the bit PORTB3 with
        the state 'on', so, 'set(pb3)' turns on the bit PORTB3, but
        the representation 'pb3(off)' turns off the bit.

        Examples:
          reg.set(pb3, pb1(off)) //turns on PORTB3 and turns off PORTB1
          reg.set(pb3(some_bool)) //turns on PORTB3 if 'some_bool' is true 
                                  //and turns off otherwise
    */
    template<typename... Bits> AVR_IO_REQUIRES_CONCEPT_BITS
    [[gnu::always_inline]] static void set(Bits... bits) noexcept
    { detail::set<reg>(false, bits...); }

    /** Define the state of a sequence of bits

        This method defines the state of each bit that is passed as an
        argument. The bit assumes the inversion of the  state as defined by its
        representation. If the bit is represented by an abstraction
        that represents the state 'on', the state will be 'off', if the
        representation is 'off' then the state will be 'on'. For
        example, the abstraction 'pb3' represents the bit PORTB3 with
        the state 'on', so, 'clear(pb3)' turns off the bit PORTB3, but
        the representation 'pb3(off)' turns on the bit.

        Examples:
          reg.clear(pb3, pb1(off)) //turns off PORTB3 and turns on PORTB1
          reg.clear(pb3(some_bool)) //turns off PORTB3 if 'some_bool' is true 
                                    //and turns on otherwise
    */
    template<typename... Bits> AVR_IO_REQUIRES_CONCEPT_BITS
    [[gnu::always_inline]] static void clear(Bits... bits) noexcept
    { detail::set<reg>(true, bits...); }
   
    /** Replaces the content of the register by one byte value.

        Examples: 
          portb = 0b01011111;
          portb = 0x5f;
     */
    const reg& operator=(uint8_t o) const noexcept {
        ref() = o;
        return *this;
    }

    /** Turns on the bits defined in the sequence and turns off all
        the other bits.

        Examples:
          portb = pb3;
          portb = {pb3};
          portb = {pb3, pb1, pb0};

        Each bit used in the sequence must represent the state 'on'
        and the representation must be know at compile-time. This
        means that bits like '~pb3' or 'pb(3)' can't be used. Note
        that all bits that are not defined will be off in the end.

          portb = {pb3, ~pb1, pb0}; //compile error

        Bits that doesn't belong to the register are not allowed, for
        example, the statement below will generate a compile error:
          portb = {pc0, pb1, pb0}; //compile error
     */
    const reg& operator=(const detail::bits_t<reg>& o) const noexcept {
        ref() = o.v;
        return *this;
    }

    /** Replaces the content of the register by a byte value defined
        by a bitwise expression.

        Examples:
          mcucr = se | sm1 | sm0;
          portb = (portb & ~pb3) | pb1 | pb0; [1]

          [1] The method 'set' should be considered in this case in
          order to achieve a more expressive code:
            portb.set(pb3(off), pb1, pb0);
            //or
            portb.set(~pb3, pb1, pb0);
            //or
            set(~pb3, pb1, pb0);

        It isn't allowed the usage of bits that doesn't belong to the
        register in the left side of the expression, for example:
          portb = pa0 | pb1; //compile error
     */
    template<typename Reg>
    const reg& operator=(detail::reg_value_t<Reg> o) const noexcept {
        static_assert(detail::is_same<reg, Reg>::value,
                      "The right side expression is associated "
                      "with other register. Check if the bits that forms "
                      "the expression are related to the register in the "
                      "left side.");
        if(addr < 0x60) ref() = o.value;
        else asm("sts %0, %1" : : "n" (&ref()), "r" (o.value));
        return *this;
    }
    
    const reg& operator|=(uint8_t o) const noexcept {
        ref() = ref() | o;
        return *this;
    }

    const reg& operator|=(const detail::bits_t<reg>& o) const noexcept {
        ref() = ref() | o.v;
        return *this;
    }
        
    template<typename T,
             typename E = detail::enable_if_t<
                 detail::is_same<T, reg>::value>
             >
    const reg& operator|=(const detail::reg_value_t<T>& o) const noexcept {
        ref() = ref() | o.value;
        return *this;
    }
        
    const reg& operator&=(uint8_t o) const noexcept {
        ref() = ref() & o;
        return *this;
    }

    const reg& operator&=(const detail::bits_t<reg>& o) const noexcept {
        ref() = ref() & o.v;
        return *this;
    }
    
    template<typename T,
             typename E = detail::enable_if_t<
                 detail::is_same<T, reg>::value>
             >
    const reg& operator&=(const detail::reg_value_t<T>& o) const noexcept {
        ref() = ref() & o.value;
        return *this;
    }

    const reg& operator^=(uint8_t o) const noexcept {
        ref() = ref() ^ o;
        return *this;
    }

    const reg& operator^=(const detail::bits_t<reg>& o) const noexcept {
        ref() = ref() ^ o.v;
        return *this;
    }
    
    template<typename T,
             typename E = detail::enable_if_t<
                 detail::is_same<T, reg>::value>
             >
    const reg& operator^=(const detail::reg_value_t<T>& o) const noexcept {
        ref() = ref() ^ o.value;
        return *this;
    }

    /** Returns an abstraction that represents the register with all
        the bits inverted. 

        Example:
          portb = ~portb;
    */
    detail::reg_value_t<reg> operator~() const noexcept
    { return {static_cast<uint8_t>(~ref())}; }
    
    operator bool() const noexcept { return !!ref(); }
};

}}

#include "avr/io/register/detail/and.hpp"
#include "avr/io/register/detail/equality.hpp"
#include "avr/io/register/detail/lt_gt.hpp"
#include "avr/io/register/detail/or.hpp"
#include "avr/io/register/detail/xor.hpp"

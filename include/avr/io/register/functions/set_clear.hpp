#pragma once

#if (__cplusplus > 201703L)  //C++20 concepts
#include "avr/io/concepts.hpp"
#endif
#include "avr/io/detail/macros.hpp"
#include "avr/io/register/detail/belongs_same_reg.hpp"
#include "avr/io/register/functions/detail/set_clear.hpp"

namespace avr { namespace io {

/** Define the state of one or more bits.

    Each bit abstraction has a representation to a state 'on' or
    'off', by the default a bit from a register represents the state
    'on' of that bit, for example, the bit 'pb3' represents the bit 3
    from the register PORTB with the state 'on' and the bit '~pb3' or
    'pb3(off)' represents the same bit but with the state 'off'. This
    concept of a representation to a bit state allows the functions
    set and clear define a bit with an explicit state.

    Example:
      set(pb0, pb1, pb3) //pb0, pb1 and pb3 drives high
      set(pb0, pb1(off), pb3) //pb0 and pb3 drives high but pb1 drives low
      set(pb0(is_low(pb3)), pb3) //pb0 drives high if is_low(pb3) is true 
                                 //and pb3 drives high
*/
template<typename... Bits> AVR_IO_REQUIRES_CONCEPT_BITS
AVR_IO_ALWAYS_INLINE 
void set(Bits... bits) noexcept {
    static_assert(sizeof...(Bits) <= 8,
                  "It isn't possible to handle more than 8 bits because "
                  "the register has only 8 bits.");
    static_assert(detail::belongs_same_reg<Bits...>::value,
                  "All bits should belong to the same register.");
    detail::set(false, bits...);
}

/** This is the same as the operation 'set' but with an inverted logic.

    Example:
      clear(pb0, pb1, pb3) //pb0, pb1 and pb3 drives low
      clear(pb0, pb1(off), pb3) //pb0 and pb3 drives low but pb1 drives high
      clear(pb0(is_low(pb3)), pb3) //pb0 drives low if is_low(pb3) is true 
                                   //and pb3 drives low
 */
template<typename... Bits> AVR_IO_REQUIRES_CONCEPT_BITS
AVR_IO_ALWAYS_INLINE
void clear(Bits... bits) noexcept {
    static_assert(sizeof...(Bits) <= 8,
                  "It isn't possible to handle more than 8 bits because "
                  "the register has only 8 bits.");
    static_assert(detail::belongs_same_reg<Bits...>::value,
                  "All bits should belong to the same register.");
    detail::set(true, bits...);
}

}}

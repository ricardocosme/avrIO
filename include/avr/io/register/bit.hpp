#pragma once

#include "avr/io/detail/global.hpp"
#include "avr/io/detail/type_traits/enable_if.hpp"
#include "avr/io/detail/type_traits/is_same.hpp"
#include "avr/io/register/bit_base.hpp"
#include "avr/io/register/bit_state_as_func.hpp"

#include <stdint.h>

namespace avr { namespace io {

/** Tag that represents the bit state 'on'. */
struct on_t {};
AVR_IO_INLINE_GLOBAL(on);

/** Tag that represents the bit state 'off'. */
struct off_t{};
AVR_IO_INLINE_GLOBAL(off);

/** Represents one bit of an IO register.
    
    This abstraction represents one bit with a state 'on' or 'off'
    that has a well defined position inside an IO register. For
    example, the instantiation 'bit<portb_t, 3>' represents the bit
    PORTB3 from the register PORTB with the state 'on', but
    'bit<portb_t, 3, false>' represents the same bit with the state
    'off'. The state that is represented by the abstraction is not the
    actual state of the bit. The actual state of the bit can be
    obtained through the method 'state()' and the state that is
    represented by the abstraction (see 'RepresentsBitOn') is that one
    used by operation like 'set(pb3, pb2(off))' or any other operation
    that needs to know what bit state should be considered.

    Register: register that owns the bit.

    Position: position of the bit inside Register. Zero(0) is the LSB
              and 7 is the MSB.

    RepresentsBitOn: the state of the bit that is represented by the
                     abstraction. This property is useful when the
                     abstraction is used to represent the state of the
                     bit, for example, the statement 'set(pb3)'
                     defines the state 'on' to the bit 'pb3' because
                     the abstraction 'pb3' represents the state 'on',
                     but 'set(pb3(off))' defines the state 'off' because
                     the expression 'pb3(off)' represents the state
                     'off'.
 */
template<typename Register, uint8_t Position, bool RepresentsBitOn = true>
struct bit : bit_base<bit<Register, Position, RepresentsBitOn>, Register, Position>
{
    using base = bit_base<
    bit<Register, Position, RepresentsBitOn>, Register, Position>;
    using base::operator=;
    
    /** Express that the representation of the state is obtained at
        compile-time. */
    constexpr static bool representation_at_runtime{false};
    
    bit() = default;

    /** Returns the byte value

        Byte value is a representation to the bit using 1 byte. If the
        abstraction represents the state 'on' then the byte value is
        '1<<value', otherwise it's the value '~(1<<value)'.
    */
    static constexpr uint8_t bv() noexcept {
        return static_cast<uint8_t>(
            RepresentsBitOn ? 1<<base::value : ~(1<<base::value));
    }

    /** Predicate that indicates if the abstraction represents the
        state 'on'. */
    static constexpr bool represents_bit_on() noexcept
    { return RepresentsBitOn; }

    /** Constructs other bit with the same position inside the same
        register but with a 'on' representation of the state. */
    bit<Register, base::value, true>
    operator()(on_t) const noexcept
    { return {}; }
    
    /** Constructs other bit with the same position inside the same
        register but with a 'off' representation of the state. */
    bit<Register, base::value, false>
    operator()(off_t) const noexcept
    { return {}; }
    
    /** Constructs other bit with the same position inside the same
        register but with a representation of the state defined by the
        function RepresentsBitOn. */
    template<typename RepresentsBitOn_>
    bit_state_as_func<Register, base::value, RepresentsBitOn_>
    operator()(RepresentsBitOn_ f) const noexcept
    { return {f}; }
    
    /** Constructs other bit with the same position inside the same
        register but with the represented state inverted. */
    bit<Register, base::value, !RepresentsBitOn> operator~() const noexcept
    { return {}; }
};

}}

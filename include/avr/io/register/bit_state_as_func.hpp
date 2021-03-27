#pragma once

#include "avr/io/register/bit_base.hpp"

#include <stdint.h>

namespace avr { namespace io {

/** Represents one bit of an IO register.
    
    This abstraction is a representation to one bit with a well
    defined position inside an IO register and a state 'on' or 'off'
    defined by a FunctionObject. 

    Register: register that owns the bit.

    Position: position of the bit inside Register. Zero(0) is the LSB
              and 7 is the MSB.
 */
template<typename Register, uint8_t Position, typename RepresentsBitOn>
class bit_state_as_func
    : public bit_base<bit_state_as_func<Register, Position, RepresentsBitOn>,
                      Register, Position>
{
    RepresentsBitOn _represents_bit_on;
public:
    using base = bit_base<
    bit_state_as_func<Register, Position, RepresentsBitOn>, Register, Position>;
    using base::operator=;
            
    /** Express that the representation of the state is obtained at
        runtime. */
    constexpr static bool representation_at_runtime{true};
    
    bit_state_as_func() = default;
    
    bit_state_as_func(RepresentsBitOn f) : _represents_bit_on(f) {}
    
    /** Returns the byte value

        Byte value is a representation to the bit using 1 byte. If the
        abstraction represents the state 'on' then the byte value is
        '1<<value', otherwise it's the value '~(1<<value)'.
    */
    uint8_t bv() const noexcept
    { return represents_bit_on() ? 1<<base::value : ~(1<<base::value); }
    
    /** Predicate that indicates if the abstraction represents the
        state 'on'. */
    bool represents_bit_on() const noexcept
    { return _represents_bit_on(); }
    
    //FIXME
    /** Constructs other bit with the same position inside the same
        register but with the state inverted. */
    // bit_state_as_func<Register, value, NotInverted> operator~() const noexcept
    // { return {}; }
};

}}

#pragma once

#include "avr/io/register/detail/bit_base.hpp"

#include <stdint.h>

namespace avr { namespace io { 

template<typename Derived, typename Register, uint8_t Position>
struct bit_base : detail::bit_base {
    /** Register that owns the bit. */
    using reg = Register;

    static_assert(Position >= 0 && Position <= 7,
                  "Position should be between [0,7]");
    
    /** Position of the bit inside the register 'reg'. */
    static constexpr uint8_t value{Position};

    /** Define the state of the bit. */
    void state(bool on) const noexcept {
        if(on) reg::ref() |= Derived::bv();
        else reg::ref() &= ~Derived::bv();
    }

    /** see state(on) */
    const Derived& operator=(bool on) const noexcept {
        state(on);
        return static_cast<const Derived&>(*this);
    }
    
    /** Returns the state of the bit.
        
        If 'represents_bit_on() == true' then the value 'true' is
        returned if the bit is 'on', but if 'represents_bit_on() ==
        false' then the value 'true' is returned if the bit is 'off'.
    */
    [[nodiscard]]
    bool state() const noexcept {
        auto v = reg::ref() & Derived::bv();
        return Derived::represents_bit_on() ? v : !v;
    }

};

}}

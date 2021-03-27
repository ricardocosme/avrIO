#pragma once

#include "avr/io/detail/macros.hpp"
#include "avr/io/register/functions/detail/set_clear.hpp"

namespace avr { namespace io { namespace detail {

template<typename Pin, typename... Pins>
AVR_IO_ALWAYS_INLINE void _out(Pin pin, Pins... pins) {
    detail::set<typename Pin::ddrx, typename Pin::portx>(false, pin, pins...);    
}

template<typename Pin, typename... Pins>
AVR_IO_ALWAYS_INLINE void _in(Pin pin, Pins... pins) {
    detail::set<typename Pin::ddrx, typename Pin::portx>(true, pin, pins...);    
}

}}}

#pragma once

#include <avr/io.hpp>
using namespace avr::io;

template<typename... Pin>
[[gnu::always_inline]] inline void ctor_impl(Pin... pins) {
    (..., Pin(output));
    (..., Pin(input));
    (..., Pin(pullup));
}

template<typename Pin>
[[gnu::always_inline]]
inline void _is_high(Pin pin) { if (is_high(pin)) low(pin); }

template<typename Pin>
[[gnu::always_inline]]
inline void _is_low(Pin pin) { if (is_low(pin)) high(pin); }

template<typename... Pin>
[[gnu::always_inline]] inline void functions_impl(Pin... pins) {
    (..., low(pins));
    (..., low(pins, 0));
    (..., high(pins));
    (..., high(pins, 0));
    (..., toggle(pins));
    (..., _is_high(pins));
    (..., _is_low(pins));
}

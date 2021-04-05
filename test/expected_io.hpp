#pragma once

#include <avr/io.h>

[[gnu::always_inline]]
inline void out(volatile uint8_t& ddr, uint8_t pin)
{ ddr |= _BV(pin); }

[[gnu::always_inline]]
inline void in(volatile uint8_t& ddr, uint8_t pin) {
    ddr &= ~_BV(pin);
    *(&ddr + 1) &= ~_BV(pin);
}

[[gnu::always_inline]]
inline void pullup(volatile uint8_t& ddr, uint8_t pin) {
    ddr &= ~_BV(pin);
    *(&ddr + 1) |= _BV(pin);
}

[[gnu::always_inline]]
inline void low(volatile uint8_t& ddr, uint8_t pin, bool v = true) {
    if(v) *(&ddr + 1) &= ~_BV(pin);
    else *(&ddr + 1) |= _BV(pin);
}

// [[gnu::always_inline]]
// inline void low(volatile uint8_t& ddr, uint8_t pin) {
//     // *(&ddr + 1) &= ~_BV(pin);
//     PORTB &= ~_BV(pin);
// }

[[gnu::always_inline]]
inline void high(volatile uint8_t& ddr, uint8_t pin, bool v = true) {
    if(v) *(&ddr + 1) |= _BV(pin);
    else *(&ddr + 1) &= ~_BV(pin);
}

[[gnu::always_inline]]
inline void pulse(volatile uint8_t& ddr, uint8_t pin) {
    high(ddr, pin);
    low(ddr, pin);
}

[[gnu::always_inline]]
inline void toggle(volatile uint8_t& pinx, uint8_t pin)
{ pinx |= _BV(pin); }

[[gnu::always_inline]] inline bool
is_high(volatile uint8_t& pinx, uint8_t pin)
{ return pinx & _BV(pin); }

[[gnu::always_inline]] inline void
test_is_high(volatile uint8_t& ddr, volatile uint8_t& pinx, uint8_t pin)
{ if(is_high(pinx, pin)) low(ddr, pin); }

[[gnu::always_inline]] inline bool
is_low(volatile uint8_t& pinx, uint8_t pin)
{ return !is_high(pinx, pin); }

[[gnu::always_inline]] inline void
test_is_low(volatile uint8_t& ddr, volatile uint8_t& pinx, uint8_t pin)
{ if(is_low(pinx, pin)) high(ddr, pin); }

template<uint8_t... pins>
[[gnu::always_inline]] inline void ctor_impl(volatile uint8_t& ddr) {
    (... , out(ddr, pins));
    (... , in(ddr, pins));
    (... , pullup(ddr, pins));
}

template<uint8_t... pins>
[[gnu::always_inline]] inline void
functions_impl(volatile uint8_t& pinx, volatile uint8_t& ddr) {
    (..., low(ddr, pins));
    (..., low(ddr, pins, 0));
    (..., high(ddr, pins));
    (..., high(ddr, pins, 0));
    (..., toggle(pinx, pins));
    (..., test_is_high(ddr, pinx, pins));
    (..., test_is_low(ddr, pinx, pins));
    (..., pulse(ddr, pins));
}


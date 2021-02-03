#pragma once

#include <stdint.h>

namespace avr { namespace io { namespace traits {

template<typename T>
struct pin {
    uint8_t number(const T& o) const { return T::value; }
    volatile uint8_t* pinx(const T& o) const { return o.pin(); }
    volatile uint8_t* ddrx(const T& o) const { return o.ddr(); }
    volatile uint8_t* portx(const T& o) const { return o.port(); }
};

}}}

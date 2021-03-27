#pragma once

#include "avr/io/detail/macros.hpp"

namespace avr { namespace io { namespace detail {

template<typename Pin>
AVR_IO_ALWAYS_INLINE void _high(Pin pin) {
    auto& portx = Pin::portx::ref();
    portx = portx | (1 << Pin::value);
}

template<typename Pin>
AVR_IO_ALWAYS_INLINE void _low(Pin pin) {
    auto& portx = Pin::portx::ref();
    portx = portx & ~(1 << Pin::value);
}

}}}

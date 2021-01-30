#pragma once

#include <stdint.h>

namespace avr { namespace io { namespace detail {

[[gnu::always_inline]]
inline volatile uint8_t* to_addr(uint8_t i)
{return reinterpret_cast<volatile uint8_t*>(i); }

}}}

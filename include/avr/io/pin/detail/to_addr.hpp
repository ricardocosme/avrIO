#pragma once

#include <stdint.h>

namespace avr { namespace io { namespace detail {

[[gnu::always_inline]]
constexpr inline volatile uint8_t* to_addr(uint16_t i)
{ return reinterpret_cast<volatile uint8_t*>(i); }

}}}

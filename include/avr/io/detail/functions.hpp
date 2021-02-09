#pragma once

#include "avr/io/concepts.hpp"
#include "avr/io/tag.hpp"
#include "avr/io/traits.hpp"

/** Basic functions to operate an I/O port pin that models the concept
    avr::io::Pin. */

namespace avr { namespace io { namespace detail {

#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void high(T pin) noexcept
{ portx(pin) = portx(pin) | (1 << pin_number(pin)); }

#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void low(T pin) noexcept
{ portx(pin) = portx(pin) & ~(1 << pin_number(pin)); }

}}}

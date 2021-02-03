#pragma once

#include "avr/io/traits.hpp"

#if (__cplusplus > 201703L) && __has_include(<concepts>) //C++20
#include <concepts>
#endif

namespace avr { namespace io {

#if (__cplusplus > 201703L)  //C++20
#if __has_include(<concepts>) //using freestanding implementation
template<typename T>
concept Pin =
    requires(T o) {
    { traits::pin<T>{}.number(o) } -> std::convertible_to<uint8_t>;
    { traits::pin<T>{}.pinx(o) } -> std::convertible_to<volatile uint8_t*>;
    { traits::pin<T>{}.ddrx(o) } -> std::convertible_to<volatile uint8_t*>;
    { traits::pin<T>{}.portx(o) } -> std::convertible_to<volatile uint8_t*>;
};
#else
template<typename T>
concept Pin =
    requires(T o) {
    { traits::pin<T>{}.number(o) };
    { traits::pin<T>{}.pinx(o) };
    { traits::pin<T>{}.ddrx(o) };
    { traits::pin<T>{}.portx(o) };
};
#endif
#endif

}}

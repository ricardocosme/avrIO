#pragma once

#include "avr/io/detail/to_addr.hpp"

#include <stdint.h>
#if (__cplusplus > 201703L) && __has_include(<concepts>) //C++20
#include <concepts>
#endif

namespace avr { namespace io {

//Tag to represent the activation of the pull-up resistor of a pin.
struct pullup_t{};
#if (__cplusplus >= 201703L) //C++17/20
constexpr inline pullup_t pullup;
#else
namespace {
constexpr auto& pullup{detail::global<pullup_t>::instance};
} //anonymous namespace    
#endif

// Represents a PORTxn (Pxn)
template<
    uint8_t pin_addr,
    uint8_t ddr_addr,
    uint8_t port_addr,
    uint8_t pin_num>
struct pxn_impl {
    static const uint8_t value{pin_num};

    //Returns a reference to the Port Input Pins (PINx)
    static volatile uint8_t* pin() noexcept
    { return detail::to_addr(pin_addr); }
    
    //Returns a reference to the Data Direction Register (DDRx)
    static volatile uint8_t* ddr() noexcept
    { return detail::to_addr(ddr_addr); }
    
    //Returns a reference to the Data Register PORTx
    static volatile uint8_t* port() noexcept
    { return detail::to_addr(port_addr); }
};

template<uint8_t pin_addr, uint8_t pin_num>
using pxn = pxn_impl<pin_addr, pin_addr + 1, pin_addr + 2, pin_num>;

namespace traits {

template<typename T>
struct pin {
    uint8_t number(const T& o) const { return T::value; }
    volatile uint8_t* pinx(const T& o) const { return o.pin(); }
    volatile uint8_t* ddrx(const T& o) const { return o.ddr(); }
    volatile uint8_t* portx(const T& o) const { return o.port(); }
};

} //namespace traits

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

#pragma once

#include "avr/io/traits.hpp"

#if (__cplusplus > 201703L) && __has_include(<concepts>) //C++20
#include <concepts>
#endif

namespace avr { namespace io {

#if (__cplusplus > 201703L)  //C++20

// The number that identifies the pin
//
// It's the number `n` in the form Pxn.
// The number must satisfies: n >= 0 && n <= 7.
//
template<typename Pin>
consteval auto pin_number(Pin o)
{ return traits::pin<Pin>{}.number(o); }

// The PINx address related to the pin
template<typename Pin>
consteval auto pin_PINx(Pin o)
{ return traits::pin<Pin>{}.pinx(o); }

// The DDRx address related to the pin
template<typename Pin>
consteval auto pin_DDRx(Pin o)
{ return traits::pin<Pin>{}.ddrx(o); }

// The PORTx address related to the pin
template<typename Pin>
consteval auto pin_PORTx(Pin o)
{ return traits::pin<Pin>{}.portx(o); }

// Concept to a single pin of an I/O port
//
// One single pin has:
//  1. An unsigned integer `n` related to the form Pxn. The number
//     must satisfies: n >= 0 && n <= 7.
//  2. An 8bit memory address to the register PINx.
//  3. An 8bit memory address to the register DDRx.
//  4. An 8bit memory address to the register PORTx.
//
#if __has_include(<concepts>) //using libstdc++ freestanding implementation
template<typename T>
concept Pin =
    requires(T o) {
    //the result `n` should satisfies: n >= 0 && n <=7
    { pin_number(o) } -> std::convertible_to<uint8_t>;
    
    { pin_PINx(o) } -> std::convertible_to<volatile uint8_t*>;
    { pin_DDRx(o) } -> std::convertible_to<volatile uint8_t*>;
    { pin_PORTx(o) } -> std::convertible_to<volatile uint8_t*>;
};
#else
template<typename T>
concept Pin =
    requires(T o) {
    //the result `n` should satisfies: n >= 0 && n <=7
    pin_number(o);
    
    pin_PINx(o);
    pin_DDRx(o);
    pin_PORTx(o);
};
#endif
#endif

}}

#pragma once

#include "avr/io/concepts.hpp"
#include "avr/io/tag.hpp"
#include "avr/io/traits.hpp"

/** Basic functions to operate an I/O port pin that models the concept
    avr::io::Pin. */

namespace avr { namespace io {

/** Returns the bit number of the pin.

    The number `n` in the general form `Pxn`.
*/
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline uint8_t pin_number(T pin) noexcept
{ return traits::pin<T>{}.number(pin); }

/** Returns the PORTx memory address. */
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline volatile uint8_t& portx(T pin) noexcept
{ return *traits::pin<T>{}.portx(pin); }

/** Returns the DDRx memory address. */
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline volatile uint8_t& ddrx(T pin) noexcept
{ return *traits::pin<T>{}.ddrx(pin); }

/** Returns the PINx memory address. */
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline volatile uint8_t& pinx(T pin) noexcept
{ return *traits::pin<T>{}.pinx(pin); }

}}//namespace avr::io

#include "avr/io/detail/functions.hpp"

namespace avr { namespace io {

/** If the pin is configured as an output pin then it drives low(zero)
    if 'v' is true or it drives high(one) if 'v' is false, otherwise
    the internal pull-up resistor is disabled if 'v' is true or
    enabled if 'v' is false.
*/
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void low(T pin, bool v = true) noexcept {
    if(v) detail::low(pin);
    else detail::high(pin);
}

/** If the pin is configured as an output pin then it drives high(one)
    if 'v' is true or it drives low(zero) if 'v' is false, otherwise
    the internal pull-up resistor is enabled if 'v' is true or
    disabled if 'v' is false.
*/
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void high(T pin, bool v = true) noexcept {
    if(v) detail::high(pin);
    else low(pin);
}

/** Toggles the pin value. */
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void toggle(T pin) noexcept
{ pinx(pin) = pinx(pin) | (1 << pin_number(pin)); }

/** Configures the pin as an output pin. */
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void out(T pin) noexcept
{ ddrx(pin) = ddrx(pin) | (1 << pin_number(pin)); }

/** Configures the pin as an input pin. */
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void in(T pin) noexcept
{ ddrx(pin) = ddrx(pin) & ~(1 << pin_number(pin)); }

/** Configures the pin as an input pin and activates the pull-up resistor. */
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void in(T pin, pullup_t) noexcept {
    in(pin);
    high(pin, true);
}

/** Returns true if the pin state is high(=1). */
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline, nodiscard]]
inline bool is_high(T pin) noexcept {
    return pinx(pin) & (1 << pin_number(pin));
}

/** Returns true if the pin state is low(=0). */
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline, nodiscard]]
inline bool is_low(T pin) noexcept
{ return !is_high(pin); }

}}

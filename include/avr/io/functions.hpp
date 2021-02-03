#pragma once

// Basic functions to operate an I/O pin that models the concept
// avr::io::Pin.

namespace avr { namespace io {

#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
inline void high(T pin) noexcept {
   auto& portr = *traits::pin<T>{}.portx(pin);
   portr = portr | (1 << traits::pin<T>{}.number(pin));
 }

//If the pin is configured as an output pin then it drives low(zero)
//if 'v' is true or it drives high(one) if 'v' is false, otherwise the
//internal pull-up resistor is disabled if 'v' is true or enabled if
//'v' is false.
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void low(T pin, bool v = true) noexcept {
    auto& portr = *traits::pin<T>{}.portx(pin);
    if(v) portr = portr & ~(1 << traits::pin<T>{}.number(pin));
    else high(pin);
}

//If the pin is configured as an output pin then it drives high(one)
//if 'v' is true or it drives low(zero) if 'v' is false, otherwise the
//internal pull-up resistor is enabled if 'v' is true or disabled if
//'v' is false.
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void high(T pin, bool v) noexcept {
    if(v) high(pin);
    else low(pin);
}

//Toggles the pin value
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void toggle(T pin) noexcept {
    auto& pinr = *traits::pin<T>{}.pinx(pin);
    pinr = pinr | (1 << traits::pin<T>{}.number(pin));
}

//Configures the pin as an output pin
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void out(T pin) noexcept {
    auto& ddrr = *traits::pin<T>{}.ddrx(pin);
    ddrr = ddrr | (1 << traits::pin<T>{}.number(pin));
}

//Configures the pin as an input pin
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void in(T pin) noexcept {
    auto& ddrr = *traits::pin<T>{}.ddrx(pin);
    ddrr = ddrr & ~(1 << traits::pin<T>{}.number(pin));
}

//Configures the pin as an input pin and activates the pull-up
//resistor
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline void in(T pin, pullup_t) noexcept {
    in(pin);
    high(pin);
}

//Returns true if the pin state is high(=1)
#if (__cplusplus > 201703L) //C++20
template<Pin T>
#else
template<typename T>
#endif
[[gnu::always_inline]]
inline bool is_high(T pin) noexcept {
    return *traits::pin<T>{}.pinx(pin) & (1 << traits::pin<T>{}.number(pin));
}

}}

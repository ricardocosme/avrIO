#pragma once

#if (__cplusplus > 201703L)  //C++20 concepts
#include "avr/io/concepts.hpp"
#endif
#include "avr/io/detail/macros.hpp"
#include "avr/io/detail/type_list.hpp"
#include "avr/io/register/detail/belongs_same_reg.hpp"
#include "avr/io/pin/detail/in_out.hpp"
#include "avr/io/pin/detail/low_high.hpp"
#include "avr/io/pin/modes.hpp"
#include "avr/io/register/detail/reg.hpp"
#include "avr/io/register/functions/set_clear.hpp"

/** Basic functions to operate an I/O port pin that models the concept
    avr::io::Pin. */

namespace avr { namespace io {

/** If the pin is configured as an output pin then it drives low if
    'v' is true and it drives high otherwise. If the pin is configured
    as an input pin then the internal pull-up resistor is disabled if
    'v' is true or enabled if 'v' is false.

    Examples: 
      //pb3 configured as an output pin
      low(pb3) //pin pb3 drives low
      low(pb3, v) //pin pb3 drives low if v is true and high if v is false

      //pb2 configured as an input pin
      low(pb2) //disable the pull-up resistor
      low(pb2, v) //disable the pull-up resistor if v is true and 
                  //enable it if v is false
*/
template<typename T> AVR_IO_REQUIRES_CONCEPT_PIN
AVR_IO_ALWAYS_INLINE
void low(T pin, bool v = true) noexcept
{ v ? detail::_low(pin) : detail::_high(pin); }

/** If the pin is configured as an output pin then it drives high
    if 'v' and it drives low otherwise. If the pin is configured
    as an input pin then the internal pull-up resistor is enabled if
    'v' is true or disabled if 'v' is false.

    Examples: 
      //pb3 configured as an output pin
      high(pb3) //pin pb3 drives high
      high(pb3, v) //pin pb3 drives high if v is true and low if v is false

      //pb2 configured as an input pin
      high(pb2) //enables the pull-up resistor
      high(pb2, v) //enables the pull-up resistor if v is true and 
                   //disable it if v is false
*/
template<typename T> AVR_IO_REQUIRES_CONCEPT_PIN
AVR_IO_ALWAYS_INLINE
void high(T pin, bool v = true) noexcept
{ v ? detail::_high(pin) : low(pin); }

/** Positive pulse */
template<typename T> AVR_IO_REQUIRES_CONCEPT_PIN
void pulse(T pin) noexcept {
    pin.high();
    pin.low();
}

/** Toggles the state of one or more pins.

    Examples:
      //if pb0 drives low
      toggle(pb0) //drives high

      //if pb0 drives low, pb1 drives high and pb3 drives low
      toggle(pb0, pb1, pb3) //pb0 drives high, pb1 drives low and pb3 drives high
*/
template<typename Pin, typename... Pins> AVR_IO_REQUIRES_CONCEPT_PINS
AVR_IO_ALWAYS_INLINE
void toggle(Pin pin, Pins... pins) noexcept
{ detail::set<typename Pin::pinx, typename Pin::portx>(false, pin, pins...); }

/** Configures one or more pins as output pins. 

    Example:
      out(pb0) //setup pb0 as an output pin
      out(pb0, pb1, pb2) //setup pb0, pb1 and pb2 as output pins

    [optional@C++17] Structure binding can be used to give names to
    the pins using a concise syntax with one single line, for example: 
      auto [ledA, ledB] = out(pb0, pb2);
*/
template<typename... Pins> AVR_IO_REQUIRES_CONCEPT_PINS
AVR_IO_ALWAYS_INLINE
detail::tup<Pins...> out(Pins... pins) noexcept
{
    static_assert(sizeof...(Pins) <= 8,
                  "It isn't possible to handle more than 8 pins because "
                  "the register has only 8 bits.");
    static_assert(detail::belongs_same_reg<Pins...>::value,
                  "All pins should belong to the same port.");
    detail::_out(pins...);
    return {};
}
        
/** Configures one or more pins as input pins. 

    Example:
      in(pb0) //setup pb0 as an input pin without pull-up resistor enabled
      in(pb0, pb1, pb2) //setup pb0, pb1 and pb2 as input pin

    [optional@C++17] Structure binding can be used to give names to
    the pins using a concise syntax with one single line, for example: 
      auto [switchA, switchB] = in(pb0, pb2);
*/
template<typename... Pins>
AVR_IO_ALWAYS_INLINE
detail::tup<Pins...> in(Pins... pins) noexcept {
    static_assert(sizeof...(Pins)  <= 8,
                  "It isn't possible to handle more than 8 pins because "
                  "the register has only 8 bits.");
    static_assert(detail::belongs_same_reg<Pins...>::value,
                  "All pins should belong to the same port.");
    detail::_in(pins...);
    return {};
}

/** Configures the pin as an input pin and activates the pull-up
    resistor. 

    Example:
      in(pullup, pb0) //setup pb0 as an input pin with pull-up resistor enabled
      in(pullup, pb0, pb1, pb2) //setup pb0, pb1 and pb2 as input pin

    [optional@C++17] Structure binding can be used to give names to
    the pins using a concise syntax with one single line, for example: 
      auto [switchA, switchB] = in(pullup, pb0, pb2);
*/
template<typename... Pins> AVR_IO_REQUIRES_CONCEPT_PINS
AVR_IO_ALWAYS_INLINE
detail::tup<Pins...> in(pullup_t, Pins... pins) noexcept
{
    static_assert(sizeof...(Pins) <= 8,
                  "It isn't possible to handle more than 8 pins because "
                  "the register has only 8 bits.");
    in(pins...);
    set(pins...);
    return {};
}

/** Returns true if the pin state is high. */
template<typename T> AVR_IO_REQUIRES_CONCEPT_PIN
AVR_IO_ALWAYS_INLINE
bool is_high(T pin) noexcept 
{ return T::pinx::ref() & (1 << T::value); }

/** Returns true if the pin state is low. */
template<typename T> AVR_IO_REQUIRES_CONCEPT_PIN
AVR_IO_ALWAYS_INLINE
bool is_low(T pin) noexcept
{ return !is_high(pin); }

namespace lazy {

template<typename Pin>
struct is_low_func
{ bool operator()() const { return Pin::is_low(); } };

template<typename T> AVR_IO_REQUIRES_CONCEPT_PIN
AVR_IO_ALWAYS_INLINE
is_low_func<T> is_low(T pin) noexcept
{ return {}; }

template<typename Pin>
struct is_high_func
{ bool operator()() const { return Pin::is_high(); } };

template<typename T> AVR_IO_REQUIRES_CONCEPT_PIN
AVR_IO_ALWAYS_INLINE
is_high_func<T> is_high(T pin) noexcept
{ return {}; }

}//namespace lazy

}}

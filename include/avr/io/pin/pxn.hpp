#pragma once

#include "avr/io/detail/macros.hpp"
#include "avr/io/pin/detail/to_addr.hpp"
#include "avr/io/pin/functions.hpp"
#include "avr/io/pin/modes.hpp"
#include "avr/io/register/bit.hpp"

#include <stdint.h>

namespace avr { namespace io {

/**  Represents a read/write IO port pin(PORTxn or Pxn). 
     
This is a model to the concept `avr::io::Pin` (see `avr/io/concepts.hpp').

If the port pin doesn't need initialization to configure the mode of
operation(input, pullup or output), then global objects can be used as
a shorthand notation, for example, instead of `avr::io::Pb0 pb0{}`,
the global `avr::io::pb0` can be used.

PORTX: the register PORTX that owns the pin.
PINX: the register PINX related to the pin.
DDRX: the register DDRX related to the pin.
pin_num: the number of the pin 'n' in the general form 'Pxn'. This is
         also means the position of the bit 'PORTXN' or 'PXN' inside
         the register PORTX.
*/
template<
    typename PORTX,
    typename PINX,
    typename DDRX,
    uint8_t pin_num>
struct pxn : bit<PORTX, pin_num>
             /** pxn is also a bit PXN(or PORTXN) from the register PORTX. */
{
    using base = bit<PORTX, pin_num>;
    
    using portx = PORTX;
    using pinx = PINX;
    using ddrx = DDRX;
    
    pxn() = default;

    /** Initializes the pin with the input mode and with the
        pull-up resistor deactivated. */
    AVR_IO_ALWAYS_INLINE
    explicit pxn(input_t) noexcept {
        in();
        low();
    }

    /** Initializes the pin with the input mode and with the pull-up
        resistor activated. */
    AVR_IO_ALWAYS_INLINE
    explicit pxn(pullup_t) noexcept
    { in(pullup); }

    /** Initializes the pin with the output mode. */
    AVR_IO_ALWAYS_INLINE
    explicit pxn(output_t) noexcept
    { out(); }

    /** Returns a reference to the Port Input Pins (PINx). */
    static volatile uint8_t& pin() noexcept
    { return *detail::to_addr(pinx::addr); }
    
    /** Returns a reference to the Data Direction Register (DDRx). */
    static volatile uint8_t& ddr() noexcept
    { return *detail::to_addr(ddrx::addr); }
    
    /** Returns a reference to the Data Register PORTx. */
    static volatile uint8_t& port() noexcept
    { return *detail::to_addr(portx::addr); }

    /** see avr/io/pin/functions.hpp */
    AVR_IO_ALWAYS_INLINE
    static void low(bool v = true) noexcept
    { avr::io::low(pxn{}, v); }

    /** see avr/io/pin/functions.hpp */
    AVR_IO_ALWAYS_INLINE
    static void high(bool v = true) noexcept
    { avr::io::high(pxn{}, v); }
    
    /** see avr/io/pin/functions.hpp */
    static void pulse() noexcept
    { return avr::io::pulse(pxn{}); }
    
    /** see avr/io/pin/functions.hpp */
    AVR_IO_ALWAYS_INLINE
    static void toggle() noexcept
    { avr::io::toggle(pxn{}); }

    /** see avr/io/pin/functions.hpp */
    AVR_IO_ALWAYS_INLINE
    static void out() noexcept
    { avr::io::out(pxn{}); }

    /** see avr/io/pin/functions.hpp */
    AVR_IO_ALWAYS_INLINE
    static void in() noexcept
    { avr::io::in(pxn{}); }

    /** see avr/io/pin/functions.hpp */
    AVR_IO_ALWAYS_INLINE
    static void in(pullup_t) noexcept
    { avr::io::in(pullup, pxn{}); }

    /** see avr/io/pin/functions.hpp */
    [[gnu::always_inline, nodiscard]]
    static bool is_high() noexcept
    { return avr::io::is_high(pxn{}); }

    /** see avr/io/pin/functions.hpp */
    [[gnu::always_inline, nodiscard]]
    static bool is_low() noexcept
    { return !is_high(); }
};

}}

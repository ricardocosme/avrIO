#pragma once

#include "avr/io/detail/to_addr.hpp"

#include <stdint.h>

namespace avr { namespace io {

// Represents a PORTxn (Pxn)
template<
    uint8_t pin_addr,
    uint8_t ddr_addr,
    uint8_t port_addr,
    uint8_t pin_num>
struct pxn_impl {
    static const uint8_t value{pin_num};

    //Returns a reference to the Port Input Pins (PINx)
    static volatile uint8_t& pin() noexcept
    { return *detail::to_addr(pin_addr); }
    
    //Returns a reference to the Data Direction Register (DDRx)
    static volatile uint8_t& ddr() noexcept
    { return *detail::to_addr(ddr_addr); }
    
    //Returns a reference to the Data Register PORTx
    static volatile uint8_t& port() noexcept
    { return *detail::to_addr(port_addr); }
    
    //If the pin is configured as an output pin then it drives
    //low(zero), otherwise the internal pull-up resistor is disabled.
    [[gnu::always_inline]]
    static void low() noexcept
    { port() = port() & ~(1 << value); }

    //If the pin is configured as an output pin then it drives
    //high(one), otherwise the internal pull-up resistor is activated.
    [[gnu::always_inline]]
    static void high() noexcept
    { port() = port() | (1 << value); }

    //Toggles the pin value
    [[gnu::always_inline]]
    static void toggle() noexcept
    { pin() = pin() | (1 << value); }

    //Configures the pin as an output pin
    [[gnu::always_inline]]
    static void out() noexcept
    { ddr() = ddr() | (1 << value); }

    //Configures the pin as an input pin
    [[gnu::always_inline]]
    static void in() noexcept
    { ddr() = ddr() & ~(1 << value); }

    //Returns true if the pin state is high(=1)
    [[nodiscard]]
    [[gnu::always_inline]]
    static bool is_high() noexcept
    { return pin() & (1 << value); }
};

template<uint8_t pin_addr, uint8_t pin_num>
using pxn = pxn_impl<pin_addr, pin_addr + 1, pin_addr + 2, pin_num>;

}}

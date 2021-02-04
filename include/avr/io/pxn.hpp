#pragma once

#include "avr/io/detail/macros.hpp"
#include "avr/io/detail/to_addr.hpp"
#include "avr/io/functions.hpp"
#include "avr/io/tag.hpp"

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

    pxn_impl() = default;

    //Initializes the pin with the input mode and without the pull-up
    //resistor deactivated.
    AVR_IO_CONSTEXPR_CTOR
    explicit pxn_impl(input_t m) noexcept {
        in();
        low();
    }

    //Initializes the pin with the input mode and with the pull-up
    //resistor activated, i.e. the pullup mode.
    AVR_IO_CONSTEXPR_CTOR
    explicit pxn_impl(pullup_t m) noexcept
    { in(pullup); }

    //Initializes the pin with the output mode.
    AVR_IO_CONSTEXPR_CTOR
    explicit pxn_impl(output_t m) noexcept {
        low();
        out();
    }
    
    //Returns a reference to the Port Input Pins (PINx)
    static volatile uint8_t* pin() noexcept
    { return detail::to_addr(pin_addr); }
    
    //Returns a reference to the Data Direction Register (DDRx)
    static volatile uint8_t* ddr() noexcept
    { return detail::to_addr(ddr_addr); }
    
    //Returns a reference to the Data Register PORTx
    static volatile uint8_t* port() noexcept
    { return detail::to_addr(port_addr); }

    //see avr/io/functions.hpp
    static void low(bool v = true) noexcept
    { avr::io::low(pxn_impl{}, v); }

    //see avr/io/functions.hpp
    static void high(bool v = true) noexcept
    { avr::io::high(pxn_impl{}, v); }
    
    //see avr/io/functions.hpp
    static void toggle() noexcept
    { avr::io::toggle(pxn_impl{}); }

    //see avr/io/functions.hpp
    static void out() noexcept
    { avr::io::out(pxn_impl{}); }

    //see avr/io/functions.hpp
    static void in() noexcept
    { avr::io::in(pxn_impl{}); }

    //see avr/io/functions.hpp
    static void in(pullup_t) noexcept
    { avr::io::in(pxn_impl{}, pullup); }

    //see avr/io/functions.hpp
    static bool is_high() noexcept
    { return avr::io::is_high(pxn_impl{}); }

    static bool is_low() noexcept
    { return !is_high(); }
    
    operator bool() noexcept
    { return is_high(); }
};

template<uint8_t pin_addr, uint8_t pin_num>
using pxn = pxn_impl<pin_addr, pin_addr + 1, pin_addr + 2, pin_num>;

}}

#pragma once

#include "avr/io/detail/to_addr.hpp"
#include "avr/io/functions.hpp"

#include <stdint.h>

namespace avr { namespace io {

enum class mode {
    input,
    pullup, //input with pullup resistor enabled
    output,
};

// Represents a PORTxn (Pxn)
template<
    uint8_t pin_addr,
    uint8_t ddr_addr,
    uint8_t port_addr,
    uint8_t pin_num>
struct pxn_impl {
    static const uint8_t value{pin_num};

    pxn_impl() = default;

#if (__cplusplus >= 201703L)
    constexpr
#endif
    explicit pxn_impl(mode m) noexcept {
        if(m == mode::input)
            in(*this);
        else if(m == mode::pullup) {
            in(*this);
            high(*this);
        } else if(m == mode::output)
            out(*this);
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
};

template<uint8_t pin_addr, uint8_t pin_num>
using pxn = pxn_impl<pin_addr, pin_addr + 1, pin_addr + 2, pin_num>;

}}

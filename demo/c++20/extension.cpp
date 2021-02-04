#include <avr/io.hpp>

#if !(defined(__AVR_ATtiny85__) || defined(__AVR_ATtiny13A__))
#error "This demo is only supported to ATtiny85/13A"
#endif

// This demo shows a hypothetical extension to model the ATtiny85 port
// I/O pins using the numbers of the pins in PDIP package. There isn't
// any intention here to claim that this particular usage is a good
// ideia, the only purpose here is to show how flexible is the
// extension mechanism using a fundamental type as 'int' as a
// representation to a pin.
//
// We want to map the following:
// 1 -> PB5
// 2 -> PB3
// 3 -> PB4
// 5 -> PB0
// 6 -> PB1
// 7 -> PB2
//
namespace avr::io::traits{
template<>
struct pin<int> {
    static const uint8_t pin_addr{0x16 + 0x20};
    
    //precondition: (n >= 1 && n <= 3) || (n >= 5 && n <= 7)
    [[gnu::always_inline]]
    uint8_t number(uint8_t n) const {
        if (n >= 5 && n <= 7) return n - 5;
        else if (n >= 2 && n <= 3) return n + 1;
        return 5;
    }
    [[gnu::always_inline]]
    volatile uint8_t* pinx(int o) const
    { return reinterpret_cast<volatile uint8_t*>(pin_addr); }
    [[gnu::always_inline]]
    volatile uint8_t* ddrx(int o) const
    { return pinx(o) + 1; }
    [[gnu::always_inline]]
    volatile uint8_t* portx(int o) const
    { return pinx(o) + 2; }
};
}

using namespace avr::io;

namespace dev {
template<avr::io::Pin Pin>
struct led {
    Pin pin;
    led(Pin ppin) : pin(ppin) { out(pin); };
    void on(bool v = true) { high(pin, v); }
};
} //namespace dev

int main() {
    dev::led led{5};
    in(2, pullup);

    while(true) led.on(is_low(2));
}

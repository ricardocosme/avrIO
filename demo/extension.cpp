#include <stdint.h>

#include <avr/io/io.hpp>

#if !defined(__AVR_ATtiny85__)
#error "This demo is only supported to ATtiny85"
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
    uint8_t number(uint8_t n) const {
        if (n >= 5 && n <= 7) return n - 5;
        else if (n >= 2 && n <= 3) return n + 1;
        return 5;
    }
    volatile uint8_t* pinx(int o) const
    { return reinterpret_cast<volatile uint8_t*>(pin_addr); }
    volatile uint8_t* ddrx(int o) const
    { return reinterpret_cast<volatile uint8_t*>(pin_addr + 1); }
    volatile uint8_t* portx(int o) const
    { return reinterpret_cast<volatile uint8_t*>(pin_addr + 2); }
};
}

template<typename Pin>
void pulse(Pin pin) {
    using namespace avr::io;
    high(pin);
    low(pin);
}

int main() {
    pulse(7); // positive pulse at PB2
}

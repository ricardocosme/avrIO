#include <avr/io/io.hpp>

namespace dev {
template<typename Pin>
struct led {
    const Pin pin;
    led(Pin ppin) : pin(ppin) { avr::io::out(pin); };
    void on(bool v = true) { avr::io::high(pin, v); }
};
} //namespace dev

using namespace avr::io;

int main() {
    dev::led<Pb0> led{pb0};
    Pb3 sw{pullup};
    
    while(true) led.on(sw.is_low());
}

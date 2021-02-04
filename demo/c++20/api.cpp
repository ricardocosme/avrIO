#include <avr/io/io.hpp>

namespace dev {
template<avr::io::Pin Pin>
struct led {
    const Pin pin;
    led(Pin ppin) : pin(ppin) { avr::io::out(pin); };
    void on(bool v = true) { avr::io::high(pin, v); }
};
} //namespace dev

using namespace avr::io;

int main() {
    dev::led led{pb0};
    Pb3 push_btn{mode::pullup};
    
    while(true)
        led.on(!push_btn.is_high());
}

#include <avr/io.hpp>

using namespace avr::io;

namespace dev {
template<avr::io::Pin Pin>
struct led {
    const Pin pin;
    led(Pin ppin) : pin(ppin) { out(pin); };
    void on(bool v = true) { high(pin, v); }
};
} //namespace dev

int main() {
    dev::led led{pb0};
    Pb3 sw{pullup};
    
    while(true) led.on(sw.is_low());
}

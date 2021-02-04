#include <avr/io/io.hpp>

using namespace avr::io;

namespace dev {
template<typename Pin>
struct led {
    const Pin pin;
    led(Pin ppin) : pin(ppin) { out(pin); };
    void on(bool v = true) { high(pin, v); }
};
} //namespace dev

int main() {
    dev::led led{pb0};
    Pb3 push_btn{mode::pullup};
    
    while(true)
        led.on(!push_btn.is_high());
}

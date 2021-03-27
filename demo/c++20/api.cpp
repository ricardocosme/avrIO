#include <avr/io.hpp>

using namespace avr::io;

template<avr::io::Pin Pin>
struct led_t {
    Pin pin;
    led_t(Pin ppin) : pin(ppin) { pin.out(); };
    void on(bool v = true) { pin.high(v); }
};

int main() {
    led_t led{pb0};
    Pb3 sw{pullup};
    
    while(true) led.on(sw.is_low());
}

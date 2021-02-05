#include <avr/io.hpp>

using namespace avr::io;

template<typename Pin>
struct led_t {
    Pin pin;
    led_t(Pin ppin) : pin(ppin) { out(pin); };
    void on(bool v = true) { high(pin, v); }
};

int main() {
    led_t<Pb0> led{pb0};
    Pb3 sw{pullup};
    
    while(true) led.on(sw.is_low());
}

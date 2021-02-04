#include <avr/io/io.hpp>

using namespace avr::io;

int main() {
    Pb0 led{mode::output};
    Pb3 push_btn{mode::pullup};
    
    while(true)
        led.high(!push_btn.is_high());
}

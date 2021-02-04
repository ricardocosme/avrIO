#include <avr/io.hpp>

using namespace avr::io;

int main() {
    Pb0 led{output};
    Pb3 sw{pullup};

    while(true) led.high(sw.is_low());
}

#include <avr/io/io.hpp>

using namespace avr::io;

int main() {
    out(pb0); //pb0 configured as an output pin
    high(pb0); //pb0 drives high(one)
    on(pb0, is_high(pb4)); //pb0 drives high(one) if pb4 is high or
                           //low(zero) otherwise
    low(pb0); //pb0 drives low(zero)
    toggle(pb0); //toggles the pb0 state
   
    in(pb0); //pb0 configured as an input pin
    high(pb0); //activates the pull-up resistor from the pb0
    low(pb0); //deactivates the pull-up resistor from the pb0

    in(pb0, pullup); //pb0 configured as in input pin with the pull-up
                     //resistor activated
  
    //checks if pb0's state is high(one)
    auto v = is_high(pb0);
}

#include <avr/io.hpp>

using namespace avr::io;

int main(){
    Pb2 swA; Pb1 swB;
    in(pullup, swA, swB);
    
    Pb0 ledA; Pb4 ledB;
    out(ledA, ledB);
    
    while(true)
        set(ledA(lazy::is_low(swA)), ledB(lazy::is_low(swB)));
}

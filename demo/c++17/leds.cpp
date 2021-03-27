#include <avr/io.hpp>

using namespace avr::io;

int main(){
    auto [swA, swB] = in(pullup, pb2, pb1);
    auto [ledA, ledB] = out(pb0, pb4);
    
    while(true)
        set(ledA(lazy::is_low(swA)), ledB(lazy::is_low(swB)));
}

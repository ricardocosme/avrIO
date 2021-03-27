#include "../io.hpp"

void ctor() { ctor_impl(pb0, pb1, pb2, pb3, pb4, pb5); }

void functions() {
    functions_impl(pb0, pb1, pb2, pb3, pb4, pb5);
    
    out(pb0, pb1);
    out(pb0, pb1, pb3);
    out(pb0, pb1, pb2, pb3, pb4, pb5);

    in(pb0, pb1);
    in(pb0, pb1, pb3);
    in(pb0, pb1, pb2, pb3, pb4, pb5);
    
    in(pullup, pb0, pb1);
    in(pullup, pb0, pb1, pb3);
    in(pullup, pb0, pb1, pb2, pb3, pb4, pb5);

    set(pb0, pb1);
    set(pb0, pb1, pb3);
    set(pb0, pb1, pb2, pb3, pb4, pb5);

    set(pb0(lazy::is_high(pb2)));
}

void set_two_pins() {
    set(pb0(lazy::is_high(pb2)), pb1(lazy::is_high(pb3)));
}

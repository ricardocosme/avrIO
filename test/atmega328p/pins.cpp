#include "../io.hpp"

void ctor() {
    ctor_impl(pb0, pb1, pb2, pb3, pb4, pb5, pb6, pb7);
    ctor_impl(pc0, pc1, pc2, pc3, pc4, pc5, pc6);
    ctor_impl(pd0, pd1, pd2, pd3, pd4, pd5, pd6, pd7);
}

void functions() {
    functions_impl(pb0, pb1, pb2, pb3, pb4, pb5);
    functions_impl(pc0, pc1, pc2, pc3, pc4, pc5, pc6);
    functions_impl(pd0, pd1, pd2, pd3, pd4, pd5, pd6);
    
    out(pb0, pb1);
    out(pb0, pb1, pb3);
    out(pb0, pb1, pb2, pb3, pb4, pb5);

    out(pc0, pc1);
    out(pc0, pc1, pc3);
    out(pc0, pc1, pc2, pc3, pc4, pc5, pc6);

    out(pd0, pd1);
    out(pd0, pd1, pd3);
    out(pd0, pd1, pd2, pd3, pd4, pd5, pd6);

    in(pb0, pb1);
    in(pb0, pb1, pb3);
    in(pb0, pb1, pb2, pb3, pb4, pb5);
    
    in(pc0, pc1);
    in(pc0, pc1, pc3);
    in(pc0, pc1, pc2, pc3, pc4, pc5, pc6);
    
    in(pd0, pd1);
    in(pd0, pd1, pd3);
    in(pd0, pd1, pd2, pd3, pd4, pd5, pd6);
    
    in(pullup, pb0, pb1);
    in(pullup, pb0, pb1, pb3);
    in(pullup, pb0, pb1, pb2, pb3, pb4, pb5);

    in(pullup, pc0, pc1);
    in(pullup, pc0, pc1, pc3);
    in(pullup, pc0, pc1, pc2, pc3, pc4, pc5, pc6);
    
    in(pullup, pd0, pd1);
    in(pullup, pd0, pd1, pd3);
    in(pullup, pd0, pd1, pd2, pd3, pd4, pd5, pd6);
    
    set(pb0, pb1);
    set(pb0, pb1, pb3);
    set(pb0, pb1, pb2, pb3, pb4, pb5);

    set(pc0, pc1);
    set(pc0, pc1, pc3);
    set(pc0, pc1, pc2, pc3, pc4, pc5, pc6);
    
    set(pd0, pd1);
    set(pd0, pd1, pd3);
    set(pd0, pd1, pd2, pd3, pd4, pd5, pd6);
    
    set(pb0(lazy::is_high(pb2)));
}

void set_two_pins() {
    set(pb0(lazy::is_high(pb2)), pb1(lazy::is_high(pb3)));
}

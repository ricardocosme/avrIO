#include "../expected_io.hpp"

void ctor() { ctor_impl<PB0, PB1, PB2, PB3, PB4, PB5>(DDRB); }

void functions() {
    functions_impl<PB0, PB1, PB2, PB3, PB4, PB5>(PINB, DDRB);

    //out(pb0, pb1);
    DDRB |= (1<<PB0);
    DDRB |= (1<<PB1);
    //out(pb0, pb1, pb3);
    DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB3);
    //out(pb0, pb1, pb2, pb3, pb4, pb5);
    DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);

    //in(pb0, pb1);
    DDRB &= ~(1<<PB0);
    DDRB &= ~(1<<PB1);
    //in(pb0, pb1, pb3);
    DDRB &= ~((1<<PB0) | (1<<PB1) | (1<<PB3));
    //in(pb0, pb1, pb2, pb3, pb4, pb5);
    DDRB &= ~((1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5));
    
    //in(pullup, pb0, pb1);
    DDRB &= ~(1<<PB0);
    DDRB &= ~(1<<PB1);
    PORTB |= (1<<PB0);
    PORTB |= (1<<PB1);
    //in(pullup, pb0, pb1, pb3);
    DDRB &= ~((1<<PB0) | (1<<PB1) | (1<<PB3));
    PORTB |= (1<<PB0) | (1<<PB1) | (1<<PB3);
    //in(pullup, pb0, pb1, pb2, pb3, pb4, pb5);
    DDRB &= ~((1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5));
    PORTB |= (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);

    //set(pb0, pb1);
    PORTB |= (1<<PB0);
    PORTB |= (1<<PB1);
    //set(pb0, pb1, pb3);
    PORTB |= (1<<PB0) | (1<<PB1) | (1<<PB3);
    //set(pb0, pb1, pb2, pb3, pb4, pb5);
    PORTB |= (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);

    //set(pb0(pb2.is_high()));
    if(PINB & (1<<PB2)) PORTB |= (1<<PB0);
    else PORTB &= ~(1<<PB0);
    
    //clear(pb0, pb1);
    asm("cbi 0x18,0\n cbi 0x18, 1");
    
    //clear(pb3, ~pb1, pb0);
    //PORTB = (PORTB & ~((1<<PB3) | (1<<PB0))) | PB1;
    {
        uint8_t reg;
        asm volatile(
            "in %0, 0x18 \n"
            "andi %0, 0xf4 \n"
            "ori %0, 0x02 \n"
            "out 0x18, %0 \n"
            : "=r" (reg)
            );
    }
    
    //toggle(pb0, pb1);
    PINB |= (1<<PB0);
    PINB |= (1<<PB1);
    //toggle(pb0, pb1, pb3);
    PINB |= (1<<PB0) | (1<<PB1) | (1<<PB3);
    //toggle(pb0, pb1, pb2, pb3, pb4, pb5);
    PINB |= (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);
}

// set(pb0(lazy::is_high(pb2)), pb1(lazy::is_high(pb3)),);
void set_two_pins() {
    uint8_t mask;
    asm volatile("ldi %0,0x00" :"=r"(mask)::);
    if(PINB & (1<<PB2)) mask |= (1<<PB0);
    if(PINB & (1<<PB3)) mask |= (1<<PB1);
    PORTB = (PORTB & 0xfc) | mask;
}

#include "../expected_io.hpp"

void ctor() {
    ctor_impl<PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7>(DDRB);
    ctor_impl<PC0, PC1, PC2, PC3, PC4, PC5, PC6>(DDRC);
    ctor_impl<PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7>(DDRD);
}
void functions() {
    functions_impl<PB0, PB1, PB2, PB3, PB4, PB5>(PINB, DDRB);
    functions_impl<PC0, PC1, PC2, PC3, PC4, PC5, PC6>(PINC, DDRC);
    functions_impl<PD0, PD1, PD2, PD3, PD4, PD5, PD6>(PIND, DDRD);

    //out(pb0, pb1);
    DDRB |= (1<<PB0);
    DDRB |= (1<<PB1);
    //out(pb0, pb1, pb3);
    DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB3);
    //out(pb0, pb1, pb2, pb3, pb4, pb5);
    DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);

    //out(pc0, pc1);
    DDRC |= (1<<PC0);
    DDRC |= (1<<PC1);
    //out(pc0, pc1, pc3);
    DDRC |= (1<<PC0) | (1<<PC1) | (1<<PC3);
    //out(pc0, pc1, pc2, pc3, pc4, pc5);
    DDRC |= (1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5) | (1<<PC6);
    
    //out(pc0, pc1);
    DDRD |= (1<<PD0);
    DDRD |= (1<<PD1);
    //out(pd0, pd1, pd3);
    DDRD |= (1<<PD0) | (1<<PD1) | (1<<PD3);
    //out(pd0, pd1, pd2, pd3, pd4, pd5);
    DDRD |= (1<<PD0) | (1<<PD1) | (1<<PD2) | (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD6);
    
    //in(pb0, pb1);
    DDRB &= ~(1<<PB0);
    DDRB &= ~(1<<PB1);
    //in(pb0, pb1, pb3);
    DDRB &= ~((1<<PB0) | (1<<PB1) | (1<<PB3));
    //in(pb0, pb1, pb2, pb3, pb4, pb5);
    DDRB &= ~((1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5));
    
    //in(pc0, pc1);
    DDRC &= ~(1<<PC0);
    DDRC &= ~(1<<PC1);
    //in(pc0, pc1, pc3);
    DDRC &= ~((1<<PC0) | (1<<PC1) | (1<<PC3));
    //in(pc0, pc1, pc2, pc3, pc4, pc5);
    DDRC &= ~((1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5) | (1<<PC6));
    
    //in(pc0, pc1);
    DDRD &= ~(1<<PD0);
    DDRD &= ~(1<<PD1);
    //in(pd0, pd1, pd3);
    DDRD &= ~((1<<PD0) | (1<<PD1) | (1<<PD3));
    //in(pd0, pd1, pd2, pd3, pd4, pd5);
    DDRD &= ~((1<<PD0) | (1<<PD1) | (1<<PD2) | (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD6));
    
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

    //in(pullup, pc0, pc1);
    DDRC &= ~(1<<PC0);
    DDRC &= ~(1<<PC1);
    PORTC |= (1<<PC0);
    PORTC |= (1<<PC1);
    //in(pullup, pc0, pc1, pc3);
    DDRC &= ~((1<<PC0) | (1<<PC1) | (1<<PC3));
    PORTC |= (1<<PC0) | (1<<PC1) | (1<<PC3);
    //in(pullup, pc0, pc1, pc2, pc3, pc4, pc5);
    DDRC &= ~((1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5) | (1<<PC6));
    PORTC |= (1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5) | (1<<PC6);
    
    //in(pullup, pd0, pd1);
    DDRD &= ~(1<<PD0);
    DDRD &= ~(1<<PD1);
    PORTD |= (1<<PD0);
    PORTD |= (1<<PD1);
    //in(pullup, pd0, pd1, pd3);
    DDRD &= ~((1<<PD0) | (1<<PD1) | (1<<PD3));
    PORTD |= (1<<PD0) | (1<<PD1) | (1<<PD3);
    //in(pullup, pd0, pd1, pd2, pd3, pd4, pd5);
    DDRD &= ~((1<<PD0) | (1<<PD1) | (1<<PD2) | (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD6));
    PORTD |= (1<<PD0) | (1<<PD1) | (1<<PD2) | (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD6);
    
    //set(pb0, pb1);
    PORTB |= (1<<PB0);
    PORTB |= (1<<PB1);
    //set(pb0, pb1, pb3);
    PORTB |= (1<<PB0) | (1<<PB1) | (1<<PB3);
    //set(pb0, pb1, pb2, pb3, pb4, pb5);
    PORTB |= (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);

    //set(pc0, pc1);
    PORTC |= (1<<PC0);
    PORTC |= (1<<PC1);
    //set(pc0, pc1, pc3);
    PORTC |= (1<<PC0) | (1<<PC1) | (1<<PC3);
    //set(pc0, pc1, pc2, pc3, pc4, pc5);
    PORTC |= (1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5) | (1<<PC6);
    
    //set(pd0, pd1);
    PORTD |= (1<<PD0);
    PORTD |= (1<<PD1);
    //set(pd0, pd1, pd3);
    PORTD |= (1<<PD0) | (1<<PD1) | (1<<PD3);
    //set(pd0, pd1, pd2, pd3, pd4, pd5);
    PORTD |= (1<<PD0) | (1<<PD1) | (1<<PD2) | (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD6);
    
    //set(pb0(pb2.is_high()));
    if(PINB & (1<<PB2)) PORTB |= (1<<PB0);
    else PORTB &= ~(1<<PB0);
}
// set(pb0(lazy::is_high(pb2)), pb1(lazy::is_high(pb3)),);
void set_two_pins() {
    uint8_t mask;
    asm volatile("ldi %0,0x00" :"=r"(mask)::);
    if(PINB & (1<<PB2)) mask |= (1<<PB0);
    if(PINB & (1<<PB3)) mask |= (1<<PB1);
    PORTB = (PORTB & 0xfc) | mask;
}

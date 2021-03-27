#include <avr/io.h>

#include "../expected_sreg.hpp"

void regs() {
    SPL = 0xff;
    GIMSK = _BV(INT0) | _BV(PCIE);
    GIFR = _BV(INTF0) | _BV(PCIF);
    TIMSK = _BV(OCIE1A) | _BV(OCIE1B) | _BV(OCIE0A) | _BV(OCIE0B) | _BV(TOIE1) | _BV(TOIE0);
    TIFR = _BV(OCF1A) | _BV(OCF1B) | _BV(OCF0A) | _BV(OCF0B) | _BV(TOV0) | _BV(TOV1);
    SPMCSR = (1<<RSIG) | (1<<CTPB) | (1<<RFLB) | (1<<PGWRT) | (1<<PGERS) | (1<<SPMEN);
    MCUCR = (1<<BODS) | (1<<PUD) | (1<<SE) | (1<<SM1) | (1<<SM0) | (1<<BODSE) | (1<<ISC01) | (1<<ISC00);
    MCUSR = (1<<WDRF) | (1<<BORF) | (1<<EXTRF) | (1<<PORF);
    TCCR0B = (1<<FOC0A) | (1<<FOC0B) | (1<<WGM02) | (1<<CS02) | (1<<CS01) | (1<<CS00);
    TCNT0 = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    OSCCAL = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    TCCR1 = (1<<CTC1) | (1<<PWM1A) | (1<<COM1A1) | (1<<COM1A0) | (1<<CS13) | (1<<CS12) | (1<<CS11) | (1<<CS10);
    TCNT1 = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    OCR1A = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    OCR1C = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    GTCCR = (1<<TSM) | (1<<PWM1B) | (1<<COM1B1) | (1<<COM1B0) | (1<<FOC1B) | (1<<FOC1A) | (1<<PSR1) | (1<<PSR0);
    OCR1B = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    TCCR0A = (1<<COM0A1) | (1<<COM0A0) | (1<<COM0B1) | (1<<COM0B0) | (1<<WGM01) | (1<<WGM00);
    OCR0A = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    OCR0B = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    PLLCSR = (1<<LSM) | (1<<PCKE) | (1<<PLLE) | (1<<PLOCK);
    CLKPR = (1<<CLKPCE) | (1<<CLKPS3) | (1<<CLKPS2) | (1<<CLKPS1) | (1<<CLKPS0);
    DT1A = (1<<DT1AH3) | (1<<DT1AH2) | (1<<DT1AH1) | (1<<DT1AH0) | (1<<DT1AL3) | (1<<DT1AL2) | (1<<DT1AL1) | (1<<DT1AL0);
    DT1B = (1<<DT1BH3) | (1<<DT1BH2) | (1<<DT1BH1) | (1<<DT1BH0) | (1<<DT1BL3) | (1<<DT1BL2) | (1<<DT1BL1) | (1<<DT1BL0);
    DTPS1 = (1<<DTPS11) | (1<<DTPS10);
    DWDR = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    WDTCR = (1<<WDIF) | (1<<WDIE) | (1<<WDP3) | (1<<WDCE) | (1<<WDE) | (1<<WDP2) | (1<<WDP1) | (1<<WDP0);
    PRR = (1<<PRTIM1) | (1<<PRTIM0) | (1<<PRUSI) | (1<<PRADC);
    EEARH = (1<<0);
    EEARL = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    EEDR = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    EECR = (1<<EEPM1) | (1<<EEPM0) | (1<<EERIE) | (1<<EEMPE) | (1<<EEPE) | (1<<EERE);
    PORTB = (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5);
    PORTB = (1<<PORTB0) | (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    DDRB = (1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3) | (1<<DDB4) | (1<<DDB5);
    PINB = (1<<PINB0) | (1<<PINB1) | (1<<PINB2) | (1<<PINB3) | (1<<PINB4) | (1<<PINB5);
    PCMSK = (1<<PCINT0) | (1<<PCINT1) | (1<<PCINT2) | (1<<PCINT3) | (1<<PCINT4) | (1<<PCINT5);
    DIDR0 = (1<<ADC0D) | (1<<ADC2D) | (1<<ADC3D) | (1<<ADC1D) | (1<<AIN1D) | (1<<AIN0D);
    USISR = (1<<USISIF) | (1<<USIOIF) | (1<<USIPF) | (1<<USIDC) | (1<<USICNT3) | (1<<USICNT2) | (1<<USICNT1) | (1<<USICNT0);
    USICR = (1<<USISIE) | (1<<USIOIE) | (1<<USIWM1) | (1<<USIWM0) | (1<<USICS1) | (1<<USICS0) | (1<<USICLK) | (1<<USITC);
    ACSR = (1<<ACD) | (1<<ACBG) | (1<<ACO) | (1<<ACI) | (1<<ACIE) | (1<<ACIS1) | (1<<ACIS0);
    ADMUX = (1<<REFS1) | (1<<REFS0) | (1<<ADLAR) | (1<<REFS2) | (1<<MUX3) | (1<<MUX2) | (1<<MUX1) | (1<<MUX0);
    ADCSRA = (1<<ADEN) | (1<<ADSC) | (1<<ADATE) | (1<<ADIF) | (1<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    ADCH = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    ADCL = (1<<7) | (1<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);
    ADCSRB = (1<<BIN) | (1<<ACME) | (1<<IPR) | (1<<ADTS2) | (1<<ADTS1) | (1<<ADTS0);
}

void f() {
    //portb.clear(pb0(0), pb1);
    asm("sbi 0x18,0\n cbi 0x18, 1");
    //portb.clear(pb0, ~pb1, pb2);
    // PORTB = (PORTB & ~((1<<PB0) | (1<<PB2))) | PB1;
    {
        uint8_t reg;
        asm volatile(
            "in %0, 0x18 \n"
            "andi %0, 0xf8 \n"
            "ori %0, 0x02 \n"
            "out 0x18, %0 \n"
            : "=r" (reg)
            );
    }
}

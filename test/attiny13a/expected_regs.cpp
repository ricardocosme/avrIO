#include <avr/io.h>

#include "../expected_sreg.hpp"

void regs() {
    SPL = 0xff;
    GIMSK = _BV(INT0) | _BV(PCIE);
    GIFR = _BV(INTF0) | _BV(PCIF);
    TIMSK0 = _BV(OCIE0B) | _BV(OCIE0A) | _BV(TOIE0);
    TIFR0 = _BV(OCF0B) | _BV(OCF0A) | _BV(TOV0);
    SPMCSR = _BV(CTPB) | _BV(RFLB) | _BV(PGWRT) | _BV(PGERS) | _BV(SPMEN);
    OCR0A = _BV(OCR0A_7) | _BV(OCR0A_6) | _BV(OCR0A_5) | _BV(OCR0A_4) | _BV(OCR0A_3) | _BV(OCR0A_2)
        | _BV(OCR0A_1) | _BV(OCR0A_0);
    MCUCR = _BV(PUD) | _BV(SE) | _BV(SM1) | _BV(SM0) | _BV(ISC01) | _BV(ISC00);
    MCUSR = _BV(WDRF) | _BV(BORF) | _BV(EXTRF) | _BV(PORF);
    TCCR0B = _BV(FOC0A) | _BV(FOC0B) | _BV(WGM02) | _BV(CS02) | _BV(CS01) | _BV(CS00);
    TCNT0 = _BV(TCNT0_7) | _BV(TCNT0_6) | _BV(TCNT0_5) | _BV(TCNT0_4) | _BV(TCNT0_3) | _BV(TCNT0_2)
        | _BV(TCNT0_1) | _BV(TCNT0_0);
    OSCCAL = _BV(CAL6) | _BV(CAL5) | _BV(CAL4) | _BV(CAL3)
        | _BV(CAL2) | _BV(CAL1) | _BV(CAL0);
    BODCR = _BV(BODS) | _BV(BODSE);
    TCCR0A = _BV(COM0A1) | _BV(COM0A0) | _BV(COM0B1) | _BV(COM0B0) | _BV(WGM01) | _BV(WGM00);
    DWDR = _BV(DWDR7) | _BV(DWDR6) | _BV(DWDR5) | _BV(DWDR4) | _BV(DWDR3) | _BV(DWDR2)
        | _BV(DWDR1) | _BV(DWDR0);
    OCR0B = _BV(OCR0B_7) | _BV(OCR0B_6) | _BV(OCR0B_5) | _BV(OCR0B_4) | _BV(OCR0B_3) | _BV(OCR0B_2)
        | _BV(OCR0B_1) | _BV(OCR0B_0);
    GTCCR = _BV(TSM) | _BV(PSR10);
    CLKPR = _BV(CLKPCE) | _BV(CLKPS3) | _BV(CLKPS2) | _BV(CLKPS1) | _BV(CLKPS0);
    PRR = _BV(PRTIM0) | _BV(PRADC);
    WDTCR = _BV(WDTIF) | _BV(WDTIE) | _BV(WDP3) | _BV(WDCE) | _BV(WDE) | _BV(WDP2)
        | _BV(WDP1) | _BV(WDP0);
    EEARL = _BV(EEAR5) | _BV(EEAR4) | _BV(EEAR3) | _BV(EEAR2)
        | _BV(EEAR1) | _BV(EEAR0);
    EEDR = _BV(EEDR7) | _BV(EEDR6) | _BV(EEDR5) | _BV(EEDR4) | _BV(EEDR3) | _BV(EEDR2)
        | _BV(EEDR1) | _BV(EEDR0);
    EECR = _BV(EEPM1) | _BV(EEPM0) | _BV(EERIE) | _BV(EEMPE) | _BV(EEPE) | _BV(EERE);
    PORTB = _BV(PB0) | _BV(PB1) | _BV(PB2) | _BV(PB3) | _BV(PB4) | _BV(PB5);
    PORTB = _BV(PB0) | _BV(PB1) | _BV(PB2) | _BV(PB3) | _BV(PB4) | _BV(PB5);
    DDRB = _BV(DDB0) | _BV(DDB1) | _BV(DDB2) | _BV(DDB3) | _BV(DDB4) | _BV(DDB5);
    PINB = _BV(PINB0) | _BV(PINB1) | _BV(PINB2) | _BV(PINB3) | _BV(PINB4) | _BV(PINB5);
    PCMSK = _BV(PCINT0) | _BV(PCINT1) | _BV(PCINT2) | _BV(PCINT3) | _BV(PCINT4) | _BV(PCINT5);
    DIDR0 = _BV(ADC0D) | _BV(ADC2D) | _BV(ADC3D) | _BV(ADC1D) | _BV(AIN1D) | _BV(AIN0D);
    ACSR = _BV(ACD) | _BV(ACBG) | _BV(ACO) | _BV(ACI) | _BV(ACIE) | _BV(ACIS1) | _BV(ACIS0);
    ADMUX = _BV(REFS0) | _BV(ADLAR) | _BV(MUX1) | _BV(MUX0);
    ADCSRA = _BV(ADEN) | _BV(ADSC) | _BV(ADATE) | _BV(ADIF) | _BV(ADIE) | _BV(ADPS2)
        | _BV(ADPS1) | _BV(ADPS0);
    ADCH = _BV(ADCH7) | _BV(ADCH6) | _BV(ADCH5) | _BV(ADCH4) | _BV(ADCH3) | _BV(ADCH2)
        | _BV(ADCH1) | _BV(ADCH0);
    ADCL = _BV(ADCL7) | _BV(ADCL6) | _BV(ADCL5) | _BV(ADCL4) | _BV(ADCL3) | _BV(ADCL2)
        | _BV(ADCL1) | _BV(ADCL0);
    ADCSRB = _BV(ACME) | _BV(ADTS2) | _BV(ADTS1) | _BV(ADTS0);
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

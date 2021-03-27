#include <avr/io.hpp>

#include "../sreg.hpp"

using namespace avr::io;

void regs() {
    spl = sp0 | sp1 | sp2 | sp3 | sp4 | sp5 | sp6 | sp7;
    gimsk = int0 | pcie;
    gifr = intf0 | pcif;
    timsk0 = ocie0b | ocie0a | toie0;
    tifr0 = ocf0b | ocf0a | tov0;
    spmcsr = ctpb | rflb | pgwrt | pgers | selfprgen;
    ocr0a = ocr0a7 | ocr0a6 | ocr0a5 | ocr0a4 | ocr0a3 | ocr0a2 | ocr0a1 | ocr0a0;
    mcucr = pud | se | sm1 | sm0 | isc01 | isc00;
    mcusr = wdrf | borf | extrf | porf;
    tccr0b = foc0a | foc0b | wgm02 | cs02 | cs01 | cs00;
    tcnt0 = tcnt07 | tcnt06 | tcnt05 | tcnt04 | tcnt03 | tcnt02 | tcnt01 | tcnt00;
    osccal = cal6 | cal5 | cal4 | cal3 | cal2 | cal1 | cal0;
    bodcr = bods | bodse;
    tccr0a = com0a1 | com0a0 | com0b1 | com0b0 | wgm01 | wgm00;
    dwdr = dwdr7 | dwdr6 | dwdr5 | dwdr4 | dwdr3 | dwdr2 | dwdr1 | dwdr0;
    ocr0b = ocr0b7 | ocr0b6 | ocr0b5 | ocr0b4 | ocr0b3 | ocr0b2 | ocr0b1 | ocr0b0;
    gtccr = tsm | psr10;
    clkpr = clkpce | clkps3 | clkps2 | clkps1 | clkps0;
    prr = prtim0 | pradc;
    wdtcr = wdtif | wdtie | wdp3 | wdce | wde | wdp2 | wdp1 | wdp0;
    eearl = eear5 | eear4 | eear3 | eear2 | eear1 | eear0;
    eedr = eedr7 | eedr6 | eedr5 | eedr4 | eedr3 | eedr2 | eedr1 | eedr0;
    eecr = eepm1 | eepm0 | eerie | eempe | eepe | eere;
    portb = pb0 | pb1 | pb2 | pb3 | pb4 | pb5;
    portb = portb0 | portb1 | portb2 | portb3 | portb4 | portb5;
    ddrb = ddb0 | ddb1 | ddb2 | ddb3 | ddb4 | ddb5;
    pinb = pinb0 | pinb1 | pinb2 | pinb3 | pinb4 | pinb5;
    pcmsk = pcint0 | pcint1 | pcint2 | pcint3 | pcint4 | pcint5;
    didr0 = adc0d | adc2d | adc3d | adc1d | ain1d | ain0d;
    acsr = acd | acbg | aco | aci | acie | acis1 | acis0;
    admux = refs0 | adlar | mux1 | mux0;
    adcsra = aden | adsc | adate | adif | adie | adps2 | adps1 | adps0;
    adch = adch7 | adch6 | adch5 | adch4 | adch3 | adch2 | adch1 | adch0;
    adcl = adcl7 | adcl6 | adcl5 | adcl4 | adcl3 | adcl2 | adcl1 | adcl0;
    adcsrb = acme | adts2 | adts1 | adts0;
}

void f() {
    portb.clear(pb0(off), pb1);
    portb.clear(pb0, ~pb1, pb2);
}

#include <avr/io.hpp>

#include "../sreg.hpp"

using namespace avr::io;

void regs() {
    spl = sp0 | sp1 | sp2 | sp3 | sp4 | sp5 | sp6 | sp7;
    gimsk = int0 | pcie;
    gifr = intf0 | pcif;
    timsk = ocie1a | ocie1b | ocie0a | ocie0b | ocie0a | toie1 | toie0;
    tifr = ocf1a | ocf1b | ocf0a | ocf0b | ocf0a | tov1 | tov0;
    spmcsr = rsig | ctpb | rflb | pgwrt | pgers | spmen;
    mcucr = bods | pud | se | sm1 | sm0 | bodse | isc01 | isc00;
    mcusr = wdrf | borf | extrf | porf;
    tccr0b = foc0a | foc0b | wgm02 | cs02 | cs01 | cs00;
    tcnt0 = tcnt07 | tcnt06 | tcnt05 | tcnt04 | tcnt03 | tcnt02 | tcnt01 | tcnt00;
    osccal = cal7 | cal6 | cal5 | cal4 | cal3 | cal2 | cal1 | cal0;
    tccr1 = ctc1 | pwm1a | com1a1 | com1a0 | cs13 | cs12 | cs11 | cs10;
    tcnt1 = tcnt17 | tcnt16 | tcnt15 | tcnt14 | tcnt13 | tcnt12 | tcnt11 | tcnt10;
    ocr1a = ocr1a7 | ocr1a6 | ocr1a5 | ocr1a4 | ocr1a3 | ocr1a2 | ocr1a1 | ocr1a0;
    ocr1c = ocr1c7 | ocr1c6 | ocr1c5 | ocr1c4 | ocr1c3 | ocr1c2 | ocr1c1 | ocr1c0;
    gtccr = tsm | pwm1b | com1b1 | com1b0 | foc1b | foc1a | psr1 | psr0;
    ocr1b = ocr1b7 | ocr1b6 | ocr1b5 | ocr1b4 | ocr1b3 | ocr1b2 | ocr1b1 | ocr1b0;
    tccr0a = com0a1 | com0a0 | com0b1 | com0b0 | wgm01 | wgm00;
    ocr0a = ocr0a7 | ocr0a6 | ocr0a5 | ocr0a4 | ocr0a3 | ocr0a2 | ocr0a1 | ocr0a0;
    ocr0b = ocr0b7 | ocr0b6 | ocr0b5 | ocr0b4 | ocr0b3 | ocr0b2 | ocr0b1 | ocr0b0;
    pllcsr = lsm | pcke | plle | plock;
    clkpr = clkpce | clkps3 | clkps2 | clkps1 | clkps0;
    dt1a = dt1ah3 | dt1ah2 | dt1ah1 | dt1ah0 | dt1al3 | dt1al2 | dt1al1 | dt1al0;
    dt1b = dt1bh3 | dt1bh2 | dt1bh1 | dt1bh0 | dt1bl3 | dt1bl2 | dt1bl1 | dt1bl0;
    dtps1 = dtps11 | dtps10;
    dwdr = dwdr7 | dwdr6 | dwdr5 | dwdr4 | dwdr3 | dwdr2 | dwdr1 | dwdr0;
    wdtcr = wdif | wdie | wdp3 | wdce | wde | wdp2 | wdp1 | wdp0;
    prr = prtim1 | prtim0 | prusi | pradc;
    eearh = eear8;
    eearl = eear7 | eear6 | eear5 | eear4 | eear3 | eear2 | eear1 | eear0;
    eedr = eedr7 | eedr6 | eedr5 | eedr4 | eedr3 | eedr2 | eedr1 | eedr0;
    eecr = eepm1 | eepm0 | eerie | eempe | eepe | eere;
    portb = pb0 | pb1 | pb2 | pb3 | pb4 | pb5;
    portb = portb0 | portb1 | portb2 | portb3 | portb4 | portb5;
    ddrb = ddb0 | ddb1 | ddb2 | ddb3 | ddb4 | ddb5;
    pinb = pinb0 | pinb1 | pinb2 | pinb3 | pinb4 | pinb5;
    pcmsk = pcint0 | pcint1 | pcint2 | pcint3 | pcint4 | pcint5;
    didr0 = adc0d | adc2d | adc3d | adc1d | ain1d | ain0d;
    usisr = usisif | usioif | usipf | usidc | usicnt3 | usicnt2 | usicnt1 | usicnt0;
    usicr = usisie | usioie | usiwm1 | usiwm0 | usics1 | usics0 | usiclk | usitc;
    acsr = acd | acbg | aco | aci | acie | acis1 | acis0;
    admux = refs1 | refs0 | adlar | refs2 | mux3 | mux2 | mux1 | mux0;
    adcsra = aden | adsc | adate | adif | adie | adps2 | adps1 | adps0;
    adch = adch7 | adch6 | adch5 | adch4 | adch3 | adch2 | adch1 | adch0;
    adcl = adcl7 | adcl6 | adcl5 | adcl4 | adcl3 | adcl2 | adcl1 | adcl0;
    adcsrb = bin | acme | ipr | adts2 | adts1 | adts0;
}

void f() {
    portb.clear(pb0(off), pb1);
    portb.clear(pb0, ~pb1, pb2);
}

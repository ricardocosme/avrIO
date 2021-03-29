#include <avr/io.hpp>

#include "../sreg.hpp"

using namespace avr::io;

void regs() {
    udr0 = udr0_0 | udr0_1 | udr0_2 | udr0_3 | udr0_4 | udr0_5 | udr0_6 | udr0_7;
    ubrr0h = ubrr0_11 | ubrr0_10 | ubrr0_9 | ubrr0_8;
    ubrr0l = ubrr0_0 | ubrr0_1 | ubrr0_2 | ubrr0_3 | ubrr0_4 | ubrr0_5 | ubrr0_6 | ubrr0_7;
    ucsr0c = umsel01 | umsel00 | upm01 | upm00 | usbs0 | ucsz01 | ucsz00 | ucpol0;
    ucsr0b = rxcie0 | txcie0 | udrie0 | rxen0 | txen0 | ucsz02 | rxb80 | txb80;
    ucsr0a = rxc0 | txc0 | udre0 | fe0 | dor0 | upe0 | u2x0 | mpcm0;
    twamr = twam6 | twam5 | twam4 | twam3 | twam2 | twam1 | twam0;
    twcr = twint | twea | twsta | twsto | twwc | twen | twie;
    twdr=twd7|twd6|twd5|twd4|twd3|twd2|twd1|twd0;
    twar=twa6|twa5|twa4|twa3|twa2|twa1|twa0|twgce;
    twsr=tws7|tws6|tws5|tws4|tws3|twps1|twps0;
    twbr=twbr7|twbr6|twbr5|twbr4|twbr3|twbr2|twbr1|twbr0;
    assr=exclk|as2|tcn2ub|ocr2aub|ocr2bub|tcr2aub|tcr2bub;
    ocr2b=ocr2b_7|ocr2b_6|ocr2b_5|ocr2b_4|ocr2b_3|ocr2b_2|ocr2b_1|ocr2b_0;
    ocr2a=ocr2a_7|ocr2a_6|ocr2a_5|ocr2a_4|ocr2a_3|ocr2a_2|ocr2a_1|ocr2a_0;
    tcnt2=tcnt2_7|tcnt2_6|tcnt2_5|tcnt2_4|tcnt2_3|tcnt2_2|tcnt2_1|tcnt2_0;
    tccr2b=foc2a|foc2b|wgm22|cs22|cs21|cs20;
    ocr1bh=ocr1b_15|ocr1b_14|ocr1b_13|ocr1b_12|ocr1b_11|ocr1b_10|ocr1b_9|ocr1b_8;
    ocr1bl=ocr1b_7|ocr1b_6|ocr1b_5|ocr1b_4|ocr1b_3|ocr1b_2|ocr1b_1|ocr1b_0;
    ocr1ah=ocr1a_15|ocr1a_14|ocr1a_13|ocr1a_12|ocr1a_11|ocr1a_10|ocr1a_9|ocr1a_8;
    ocr1al=ocr1a_7|ocr1a_6|ocr1a_5|ocr1a_4|ocr1a_3|ocr1a_2|ocr1a_1|ocr1a_0;
    icr1h=icr1_15|icr1_14|icr1_13|icr1_12|icr1_11|icr1_10|icr1_9|icr1_8;
    icr1l=icr1_7|icr1_6|icr1_5|icr1_4|icr1_3|icr1_2|icr1_1|icr1_0;
    tcnt1h=tcnt1_15|tcnt1_14|tcnt1_13|tcnt1_12|tcnt1_11|tcnt1_10|tcnt1_9|tcnt1_8;
    tcnt1l=tcnt1_7|tcnt1_6|tcnt1_5|tcnt1_4|tcnt1_3|tcnt1_2|tcnt1_1|tcnt1_0;
    tccr1c=foc1a|foc1b;
    tccr1b=icnc1|ices1|wgm13|wgm12|cs12|cs11|cs10;
    tccr1a=com1a1|com1a0|com1b1|com1b0|wgm11|wgm10;
    didr1=ain1d|ain0d;
    didr0=adc5d|adc4d|adc3d|adc2d|adc1d|adc0d;
    admux=refs1|refs0|adlar|mux3|mux2|mux1|mux0;
    adcsrb=acme|adts2|adts1|adts0;
    adcsra=aden|adsc|adate|adif|adie|adps2|adps1|adps0;
    adch=adc_9|adc_8;
    adcl=adc_7|adc_6|adc_5|adc_4|adc_3|adc_2|adc_1|adc_0;
    timsk2=ocie2b|ocie2a|toie2;
    timsk1=icie1|ocie1b|ocie1a|toie1;
    timsk0=ocie0b|ocie0a|toie0;
    pcmsk2=pcint23|pcint22|pcint21|pcint20|pcint19|pcint18|pcint17|pcint16;
    pcmsk1=pcint14|pcint13|pcint12|pcint11|pcint10|pcint9|pcint8;
    pcmsk0=pcint7|pcint6|pcint5|pcint4|pcint3|pcint2|pcint1|pcint0;
    eicra=isc11|isc10|isc01|isc00;
    pcicr=pcie2|pcie1|pcie0;
    osccal=cal7|cal6|cal5|cal4|cal3|cal2|cal1|cal0;
    prr=prtwi|prtim2|prtim0|prtim1|prspi|prusart0|pradc;
    clkpr=clkpce|clkps3|clkps1|clkps0;
    wdtcsr=wdif|wdie|wdp3|wdce|wde|wdp2|wdp1|wdp0;
    sph=sp10|sp9|sp8;
    spl=sp0|sp1|sp2|sp3|sp4|sp5|sp6|sp7;
    spmcsr = spmie | rwwsb | rwwsre | blbset | pgwrt | pgers | selfprgen;
    mcucr=bods|bodse|pud|ivsel|ivce;
    mcusr = wdrf | borf | extrf | porf;
    smcr=sm2|sm1|sm0|se;
    acsr = acd | acbg | aco | aci | acie | acic | acis1 | acis0;
    spdr=spdr7|spdr6|spdr5|spdr4|spdr3|spdr2|spdr1|spdr0;
    spsr=spif|wcol|spi2x;
    spcr=spie|spe|dord|mstr|cpol|cpha|spr1|spr0;
    gpior2=gpior2_7|gpior2_6|gpior2_5|gpior2_4|gpior2_3|gpior2_2|gpior2_1|gpior2_0;
    gpior1=gpior1_7|gpior1_6|gpior1_5|gpior1_4|gpior1_3|gpior1_2|gpior1_1|gpior1_0;
    ocr0b=ocr0b7|ocr0b6|ocr0b5|ocr0b4|ocr0b3|ocr0b2|ocr0b1|ocr0b0;
    ocr0a=ocr0a7|ocr0a6|ocr0a5|ocr0a4|ocr0a3|ocr0a2|ocr0a1|ocr0a0;
    tcnt0=tcnt0_7|tcnt0_6|tcnt0_5|tcnt0_4|tcnt0_3|tcnt0_2|tcnt0_1|tcnt0_0;
    tccr0b=foc0a|foc0b|wgm02|cs02|cs01|cs00;
    tccr0a=com0a1|com0a0|com0b1|com0b0|wgm01|wgm00;
    gtccr=tsm|psrasy|psrsync;
    eearh=eear8;
    eearl=eear7|eear6|eear5|eear4|eear3|eear2|eear1|eear0;
    eedr=eedr7|eedr6|eedr5|eedr4|eedr3|eedr2|eedr1|eedr0;
    eecr=eepm1|eepm0|eerie|eempe|eepe|eere;
    gpior0=gpior0_7|gpior0_6|gpior0_5|gpior0_4|gpior0_3|gpior0_2|gpior0_1|gpior0_0;
    eimsk=int1|int0;
    eifr=intf1|intf0;
    pcifr=pcif2|pcif1|pcif0;
    tifr2=ocf2b|ocf2a|tov2;
    tifr1=icf1|ocf1b|ocf1a|tov1;
    tifr0=ocf0b|ocf0a|tov0;
    portd = pd0 | pd1 | pd2 | pd3 | pd4 | pd5 | pd6 | pd7;
    portd = portd0 | portd1 | portd2 | portd3 | portd4 | portd5 | portd6 | portd7;
    ddrd = ddd0 | ddd1 | ddd2 | ddd3 | ddd4 | ddd5 | ddd6 | ddd7;
    pind = pind0 | pind1 | pind2 | pind3 | pind4 | pind5 | pind6 | pind7;
    portc = pc0 | pc1 | pc2 | pc3 | pc4 | pc5 | pc6;
    portc = portc0 | portc1 | portc2 | portc3 | portc4 | portc5 | portc6;
    ddrc = ddc0 | ddc1 | ddc2 | ddc3 | ddc4 | ddc5 | ddc6;
    pinc = pinc0 | pinc1 | pinc2 | pinc3 | pinc4 | pinc5 | pinc6;
    portb = pb0 | pb1 | pb2 | pb3 | pb4 | pb5 | pb6 | pb7;
    portb = portb0 | portb1 | portb2 | portb3 | portb4 | portb5 | portb6 | portb7;
    ddrb = ddb0 | ddb1 | ddb2 | ddb3 | ddb4 | ddb5 | ddb6 | ddb7;
    pinb = pinb0 | pinb1 | pinb2 | pinb3 | pinb4 | pinb5 | pinb6 | pinb7;
}

void f() {
    portb.clear(pb0(off), pb1);
    portb.clear(pb0, ~pb1, pb2);
}

void greater_or_equal_to_0x60() {
    wdtcsr = {wde,wdce};
}

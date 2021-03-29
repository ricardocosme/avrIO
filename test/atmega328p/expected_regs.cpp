#include <avr/io.h>

#include "../expected_sreg.hpp"

void regs() {
    UDR0 = (1<<UDR0_0) | (1<<UDR0_1) | (1<<UDR0_2) | (1<<UDR0_3) | (1<<UDR0_4) | (1<<UDR0_5) | (1<<UDR0_6) | (1<<UDR0_7);
    UBRR0H = (1<<UBRR0_11) | (1<<UBRR0_10) | (1<<UBRR0_9) | (1<<UBRR0_8);
    UBRR0L = (1<<UBRR0_0) | (1<<UBRR0_1) | (1<<UBRR0_2) | (1<<UBRR0_3) | (1<<UBRR0_4) | (1<<UBRR0_5) | (1<<UBRR0_6) | (1<<UBRR0_7);
    UCSR0C = (1<<UMSEL01) | (1<<UMSEL00) | (1<<UPM01) | (1<<UPM00) | (1<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (1<<UCPOL0);
    UCSR0B = (1<<RXCIE0) | (1<<TXCIE0) | (1<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0) | (1<<UCSZ02) | (1<<RXB80) | (1<<TXB80);
    UCSR0A = (1<<RXC0) | (1<<TXC0) | (1<<UDRE0) | (1<<FE0) | (1<<DOR0) | (1<<UPE0) | (1<<U2X0) | (1<<MPCM0);
    TWAMR = (1<<TWAM6) | (1<<TWAM5) | (1<<TWAM4) | (1<<TWAM3) | (1<<TWAM2) | (1<<TWAM1) | (1<<TWAM0);
    TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWSTA) | (1<<TWSTO) | (1<<TWWC) | (1<<TWEN) | (1<<TWIE);
    TWDR=(1<<TWD7)|(1<<TWD6)|(1<<TWD5)|(1<<TWD4)|(1<<TWD3)|(1<<TWD2)|(1<<TWD1)|(1<<TWD0);
    TWAR=(1<<TWA6)|(1<<TWA5)|(1<<TWA4)|(1<<TWA3)|(1<<TWA2)|(1<<TWA1)|(1<<TWA0)|(1<<TWGCE);
    TWSR=(1<<TWS7)|(1<<TWS6)|(1<<TWS5)|(1<<TWS4)|(1<<TWS3)|(1<<TWPS1)|(1<<TWPS0);
    TWBR=(1<<TWBR7)|(1<<TWBR6)|(1<<TWBR5)|(1<<TWBR4)|(1<<TWBR3)|(1<<TWBR2)|(1<<TWBR1)|(1<<TWBR0);
    ASSR=(1<<EXCLK)|(1<<AS2)|(1<<TCN2UB)|(1<<OCR2AUB)|(1<<OCR2BUB)|(1<<TCR2AUB)|(1<<TCR2BUB);
    OCR2B=(1<<OCR2_7)|(1<<OCR2_6)|(1<<OCR2_5)|(1<<OCR2_4)|(1<<OCR2_3)|(1<<OCR2_2)|(1<<OCR2_1)|(1<<OCR2_0);
    OCR2A=(1<<OCR2_7)|(1<<OCR2_6)|(1<<OCR2_5)|(1<<OCR2_4)|(1<<OCR2_3)|(1<<OCR2_2)|(1<<OCR2_1)|(1<<OCR2_0);
    TCNT2=(1<<TCNT2_7)|(1<<TCNT2_6)|(1<<TCNT2_5)|(1<<TCNT2_4)|(1<<TCNT2_3)|(1<<TCNT2_2)|(1<<TCNT2_1)|(1<<TCNT2_0);
    TCCR2B=(1<<FOC2A)|(1<<FOC2B)|(1<<WGM22)|(1<<CS22)|(1<<CS21)|(1<<CS20);
    OCR1BH=(1<<OCR1BH7)|(1<<OCR1BH6)|(1<<OCR1BH5)|(1<<OCR1BH4)|(1<<OCR1BH3)|(1<<OCR1BH2)|(1<<OCR1BH1)|(1<<OCR1BH0);
    OCR1BL=(1<<OCR1BL7)|(1<<OCR1BL6)|(1<<OCR1BL5)|(1<<OCR1BL4)|(1<<OCR1BL3)|(1<<OCR1BL2)|(1<<OCR1BL1)|(1<<OCR1BL0);
    OCR1AH=(1<<OCR1AH7)|(1<<OCR1AH6)|(1<<OCR1AH5)|(1<<OCR1AH4)|(1<<OCR1AH3)|(1<<OCR1AH2)|(1<<OCR1AH1)|(1<<OCR1AH0);
    OCR1AL=(1<<OCR1AL7)|(1<<OCR1AL6)|(1<<OCR1AL5)|(1<<OCR1AL4)|(1<<OCR1AL3)|(1<<OCR1AL2)|(1<<OCR1AL1)|(1<<OCR1AL0);
    ICR1H=(1<<ICR1H7)|(1<<ICR1H6)|(1<<ICR1H5)|(1<<ICR1H4)|(1<<ICR1H3)|(1<<ICR1H2)|(1<<ICR1H1)|(1<<ICR1H0);
    ICR1L=(1<<ICR1L7)|(1<<ICR1L6)|(1<<ICR1L5)|(1<<ICR1L4)|(1<<ICR1L3)|(1<<ICR1L2)|(1<<ICR1L1)|(1<<ICR1L0);
    TCNT1H=(1<<TCNT1H7)|(1<<TCNT1H6)|(1<<TCNT1H5)|(1<<TCNT1H4)|(1<<TCNT1H3)|(1<<TCNT1H2)|(1<<TCNT1H1)|(1<<TCNT1H0);
    TCNT1L=(1<<TCNT1L7)|(1<<TCNT1L6)|(1<<TCNT1L5)|(1<<TCNT1L4)|(1<<TCNT1L3)|(1<<TCNT1L2)|(1<<TCNT1L1)|(1<<TCNT1L0);
    TCCR1C=(1<<FOC1A)|(1<<FOC1B);
    TCCR1B=(1<<ICNC1)|(1<<ICES1)|(1<<WGM13)|(1<<WGM12)|(1<<CS12)|(1<<CS11)|(1<<CS10);
    TCCR1A=(1<<COM1A1)|(1<<COM1A0)|(1<<COM1B1)|(1<<COM1B0)|(1<<WGM11)|(1<<WGM10);
    DIDR1=(1<<AIN1D)|(1<<AIN0D);
    DIDR0=(1<<ADC5D)|(1<<ADC4D)|(1<<ADC3D)|(1<<ADC2D)|(1<<ADC1D)|(1<<ADC0D);
    ADMUX=(1<<REFS1)|(1<<REFS0)|(1<<ADLAR)|(1<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0);
    ADCSRB=(1<<ACME)|(1<<ADTS2)|(1<<ADTS1)|(1<<ADTS0);
    ADCSRA=(1<<ADEN)|(1<<ADSC)|(1<<ADATE)|(1<<ADIF)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
    ADCH=(1<<ADCH1)|(1<<ADCH0);
    ADCL=(1<<ADCL7)|(1<<ADCL6)|(1<<ADCL5)|(1<<ADCL4)|(1<<ADCL3)|(1<<ADCL2)|(1<<ADCL1)|(1<<ADCL0);
    TIMSK2=(1<<OCIE2B)|(1<<OCIE2A)|(1<<TOIE2);
    TIMSK1=(1<<ICIE1)|(1<<OCIE1B)|(1<<OCIE1A)|(1<<TOIE1);
    TIMSK0=(1<<OCIE0B)|(1<<OCIE0A)|(1<<TOIE0);
    PCMSK2=(1<<PCINT23)|(1<<PCINT22)|(1<<PCINT21)|(1<<PCINT20)|(1<<PCINT19)|(1<<PCINT18)|(1<<PCINT17)|(1<<PCINT16);
    PCMSK1=(1<<PCINT14)|(1<<PCINT13)|(1<<PCINT12)|(1<<PCINT11)|(1<<PCINT10)|(1<<PCINT9)|(1<<PCINT8);
    PCMSK0=(1<<PCINT7)|(1<<PCINT6)|(1<<PCINT5)|(1<<PCINT4)|(1<<PCINT3)|(1<<PCINT2)|(1<<PCINT1)|(1<<PCINT0);
    EICRA=(1<<ISC11)|(1<<ISC10)|(1<<ISC01)|(1<<ISC00);
    PCICR=(1<<PCIE2)|(1<<PCIE1)|(1<<PCIE0);
    OSCCAL=(1<<CAL7)|(1<<CAL6)|(1<<CAL5)|(1<<CAL4)|(1<<CAL3)|(1<<CAL2)|(1<<CAL1)|(1<<CAL0);
    PRR=(1<<PRTWI)|(1<<PRTIM2)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRADC);
    CLKPR=(1<<CLKPCE)|(1<<CLKPS3)|(1<<CLKPS1)|(1<<CLKPS0);
    WDTCSR=(1<<WDIF)|(1<<WDIE)|(1<<WDP3)|(1<<WDCE)|(1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0);
    SPH=(1<<2)|(1<<1)|(1<<0);
    SPL = 0xff;
    SPMCSR = (1<<SPMIE) | (1<<RWWSB) | (1<<RWWSRE) | (1<<BLBSET) | (1<<PGWRT) | (1<<PGERS) | (1<<SELFPRGEN);
    MCUCR=(1<<BODS)|(1<<BODSE)|(1<<PUD)|(1<<IVSEL)|(1<<IVCE);
    MCUSR = (1<<WDRF) | (1<<BORF) | (1<<EXTRF) | (1<<PORF);
    SMCR=(1<<SM2)|(1<<SM1)|(1<<SM0)|(1<<SE);
    ACSR = (1<<ACD) | (1<<ACBG) | (1<<ACO) | (1<<ACI) | (1<<ACIE) | (1<<ACIC) | (1<<ACIS1) | (1<<ACIS0);
    SPDR=(1<<SPDR7)|(1<<SPDR6)|(1<<SPDR5)|(1<<SPDR4)|(1<<SPDR3)|(1<<SPDR2)|(1<<SPDR1)|(1<<SPDR0);
    SPSR=(1<<SPIF)|(1<<WCOL)|(1<<SPI2X);
    SPCR=(1<<SPIE)|(1<<SPE)|(1<<DORD)|(1<<MSTR)|(1<<CPOL)|(1<<CPHA)|(1<<SPR1)|(1<<SPR0);
    GPIOR2=(1<<GPIOR27)|(1<<GPIOR26)|(1<<GPIOR25)|(1<<GPIOR24)|(1<<GPIOR23)|(1<<GPIOR22)|(1<<GPIOR21)|(1<<GPIOR20);
    GPIOR1=(1<<GPIOR17)|(1<<GPIOR16)|(1<<GPIOR15)|(1<<GPIOR14)|(1<<GPIOR13)|(1<<GPIOR12)|(1<<GPIOR11)|(1<<GPIOR10);
    OCR0B=(1<<OCR0B_7)|(1<<OCR0B_6)|(1<<OCR0B_5)|(1<<OCR0B_4)|(1<<OCR0B_3)|(1<<OCR0B_2)|(1<<OCR0B_1)|(1<<OCR0B_0);
    OCR0A=(1<<OCR0A_7)|(1<<OCR0A_6)|(1<<OCR0A_5)|(1<<OCR0A_4)|(1<<OCR0A_3)|(1<<OCR0A_2)|(1<<OCR0A_1)|(1<<OCR0A_0);
    TCNT0=(1<<TCNT0_7)|(1<<TCNT0_6)|(1<<TCNT0_5)|(1<<TCNT0_4)|(1<<TCNT0_3)|(1<<TCNT0_2)|(1<<TCNT0_1)|(1<<TCNT0_0);
    TCCR0B=(1<<FOC0A)|(1<<FOC0B)|(1<<WGM02)|(1<<CS02)|(1<<CS01)|(1<<CS00);
    TCCR0A=(1<<COM0A1)|(1<<COM0A0)|(1<<COM0B1)|(1<<COM0B0)|(1<<WGM01)|(1<<WGM00);
    GTCCR=(1<<TSM)|(1<<PSRASY)|(1<<PSRSYNC);
    EEARH=(1<<EEAR8);
    EEARL=(1<<EEAR7)|(1<<EEAR6)|(1<<EEAR5)|(1<<EEAR4)|(1<<EEAR3)|(1<<EEAR2)|(1<<EEAR1)|(1<<EEAR0);
    EEDR=(1<<EEDR7)|(1<<EEDR6)|(1<<EEDR5)|(1<<EEDR4)|(1<<EEDR3)|(1<<EEDR2)|(1<<EEDR1)|(1<<EEDR0);
    EECR=(1<<EEPM1)|(1<<EEPM0)|(1<<EERIE)|(1<<EEMPE)|(1<<EEPE)|(1<<EERE);
    GPIOR0=(1<<GPIOR07)|(1<<GPIOR06)|(1<<GPIOR05)|(1<<GPIOR04)|(1<<GPIOR03)|(1<<GPIOR02)|(1<<GPIOR01)|(1<<GPIOR00);
    EIMSK=(1<<INT1)|(1<<INT0);
    EIFR=(1<<INTF1)|(1<<INTF0);
    PCIFR=(1<<PCIF2)|(1<<PCIF1)|(1<<PCIF0);
    TIFR2=(1<<OCF2B)|(1<<OCF2A)|(1<<TOV2);
    TIFR1=(1<<ICF1)|(1<<OCF1B)|(1<<OCF1A)|(1<<TOV1);
    TIFR0=(1<<OCF0B)|(1<<OCF0A)|(1<<TOV0);
    PORTD = (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5) | (1<<PB6) | (1<<PB7);
    PORTD = (1<<PORTD0) | (1<<PORTD1) | (1<<PORTD2) | (1<<PORTD3) | (1<<PORTD4) | (1<<PORTD5) | (1<<PORTD6) | (1<<PORTD7);
    DDRD = (1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3) | (1<<DDB4) | (1<<DDB5) | (1<<DDB6) | (1<<DDB7);
    PIND = (1<<PIND0) | (1<<PIND1) | (1<<PIND2) | (1<<PIND3) | (1<<PIND4) | (1<<PIND5) | (1<<PIND6) | (1<<PIND7);
    PORTC = (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5) | (1<<PB6);
    PORTC = (1<<PORTC0) | (1<<PORTC1) | (1<<PORTC2) | (1<<PORTC3) | (1<<PORTC4) | (1<<PORTC5) | (1<<PORTC6);
    DDRC = (1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3) | (1<<DDB4) | (1<<DDB5) | (1<<DDB6);
    PINC = (1<<PINC0) | (1<<PINC1) | (1<<PINC2) | (1<<PINC3) | (1<<PINC4) | (1<<PINC5) | (1<<PINC6);
    PORTB = (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4) | (1<<PB5) | (1<<PB6) | (1<<PB7);
    PORTB = (1<<PORTB0) | (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5) | (1<<PORTB6) | (1<<PORTB7);
    DDRB = (1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3) | (1<<DDB4) | (1<<DDB5) | (1<<DDB6) | (1<<DDB7);
    PINB = (1<<PINB0) | (1<<PINB1) | (1<<PINB2) | (1<<PINB3) | (1<<PINB4) | (1<<PINB5) | (1<<PINB6) | (1<<PINB7);
}

void f() {
    //portb.clear(pb0(0), pb1);
    asm("sbi 0x05,0\n cbi 0x05, 1");
    //portb.clear(pb0, ~pb1, pb2);
    // PORTB = (PORTB & ~((1<<PB0) | (1<<PB2))) | PB1;
    {
        uint8_t reg;
        asm volatile(
            "in %0, 0x05 \n"
            "andi %0, 0xf8 \n"
            "ori %0, 0x02 \n"
            "out 0x05, %0 \n"
            : "=r" (reg)
            );
    }
}

void greater_or_equal_to_0x60() {
    uint8_t v = (1<<WDE) | (1<<WDCE);
    asm("sts %0, %1" : : "n" (&WDTCSR), "r" (v));
}

#pragma once

#include "avr/io/detail/global.hpp"
#include "avr/io/pin/pxn.hpp"
#include "avr/io/register/reg.hpp"

namespace avr { namespace io {

/** All registers have a mnemonic defined by the datasheet and for
    each register there is one type with the name '{mnemonic}_t',
    where {mnemonic} is a variable with the name of the mnemonic in
    lower case, and, a global object with the name '{mnemonic}'.

    Example, the register 'WDTCR' is represented by the type 'wdtcr_t'
    and the global 'wdtcr'.

    The same pattern applies for each bit of each register. For
    example, the bit 'WDCE' from the register 'WDTCR' is represented
    by the type 'wdce_t' and the object 'wdce'.
*/

/** UDR0 0xc6 */
using udr0_t = reg<0xc6>;
using udr0_0_t = bit<udr0_t, 7>;
using udr0_1_t = bit<udr0_t, 6>;
using udr0_2_t = bit<udr0_t, 5>;
using udr0_3_t = bit<udr0_t, 4>;
using udr0_4_t = bit<udr0_t, 3>;
using udr0_5_t = bit<udr0_t, 2>;
using udr0_6_t = bit<udr0_t, 1>;
using udr0_7_t = bit<udr0_t, 0>;
AVR_IO_INLINE_GLOBAL(udr0)
AVR_IO_INLINE_GLOBAL(udr0_0)
AVR_IO_INLINE_GLOBAL(udr0_1)
AVR_IO_INLINE_GLOBAL(udr0_2)
AVR_IO_INLINE_GLOBAL(udr0_3)
AVR_IO_INLINE_GLOBAL(udr0_4)
AVR_IO_INLINE_GLOBAL(udr0_5)
AVR_IO_INLINE_GLOBAL(udr0_6)
AVR_IO_INLINE_GLOBAL(udr0_7)

/** UBRR0H 0xc5 */
using ubrr0h_t = reg<0xc5>;
using ubrr0_11_t = bit<ubrr0h_t, 3>;
using ubrr0_10_t = bit<ubrr0h_t, 2>;
using ubrr0_9_t = bit<ubrr0h_t, 1>;
using ubrr0_8_t = bit<ubrr0h_t, 0>;
AVR_IO_INLINE_GLOBAL(ubrr0h)
AVR_IO_INLINE_GLOBAL(ubrr0_11)
AVR_IO_INLINE_GLOBAL(ubrr0_10)
AVR_IO_INLINE_GLOBAL(ubrr0_9)
AVR_IO_INLINE_GLOBAL(ubrr0_8)

/** UBRR0L 0xc4 */
using ubrr0l_t = reg<0xc4>;
using ubrr0_7_t = bit<ubrr0l_t, 7>;
using ubrr0_6_t = bit<ubrr0l_t, 6>;
using ubrr0_5_t = bit<ubrr0l_t, 5>;
using ubrr0_4_t = bit<ubrr0l_t, 4>;
using ubrr0_3_t = bit<ubrr0l_t, 3>;
using ubrr0_2_t = bit<ubrr0l_t, 2>;
using ubrr0_1_t = bit<ubrr0l_t, 1>;
using ubrr0_0_t = bit<ubrr0l_t, 0>;
AVR_IO_INLINE_GLOBAL(ubrr0l)
AVR_IO_INLINE_GLOBAL(ubrr0_7)
AVR_IO_INLINE_GLOBAL(ubrr0_6)
AVR_IO_INLINE_GLOBAL(ubrr0_5)
AVR_IO_INLINE_GLOBAL(ubrr0_4)
AVR_IO_INLINE_GLOBAL(ubrr0_3)
AVR_IO_INLINE_GLOBAL(ubrr0_2)
AVR_IO_INLINE_GLOBAL(ubrr0_1)
AVR_IO_INLINE_GLOBAL(ubrr0_0)

/** UCSR0C 0xc2 */
using ucsr0c_t = reg<0xc2>;
using umsel01_t = bit<ucsr0c_t, 7>;
using umsel00_t = bit<ucsr0c_t, 6>;
using upm01_t = bit<ucsr0c_t, 5>;
using upm00_t = bit<ucsr0c_t, 4>;
using usbs0_t = bit<ucsr0c_t, 3>;
using ucsz01_t = bit<ucsr0c_t, 2>;
using udord0_t = ucsz01_t;
using ucsz00_t = bit<ucsr0c_t, 1>;
using ucpha0_t = ucsz00_t;
using ucpol0_t = bit<ucsr0c_t, 0>;
AVR_IO_INLINE_GLOBAL(ucsr0c)
AVR_IO_INLINE_GLOBAL(umsel01)
AVR_IO_INLINE_GLOBAL(umsel00)
AVR_IO_INLINE_GLOBAL(upm01)
AVR_IO_INLINE_GLOBAL(upm00)
AVR_IO_INLINE_GLOBAL(usbs0)
AVR_IO_INLINE_GLOBAL(ucsz01)
AVR_IO_INLINE_GLOBAL(udord0)
AVR_IO_INLINE_GLOBAL(ucsz00)
AVR_IO_INLINE_GLOBAL(ucpha0)
AVR_IO_INLINE_GLOBAL(ucpol0)

/** UCSR0B 0xc1 */
using ucsr0b_t = reg<0xc1>;
using rxcie0_t = bit<ucsr0b_t, 7>;
using txcie0_t = bit<ucsr0b_t, 6>;
using udrie0_t = bit<ucsr0b_t, 5>;
using rxen0_t = bit<ucsr0b_t, 4>;
using txen0_t = bit<ucsr0b_t, 3>;
using ucsz02_t = bit<ucsr0b_t, 2>;
using rxb80_t = bit<ucsr0b_t, 1>;
using txb80_t = bit<ucsr0b_t, 0>;
AVR_IO_INLINE_GLOBAL(ucsr0b)
AVR_IO_INLINE_GLOBAL(rxcie0)
AVR_IO_INLINE_GLOBAL(txcie0)
AVR_IO_INLINE_GLOBAL(udrie0)
AVR_IO_INLINE_GLOBAL(rxen0)
AVR_IO_INLINE_GLOBAL(txen0)
AVR_IO_INLINE_GLOBAL(ucsz02)
AVR_IO_INLINE_GLOBAL(rxb80)
AVR_IO_INLINE_GLOBAL(txb80)

/** UCSR0A 0xc0 */
using ucsr0a_t = reg<0xc0>;
using rxc0_t = bit<ucsr0a_t, 7>;
using txc0_t = bit<ucsr0a_t, 6>;
using udre0_t = bit<ucsr0a_t, 5>;
using fe0_t = bit<ucsr0a_t, 4>;
using dor0_t = bit<ucsr0a_t, 3>;
using upe0_t = bit<ucsr0a_t, 2>;
using u2x0_t = bit<ucsr0a_t, 1>;
using mpcm0_t = bit<ucsr0a_t, 0>;
AVR_IO_INLINE_GLOBAL(ucsr0a)
AVR_IO_INLINE_GLOBAL(rxc0)
AVR_IO_INLINE_GLOBAL(txc0)
AVR_IO_INLINE_GLOBAL(udre0)
AVR_IO_INLINE_GLOBAL(fe0)
AVR_IO_INLINE_GLOBAL(dor0)
AVR_IO_INLINE_GLOBAL(upe0)
AVR_IO_INLINE_GLOBAL(u2x0)
AVR_IO_INLINE_GLOBAL(mpcm0)

/** TWAMR 0xbd */
using twamr_t = reg<0xbd>;
using twam6_t = bit<twamr_t, 6>;
using twam5_t = bit<twamr_t, 5>;
using twam4_t = bit<twamr_t, 4>;
using twam3_t = bit<twamr_t, 3>;
using twam2_t = bit<twamr_t, 2>;
using twam1_t = bit<twamr_t, 1>;
using twam0_t = bit<twamr_t, 0>;
AVR_IO_INLINE_GLOBAL(twamr)
AVR_IO_INLINE_GLOBAL(twam6)
AVR_IO_INLINE_GLOBAL(twam5)
AVR_IO_INLINE_GLOBAL(twam4)
AVR_IO_INLINE_GLOBAL(twam3)
AVR_IO_INLINE_GLOBAL(twam2)
AVR_IO_INLINE_GLOBAL(twam1)
AVR_IO_INLINE_GLOBAL(twam0)

/** TWCR 0xbc */
using twcr_t = reg<0xbc>;
using twint_t = bit<twcr_t, 7>;
using twea_t = bit<twcr_t, 6>;
using twsta_t = bit<twcr_t, 5>;
using twsto_t = bit<twcr_t, 4>;
using twwc_t = bit<twcr_t, 3>;
using twen_t = bit<twcr_t, 2>;
using twie_t = bit<twcr_t, 0>;
AVR_IO_INLINE_GLOBAL(twcr)
AVR_IO_INLINE_GLOBAL(twint)
AVR_IO_INLINE_GLOBAL(twea)
AVR_IO_INLINE_GLOBAL(twsta)
AVR_IO_INLINE_GLOBAL(twsto)
AVR_IO_INLINE_GLOBAL(twwc)
AVR_IO_INLINE_GLOBAL(twen)
AVR_IO_INLINE_GLOBAL(twie)

/** TWDR 0xbb */
using twdr_t = reg<0xbb>;
using twd7_t = bit<twdr_t, 7>;
using twd6_t = bit<twdr_t, 6>;
using twd5_t = bit<twdr_t, 5>;
using twd4_t = bit<twdr_t, 4>;
using twd3_t = bit<twdr_t, 3>;
using twd2_t = bit<twdr_t, 2>;
using twd1_t = bit<twdr_t, 1>;
using twd0_t = bit<twdr_t, 0>;
AVR_IO_INLINE_GLOBAL(twdr)
AVR_IO_INLINE_GLOBAL(twd7)
AVR_IO_INLINE_GLOBAL(twd6)
AVR_IO_INLINE_GLOBAL(twd5)
AVR_IO_INLINE_GLOBAL(twd4)
AVR_IO_INLINE_GLOBAL(twd3)
AVR_IO_INLINE_GLOBAL(twd2)
AVR_IO_INLINE_GLOBAL(twd1)
AVR_IO_INLINE_GLOBAL(twd0)

/** TWAR 0xba */
using twar_t = reg<0xba>;
using twa6_t = bit<twar_t, 7>;
using twa5_t = bit<twar_t, 6>;
using twa4_t = bit<twar_t, 5>;
using twa3_t = bit<twar_t, 4>;
using twa2_t = bit<twar_t, 3>;
using twa1_t = bit<twar_t, 2>;
using twa0_t = bit<twar_t, 1>;
using twgce_t = bit<twar_t, 0>;
AVR_IO_INLINE_GLOBAL(twar)
AVR_IO_INLINE_GLOBAL(twa6)
AVR_IO_INLINE_GLOBAL(twa5)
AVR_IO_INLINE_GLOBAL(twa4)
AVR_IO_INLINE_GLOBAL(twa3)
AVR_IO_INLINE_GLOBAL(twa2)
AVR_IO_INLINE_GLOBAL(twa1)
AVR_IO_INLINE_GLOBAL(twa0)
AVR_IO_INLINE_GLOBAL(twgce)

/** TWSR 0xb9 */
using twsr_t = reg<0xb9>;
using tws7_t = bit<twsr_t, 7>;
using tws6_t = bit<twsr_t, 6>;
using tws5_t = bit<twsr_t, 5>;
using tws4_t = bit<twsr_t, 4>;
using tws3_t = bit<twsr_t, 3>;
using twps1_t = bit<twsr_t, 1>;
using twps0_t = bit<twsr_t, 0>;
AVR_IO_INLINE_GLOBAL(twsr)
AVR_IO_INLINE_GLOBAL(tws7)
AVR_IO_INLINE_GLOBAL(tws6)
AVR_IO_INLINE_GLOBAL(tws5)
AVR_IO_INLINE_GLOBAL(tws4)
AVR_IO_INLINE_GLOBAL(tws3)
AVR_IO_INLINE_GLOBAL(twps1)
AVR_IO_INLINE_GLOBAL(twps0)

/** TWBR 0xb8 */
using twbr_t = reg<0xb8>;
using twbr7_t = bit<twbr_t, 7>;
using twbr6_t = bit<twbr_t, 6>;
using twbr5_t = bit<twbr_t, 5>;
using twbr4_t = bit<twbr_t, 4>;
using twbr3_t = bit<twbr_t, 3>;
using twbr2_t = bit<twbr_t, 2>;
using twbr1_t = bit<twbr_t, 1>;
using twbr0_t = bit<twbr_t, 0>;
AVR_IO_INLINE_GLOBAL(twbr)
AVR_IO_INLINE_GLOBAL(twbr7)
AVR_IO_INLINE_GLOBAL(twbr6)
AVR_IO_INLINE_GLOBAL(twbr5)
AVR_IO_INLINE_GLOBAL(twbr4)
AVR_IO_INLINE_GLOBAL(twbr3)
AVR_IO_INLINE_GLOBAL(twbr2)
AVR_IO_INLINE_GLOBAL(twbr1)
AVR_IO_INLINE_GLOBAL(twbr0)

/** ASSR 0xb6 */
using assr_t = reg<0xb6>;
using exclk_t = bit<assr_t, 6>;
using as2_t = bit<assr_t, 5>;
using tcn2ub_t = bit<assr_t, 4>;
using ocr2aub_t = bit<assr_t, 3>;
using ocr2bub_t = bit<assr_t, 2>;
using tcr2aub_t = bit<assr_t, 1>;
using tcr2bub_t = bit<assr_t, 0>;
AVR_IO_INLINE_GLOBAL(assr)
AVR_IO_INLINE_GLOBAL(exclk)
AVR_IO_INLINE_GLOBAL(as2)
AVR_IO_INLINE_GLOBAL(tcn2ub)
AVR_IO_INLINE_GLOBAL(ocr2aub)
AVR_IO_INLINE_GLOBAL(ocr2bub)
AVR_IO_INLINE_GLOBAL(tcr2aub)
AVR_IO_INLINE_GLOBAL(tcr2bub)

/** OCR2B 0xb4 */
using ocr2b_t = reg<0xb4>;
using ocr2b_7_t = bit<ocr2b_t, 7>;
using ocr2b_6_t = bit<ocr2b_t, 6>;
using ocr2b_5_t = bit<ocr2b_t, 5>;
using ocr2b_4_t = bit<ocr2b_t, 4>;
using ocr2b_3_t = bit<ocr2b_t, 3>;
using ocr2b_2_t = bit<ocr2b_t, 2>;
using ocr2b_1_t = bit<ocr2b_t, 1>;
using ocr2b_0_t = bit<ocr2b_t, 0>;
AVR_IO_INLINE_GLOBAL(ocr2b)
AVR_IO_INLINE_GLOBAL(ocr2b_7)
AVR_IO_INLINE_GLOBAL(ocr2b_6)
AVR_IO_INLINE_GLOBAL(ocr2b_5)
AVR_IO_INLINE_GLOBAL(ocr2b_4)
AVR_IO_INLINE_GLOBAL(ocr2b_3)
AVR_IO_INLINE_GLOBAL(ocr2b_2)
AVR_IO_INLINE_GLOBAL(ocr2b_1)
AVR_IO_INLINE_GLOBAL(ocr2b_0)

/** OCR2A 0xb3 */
using ocr2a_t = reg<0xb3>;
using ocr2a_7_t = bit<ocr2a_t, 7>;
using ocr2a_6_t = bit<ocr2a_t, 6>;
using ocr2a_5_t = bit<ocr2a_t, 5>;
using ocr2a_4_t = bit<ocr2a_t, 4>;
using ocr2a_3_t = bit<ocr2a_t, 3>;
using ocr2a_2_t = bit<ocr2a_t, 2>;
using ocr2a_1_t = bit<ocr2a_t, 1>;
using ocr2a_0_t = bit<ocr2a_t, 0>;
AVR_IO_INLINE_GLOBAL(ocr2a)
AVR_IO_INLINE_GLOBAL(ocr2a_7)
AVR_IO_INLINE_GLOBAL(ocr2a_6)
AVR_IO_INLINE_GLOBAL(ocr2a_5)
AVR_IO_INLINE_GLOBAL(ocr2a_4)
AVR_IO_INLINE_GLOBAL(ocr2a_3)
AVR_IO_INLINE_GLOBAL(ocr2a_2)
AVR_IO_INLINE_GLOBAL(ocr2a_1)
AVR_IO_INLINE_GLOBAL(ocr2a_0)

/** TCNT2 0xb2 */
using tcnt2_t = reg<0xb2>;
using tcnt2_7_t = bit<tcnt2_t, 7>;
using tcnt2_6_t = bit<tcnt2_t, 6>;
using tcnt2_5_t = bit<tcnt2_t, 5>;
using tcnt2_4_t = bit<tcnt2_t, 4>;
using tcnt2_3_t = bit<tcnt2_t, 3>;
using tcnt2_2_t = bit<tcnt2_t, 2>;
using tcnt2_1_t = bit<tcnt2_t, 1>;
using tcnt2_0_t = bit<tcnt2_t, 0>;
AVR_IO_INLINE_GLOBAL(tcnt2)
AVR_IO_INLINE_GLOBAL(tcnt2_7)
AVR_IO_INLINE_GLOBAL(tcnt2_6)
AVR_IO_INLINE_GLOBAL(tcnt2_5)
AVR_IO_INLINE_GLOBAL(tcnt2_4)
AVR_IO_INLINE_GLOBAL(tcnt2_3)
AVR_IO_INLINE_GLOBAL(tcnt2_2)
AVR_IO_INLINE_GLOBAL(tcnt2_1)
AVR_IO_INLINE_GLOBAL(tcnt2_0)

/** TCCR2B 0xb1 */
using tccr2b_t = reg<0xb1>;
using foc2a_t = bit<tccr2b_t, 7>;
using foc2b_t = bit<tccr2b_t, 6>;
using wgm22_t = bit<tccr2b_t, 3>;
using cs22_t = bit<tccr2b_t, 2>;
using cs21_t = bit<tccr2b_t, 1>;
using cs20_t = bit<tccr2b_t, 0>;
AVR_IO_INLINE_GLOBAL(tccr2b)
AVR_IO_INLINE_GLOBAL(foc2a)
AVR_IO_INLINE_GLOBAL(foc2b)
AVR_IO_INLINE_GLOBAL(wgm22)
AVR_IO_INLINE_GLOBAL(cs22)
AVR_IO_INLINE_GLOBAL(cs21)
AVR_IO_INLINE_GLOBAL(cs20)

/** OCR1BH 0x8b */
using ocr1bh_t = reg<0x8b>;
using ocr1b_15_t = bit<ocr1bh_t, 7>;
using ocr1b_14_t = bit<ocr1bh_t, 6>;
using ocr1b_13_t = bit<ocr1bh_t, 5>;
using ocr1b_12_t = bit<ocr1bh_t, 4>;
using ocr1b_11_t = bit<ocr1bh_t, 3>;
using ocr1b_10_t = bit<ocr1bh_t, 2>;
using ocr1b_9_t = bit<ocr1bh_t, 1>;
using ocr1b_8_t = bit<ocr1bh_t, 0>;
AVR_IO_INLINE_GLOBAL(ocr1bh)
AVR_IO_INLINE_GLOBAL(ocr1b_15)
AVR_IO_INLINE_GLOBAL(ocr1b_14)
AVR_IO_INLINE_GLOBAL(ocr1b_13)
AVR_IO_INLINE_GLOBAL(ocr1b_12)
AVR_IO_INLINE_GLOBAL(ocr1b_11)
AVR_IO_INLINE_GLOBAL(ocr1b_10)
AVR_IO_INLINE_GLOBAL(ocr1b_9)
AVR_IO_INLINE_GLOBAL(ocr1b_8)

/** OCR1BL 0x8a */
using ocr1bl_t = reg<0x8a>;
using ocr1b_7_t = bit<ocr1bl_t, 7>;
using ocr1b_6_t = bit<ocr1bl_t, 6>;
using ocr1b_5_t = bit<ocr1bl_t, 5>;
using ocr1b_4_t = bit<ocr1bl_t, 4>;
using ocr1b_3_t = bit<ocr1bl_t, 3>;
using ocr1b_2_t = bit<ocr1bl_t, 2>;
using ocr1b_1_t = bit<ocr1bl_t, 1>;
using ocr1b_0_t = bit<ocr1bl_t, 0>;
AVR_IO_INLINE_GLOBAL(ocr1bl)
AVR_IO_INLINE_GLOBAL(ocr1b_7)
AVR_IO_INLINE_GLOBAL(ocr1b_6)
AVR_IO_INLINE_GLOBAL(ocr1b_5)
AVR_IO_INLINE_GLOBAL(ocr1b_4)
AVR_IO_INLINE_GLOBAL(ocr1b_3)
AVR_IO_INLINE_GLOBAL(ocr1b_2)
AVR_IO_INLINE_GLOBAL(ocr1b_1)
AVR_IO_INLINE_GLOBAL(ocr1b_0)

/** OCR1AH 0x89 */
using ocr1ah_t = reg<0x89>;
using ocr1a_15_t = bit<ocr1ah_t, 7>;
using ocr1a_14_t = bit<ocr1ah_t, 6>;
using ocr1a_13_t = bit<ocr1ah_t, 5>;
using ocr1a_12_t = bit<ocr1ah_t, 4>;
using ocr1a_11_t = bit<ocr1ah_t, 3>;
using ocr1a_10_t = bit<ocr1ah_t, 2>;
using ocr1a_9_t = bit<ocr1ah_t, 1>;
using ocr1a_8_t = bit<ocr1ah_t, 0>;
AVR_IO_INLINE_GLOBAL(ocr1ah)
AVR_IO_INLINE_GLOBAL(ocr1a_15)
AVR_IO_INLINE_GLOBAL(ocr1a_14)
AVR_IO_INLINE_GLOBAL(ocr1a_13)
AVR_IO_INLINE_GLOBAL(ocr1a_12)
AVR_IO_INLINE_GLOBAL(ocr1a_11)
AVR_IO_INLINE_GLOBAL(ocr1a_10)
AVR_IO_INLINE_GLOBAL(ocr1a_9)
AVR_IO_INLINE_GLOBAL(ocr1a_8)

/** OCR1AL 0x88 */
using ocr1al_t = reg<0x88>;
using ocr1a_7_t = bit<ocr1al_t, 7>;
using ocr1a_6_t = bit<ocr1al_t, 6>;
using ocr1a_5_t = bit<ocr1al_t, 5>;
using ocr1a_4_t = bit<ocr1al_t, 4>;
using ocr1a_3_t = bit<ocr1al_t, 3>;
using ocr1a_2_t = bit<ocr1al_t, 2>;
using ocr1a_1_t = bit<ocr1al_t, 1>;
using ocr1a_0_t = bit<ocr1al_t, 0>;
AVR_IO_INLINE_GLOBAL(ocr1al)
AVR_IO_INLINE_GLOBAL(ocr1a_7)
AVR_IO_INLINE_GLOBAL(ocr1a_6)
AVR_IO_INLINE_GLOBAL(ocr1a_5)
AVR_IO_INLINE_GLOBAL(ocr1a_4)
AVR_IO_INLINE_GLOBAL(ocr1a_3)
AVR_IO_INLINE_GLOBAL(ocr1a_2)
AVR_IO_INLINE_GLOBAL(ocr1a_1)
AVR_IO_INLINE_GLOBAL(ocr1a_0)

/** ICR1H 0x89 */
using icr1h_t = reg<0x87>;
using icr1_15_t = bit<icr1h_t, 7>;
using icr1_14_t = bit<icr1h_t, 6>;
using icr1_13_t = bit<icr1h_t, 5>;
using icr1_12_t = bit<icr1h_t, 4>;
using icr1_11_t = bit<icr1h_t, 3>;
using icr1_10_t = bit<icr1h_t, 2>;
using icr1_9_t = bit<icr1h_t, 1>;
using icr1_8_t = bit<icr1h_t, 0>;
AVR_IO_INLINE_GLOBAL(icr1h)
AVR_IO_INLINE_GLOBAL(icr1_15)
AVR_IO_INLINE_GLOBAL(icr1_14)
AVR_IO_INLINE_GLOBAL(icr1_13)
AVR_IO_INLINE_GLOBAL(icr1_12)
AVR_IO_INLINE_GLOBAL(icr1_11)
AVR_IO_INLINE_GLOBAL(icr1_10)
AVR_IO_INLINE_GLOBAL(icr1_9)
AVR_IO_INLINE_GLOBAL(icr1_8)

/** ICR1L 0x88 */
using icr1l_t = reg<0x86>;
using icr1_7_t = bit<icr1l_t, 7>;
using icr1_6_t = bit<icr1l_t, 6>;
using icr1_5_t = bit<icr1l_t, 5>;
using icr1_4_t = bit<icr1l_t, 4>;
using icr1_3_t = bit<icr1l_t, 3>;
using icr1_2_t = bit<icr1l_t, 2>;
using icr1_1_t = bit<icr1l_t, 1>;
using icr1_0_t = bit<icr1l_t, 0>;
AVR_IO_INLINE_GLOBAL(icr1l)
AVR_IO_INLINE_GLOBAL(icr1_7)
AVR_IO_INLINE_GLOBAL(icr1_6)
AVR_IO_INLINE_GLOBAL(icr1_5)
AVR_IO_INLINE_GLOBAL(icr1_4)
AVR_IO_INLINE_GLOBAL(icr1_3)
AVR_IO_INLINE_GLOBAL(icr1_2)
AVR_IO_INLINE_GLOBAL(icr1_1)
AVR_IO_INLINE_GLOBAL(icr1_0)

/** TCNT1H 0x85 */
using tcnt1h_t = reg<0x85>;
using tcnt1_15_t = bit<tcnt1h_t, 7>;
using tcnt1_14_t = bit<tcnt1h_t, 6>;
using tcnt1_13_t = bit<tcnt1h_t, 5>;
using tcnt1_12_t = bit<tcnt1h_t, 4>;
using tcnt1_11_t = bit<tcnt1h_t, 3>;
using tcnt1_10_t = bit<tcnt1h_t, 2>;
using tcnt1_9_t = bit<tcnt1h_t, 1>;
using tcnt1_8_t = bit<tcnt1h_t, 0>;
AVR_IO_INLINE_GLOBAL(tcnt1h)
AVR_IO_INLINE_GLOBAL(tcnt1_15)
AVR_IO_INLINE_GLOBAL(tcnt1_14)
AVR_IO_INLINE_GLOBAL(tcnt1_13)
AVR_IO_INLINE_GLOBAL(tcnt1_12)
AVR_IO_INLINE_GLOBAL(tcnt1_11)
AVR_IO_INLINE_GLOBAL(tcnt1_10)
AVR_IO_INLINE_GLOBAL(tcnt1_9)
AVR_IO_INLINE_GLOBAL(tcnt1_8)

/** TCNT1L 0x84 */
using tcnt1l_t = reg<0x84>;
using tcnt1_7_t = bit<tcnt1l_t, 7>;
using tcnt1_6_t = bit<tcnt1l_t, 6>;
using tcnt1_5_t = bit<tcnt1l_t, 5>;
using tcnt1_4_t = bit<tcnt1l_t, 4>;
using tcnt1_3_t = bit<tcnt1l_t, 3>;
using tcnt1_2_t = bit<tcnt1l_t, 2>;
using tcnt1_1_t = bit<tcnt1l_t, 1>;
using tcnt1_0_t = bit<tcnt1l_t, 0>;
AVR_IO_INLINE_GLOBAL(tcnt1l)
AVR_IO_INLINE_GLOBAL(tcnt1_7)
AVR_IO_INLINE_GLOBAL(tcnt1_6)
AVR_IO_INLINE_GLOBAL(tcnt1_5)
AVR_IO_INLINE_GLOBAL(tcnt1_4)
AVR_IO_INLINE_GLOBAL(tcnt1_3)
AVR_IO_INLINE_GLOBAL(tcnt1_2)
AVR_IO_INLINE_GLOBAL(tcnt1_1)
AVR_IO_INLINE_GLOBAL(tcnt1_0)

/** TCCR1C 0x82 */
using tccr1c_t = reg<0x82>;
using foc1a_t = bit<tccr1c_t, 7>;
using foc1b_t = bit<tccr1c_t, 6>;
AVR_IO_INLINE_GLOBAL(tccr1c)
AVR_IO_INLINE_GLOBAL(foc1a)
AVR_IO_INLINE_GLOBAL(foc1b)

/** TCCR1B 0x81 */
using tccr1b_t = reg<0x81>;
using icnc1_t = bit<tccr1b_t, 7>;
using ices1_t = bit<tccr1b_t, 6>;
using wgm13_t = bit<tccr1b_t, 4>;
using wgm12_t = bit<tccr1b_t, 3>;
using cs12_t = bit<tccr1b_t, 2>;
using cs11_t = bit<tccr1b_t, 1>;
using cs10_t = bit<tccr1b_t, 0>;
AVR_IO_INLINE_GLOBAL(tccr1b)
AVR_IO_INLINE_GLOBAL(icnc1)
AVR_IO_INLINE_GLOBAL(ices1)
AVR_IO_INLINE_GLOBAL(wgm13)
AVR_IO_INLINE_GLOBAL(wgm12)
AVR_IO_INLINE_GLOBAL(cs12)
AVR_IO_INLINE_GLOBAL(cs11)
AVR_IO_INLINE_GLOBAL(cs10)

/** TCCR1A 0x80 */
using tccr1a_t = reg<0x80>;
using com1a1_t = bit<tccr1a_t, 7>;
using com1a0_t = bit<tccr1a_t, 6>;
using com1b1_t = bit<tccr1a_t, 5>;
using com1b0_t = bit<tccr1a_t, 4>;
using wgm11_t = bit<tccr1a_t, 1>;
using wgm10_t = bit<tccr1a_t, 0>;
AVR_IO_INLINE_GLOBAL(tccr1a)
AVR_IO_INLINE_GLOBAL(com1a1)
AVR_IO_INLINE_GLOBAL(com1a0)
AVR_IO_INLINE_GLOBAL(com1b1)
AVR_IO_INLINE_GLOBAL(com1b0)
AVR_IO_INLINE_GLOBAL(wgm11)
AVR_IO_INLINE_GLOBAL(wgm10)

/** DIDR1 0x7f */
using didr1_t = reg<0x7f>;
using ain1d_t = bit<didr1_t, 1>;
using ain0d_t = bit<didr1_t, 0>;
AVR_IO_INLINE_GLOBAL(didr1)
AVR_IO_INLINE_GLOBAL(ain1d)
AVR_IO_INLINE_GLOBAL(ain0d)

/** DIDR0 0x7e */
using didr0_t = reg<0x7e>;
using adc5d_t = bit<didr0_t, 5>;
using adc4d_t = bit<didr0_t, 4>;
using adc3d_t = bit<didr0_t, 3>;
using adc2d_t = bit<didr0_t, 2>;
using adc1d_t = bit<didr0_t, 1>;
using adc0d_t = bit<didr0_t, 0>;
AVR_IO_INLINE_GLOBAL(didr0)
AVR_IO_INLINE_GLOBAL(adc5d)
AVR_IO_INLINE_GLOBAL(adc4d)
AVR_IO_INLINE_GLOBAL(adc3d)
AVR_IO_INLINE_GLOBAL(adc2d)
AVR_IO_INLINE_GLOBAL(adc1d)
AVR_IO_INLINE_GLOBAL(adc0d)

/** ADMUX 0x7c */
using admux_t = reg<0x7c>;
using refs1_t = bit<admux_t, 7>;
using refs0_t = bit<admux_t, 6>;
using adlar_t = bit<admux_t, 5>;
using mux3_t = bit<admux_t, 3>;
using mux2_t = bit<admux_t, 2>;
using mux1_t = bit<admux_t, 1>;
using mux0_t = bit<admux_t, 0>;
AVR_IO_INLINE_GLOBAL(admux)
AVR_IO_INLINE_GLOBAL(refs1)
AVR_IO_INLINE_GLOBAL(refs0)
AVR_IO_INLINE_GLOBAL(adlar)
AVR_IO_INLINE_GLOBAL(mux3)
AVR_IO_INLINE_GLOBAL(mux2)
AVR_IO_INLINE_GLOBAL(mux1)
AVR_IO_INLINE_GLOBAL(mux0)

/** ADCSRB 0x7b */
using adcsrb_t = reg<0x7b>;
using acme_t = bit<adcsrb_t, 6>;
using adts2_t = bit<adcsrb_t, 2>;
using adts1_t = bit<adcsrb_t, 1>;
using adts0_t = bit<adcsrb_t, 0>;
AVR_IO_INLINE_GLOBAL(adcsrb)
AVR_IO_INLINE_GLOBAL(acme)
AVR_IO_INLINE_GLOBAL(adts2)
AVR_IO_INLINE_GLOBAL(adts1)
AVR_IO_INLINE_GLOBAL(adts0)

/** ADCSRA 0x7a */
using adcsra_t = reg<0x7a>;
using aden_t = bit<adcsra_t, 7>;
using adsc_t = bit<adcsra_t, 6>;
using adate_t = bit<adcsra_t, 5>;
using adif_t = bit<adcsra_t, 4>;
using adie_t = bit<adcsra_t, 3>;
using adps2_t = bit<adcsra_t, 2>;
using adps1_t = bit<adcsra_t, 1>;
using adps0_t = bit<adcsra_t, 0>;
AVR_IO_INLINE_GLOBAL(adcsra)
AVR_IO_INLINE_GLOBAL(aden)
AVR_IO_INLINE_GLOBAL(adsc)
AVR_IO_INLINE_GLOBAL(adate)
AVR_IO_INLINE_GLOBAL(adif)
AVR_IO_INLINE_GLOBAL(adie)
AVR_IO_INLINE_GLOBAL(adps2)
AVR_IO_INLINE_GLOBAL(adps1)
AVR_IO_INLINE_GLOBAL(adps0)

/** ADCH 0x79 */
using adch_t = reg<0x79>;
using adc_9_t = bit<adch_t, 1>;
using adc_8_t = bit<adch_t, 0>;
AVR_IO_INLINE_GLOBAL(adch)
AVR_IO_INLINE_GLOBAL(adc_9)
AVR_IO_INLINE_GLOBAL(adc_8)

/** ADCL 0x78 */
using adcl_t = reg<0x78>;
using adc_7_t = bit<adcl_t, 7>;
using adc_6_t = bit<adcl_t, 6>;
using adc_5_t = bit<adcl_t, 5>;
using adc_4_t = bit<adcl_t, 4>;
using adc_3_t = bit<adcl_t, 3>;
using adc_2_t = bit<adcl_t, 2>;
using adc_1_t = bit<adcl_t, 1>;
using adc_0_t = bit<adcl_t, 0>;
AVR_IO_INLINE_GLOBAL(adcl)
AVR_IO_INLINE_GLOBAL(adc_7)
AVR_IO_INLINE_GLOBAL(adc_6)
AVR_IO_INLINE_GLOBAL(adc_5)
AVR_IO_INLINE_GLOBAL(adc_4)
AVR_IO_INLINE_GLOBAL(adc_3)
AVR_IO_INLINE_GLOBAL(adc_2)
AVR_IO_INLINE_GLOBAL(adc_1)
AVR_IO_INLINE_GLOBAL(adc_0)

/** TIMSK2 0x70 */
using timsk2_t = reg<0x70>;
using ocie2b_t = bit<timsk2_t,2>;
using ocie2a_t = bit<timsk2_t,1>;
using toie2_t = bit<timsk2_t,0>;
AVR_IO_INLINE_GLOBAL(timsk2)
AVR_IO_INLINE_GLOBAL(ocie2b)
AVR_IO_INLINE_GLOBAL(ocie2a)
AVR_IO_INLINE_GLOBAL(toie2)

/** TIMSK1 0x6f */
using timsk1_t = reg<0x6f>;
using icie1_t = bit<timsk1_t,5>;
using ocie1b_t = bit<timsk1_t,2>;
using ocie1a_t = bit<timsk1_t,1>;
using toie1_t = bit<timsk1_t,0>;
AVR_IO_INLINE_GLOBAL(timsk1)
AVR_IO_INLINE_GLOBAL(icie1)
AVR_IO_INLINE_GLOBAL(ocie1b)
AVR_IO_INLINE_GLOBAL(ocie1a)
AVR_IO_INLINE_GLOBAL(toie1)

/** TIMSK0 0x6e */
using timsk0_t = reg<0x6e>;
using ocie0b_t = bit<timsk0_t,2>;
using ocie0a_t = bit<timsk0_t,1>;
using toie0_t = bit<timsk0_t,0>;
AVR_IO_INLINE_GLOBAL(timsk0)
AVR_IO_INLINE_GLOBAL(ocie0b)
AVR_IO_INLINE_GLOBAL(ocie0a)
AVR_IO_INLINE_GLOBAL(toie0)

/** PCMSK2 0x6d */
using pcmsk2_t = reg<0x6d>;
using pcint23_t = bit<pcmsk2_t, 7>;
using pcint22_t = bit<pcmsk2_t, 6>;
using pcint21_t = bit<pcmsk2_t, 5>;
using pcint20_t = bit<pcmsk2_t, 4>;
using pcint19_t = bit<pcmsk2_t, 3>;
using pcint18_t = bit<pcmsk2_t, 2>;
using pcint17_t = bit<pcmsk2_t, 1>;
using pcint16_t = bit<pcmsk2_t, 0>;
AVR_IO_INLINE_GLOBAL(pcmsk2)
AVR_IO_INLINE_GLOBAL(pcint23)
AVR_IO_INLINE_GLOBAL(pcint22)
AVR_IO_INLINE_GLOBAL(pcint21)
AVR_IO_INLINE_GLOBAL(pcint20)
AVR_IO_INLINE_GLOBAL(pcint19)
AVR_IO_INLINE_GLOBAL(pcint18)
AVR_IO_INLINE_GLOBAL(pcint17)
AVR_IO_INLINE_GLOBAL(pcint16)

/** PCMSK1 0x6c */
using pcmsk1_t = reg<0x6c>;
using pcint14_t = bit<pcmsk1_t, 6>;
using pcint13_t = bit<pcmsk1_t, 5>;
using pcint12_t = bit<pcmsk1_t, 4>;
using pcint11_t = bit<pcmsk1_t, 3>;
using pcint10_t = bit<pcmsk1_t, 2>;
using pcint9_t = bit<pcmsk1_t, 1>;
using pcint8_t = bit<pcmsk1_t, 0>;
AVR_IO_INLINE_GLOBAL(pcmsk1)
AVR_IO_INLINE_GLOBAL(pcint14)
AVR_IO_INLINE_GLOBAL(pcint13)
AVR_IO_INLINE_GLOBAL(pcint12)
AVR_IO_INLINE_GLOBAL(pcint11)
AVR_IO_INLINE_GLOBAL(pcint10)
AVR_IO_INLINE_GLOBAL(pcint9)
AVR_IO_INLINE_GLOBAL(pcint8)

/** PCMSK0 0x6b */
using pcmsk0_t = reg<0x6b>;
using pcint7_t = bit<pcmsk0_t, 7>;
using pcint6_t = bit<pcmsk0_t, 6>;
using pcint5_t = bit<pcmsk0_t, 5>;
using pcint4_t = bit<pcmsk0_t, 4>;
using pcint3_t = bit<pcmsk0_t, 3>;
using pcint2_t = bit<pcmsk0_t, 2>;
using pcint1_t = bit<pcmsk0_t, 1>;
using pcint0_t = bit<pcmsk0_t, 0>;
AVR_IO_INLINE_GLOBAL(pcmsk0)
AVR_IO_INLINE_GLOBAL(pcint7)
AVR_IO_INLINE_GLOBAL(pcint6)
AVR_IO_INLINE_GLOBAL(pcint5)
AVR_IO_INLINE_GLOBAL(pcint4)
AVR_IO_INLINE_GLOBAL(pcint3)
AVR_IO_INLINE_GLOBAL(pcint2)
AVR_IO_INLINE_GLOBAL(pcint1)
AVR_IO_INLINE_GLOBAL(pcint0)

/** EICRA 0x69 */
using eicra_t = reg<0x69>;
using isc11_t = bit<eicra_t, 3>;
using isc10_t = bit<eicra_t, 2>;
using isc01_t = bit<eicra_t, 1>;
using isc00_t = bit<eicra_t, 0>;
AVR_IO_INLINE_GLOBAL(eicra)
AVR_IO_INLINE_GLOBAL(isc11)
AVR_IO_INLINE_GLOBAL(isc10)
AVR_IO_INLINE_GLOBAL(isc01)
AVR_IO_INLINE_GLOBAL(isc00)

/** PCICR 0x68 */
using pcicr_t = reg<0x68>;
using pcie2_t = bit<pcicr_t, 2>;
using pcie1_t = bit<pcicr_t, 1>;
using pcie0_t = bit<pcicr_t, 0>;
AVR_IO_INLINE_GLOBAL(pcicr)
AVR_IO_INLINE_GLOBAL(pcie2)
AVR_IO_INLINE_GLOBAL(pcie1)
AVR_IO_INLINE_GLOBAL(pcie0)

/** OSCCAL 0x66 */
using osccal_t = reg<0x66>;
using cal7_t = bit<osccal_t,7>;
using cal6_t = bit<osccal_t,6>;
using cal5_t = bit<osccal_t,5>;
using cal4_t = bit<osccal_t,4>;
using cal3_t = bit<osccal_t,3>;
using cal2_t = bit<osccal_t,2>;
using cal1_t = bit<osccal_t,1>;
using cal0_t = bit<osccal_t,0>;
AVR_IO_INLINE_GLOBAL(osccal)
AVR_IO_INLINE_GLOBAL(cal7)
AVR_IO_INLINE_GLOBAL(cal6)
AVR_IO_INLINE_GLOBAL(cal5)
AVR_IO_INLINE_GLOBAL(cal4)
AVR_IO_INLINE_GLOBAL(cal3)
AVR_IO_INLINE_GLOBAL(cal2)
AVR_IO_INLINE_GLOBAL(cal1)
AVR_IO_INLINE_GLOBAL(cal0)

/** PRR 0x64 */
using prr_t = reg<0x64>;
using prtwi_t = bit<prr_t, 7>;
using prtim2_t = bit<prr_t, 6>;
using prtim0_t = bit<prr_t, 5>;
using prtim1_t = bit<prr_t, 3>;
using prspi_t = bit<prr_t, 2>;
using prusart0_t = bit<prr_t, 1>;
using pradc_t = bit<prr_t, 0>;
AVR_IO_INLINE_GLOBAL(prr)
AVR_IO_INLINE_GLOBAL(prtwi)
AVR_IO_INLINE_GLOBAL(prtim2)
AVR_IO_INLINE_GLOBAL(prtim0)
AVR_IO_INLINE_GLOBAL(prtim1)
AVR_IO_INLINE_GLOBAL(prspi)
AVR_IO_INLINE_GLOBAL(prusart0)
AVR_IO_INLINE_GLOBAL(pradc)

/** CLKPR 0x61 */
using clkpr_t = reg<0x61>;
using clkpce_t = bit<clkpr_t, 7>;
using clkps3_t = bit<clkpr_t, 3>;
using clkps2_t = bit<clkpr_t, 2>;
using clkps1_t = bit<clkpr_t, 1>;
using clkps0_t = bit<clkpr_t, 0>;
AVR_IO_INLINE_GLOBAL(clkpr)
AVR_IO_INLINE_GLOBAL(clkpce)
AVR_IO_INLINE_GLOBAL(clkps3)
AVR_IO_INLINE_GLOBAL(clkps2)
AVR_IO_INLINE_GLOBAL(clkps1)
AVR_IO_INLINE_GLOBAL(clkps0)

/** WDTCSR 0x60 */
using wdtcsr_t = reg<0x60>;
using wdif_t = bit<wdtcsr_t, 7>;
using wdie_t = bit<wdtcsr_t, 6>;
using wdp3_t = bit<wdtcsr_t, 5>;
using wdce_t = bit<wdtcsr_t, 4>;
using wde_t = bit<wdtcsr_t, 3>;
using wdp2_t = bit<wdtcsr_t, 2>;
using wdp1_t = bit<wdtcsr_t, 1>;
using wdp0_t = bit<wdtcsr_t, 0>;
AVR_IO_INLINE_GLOBAL(wdtcsr)
AVR_IO_INLINE_GLOBAL(wdif)
AVR_IO_INLINE_GLOBAL(wdie)
AVR_IO_INLINE_GLOBAL(wdp3)
AVR_IO_INLINE_GLOBAL(wdce)
AVR_IO_INLINE_GLOBAL(wde)
AVR_IO_INLINE_GLOBAL(wdp2)
AVR_IO_INLINE_GLOBAL(wdp1)
AVR_IO_INLINE_GLOBAL(wdp0)

#define AVR_IO_WDT_HAS_WDRF 1
#define AVR_IO_WDT_HAS_WDP3 1
#define AVR_IO_WDT_HAS_INTERRUPT_MODE 1
#define AVR_IO_WDT_NEEDS_ON_TIMED_SEQ 1
#define AVR_IO_WDT_NEEDS_OFF_TIMED_SEQ 1

/** SREG 0x3f */
using _sreg = reg<0x3f + 0x20>;
using sreg_i_t = bit<_sreg, 7>;
using sreg_t_t = bit<_sreg, 6>;
using sreg_h_t = bit<_sreg, 5>;
using sreg_s_t = bit<_sreg, 4>;
using sreg_v_t = bit<_sreg, 3>;
using sreg_n_t = bit<_sreg, 2>;
using sreg_z_t = bit<_sreg, 1>;
using sreg_c_t = bit<_sreg, 0>;
AVR_IO_INLINE_GLOBAL_T(_sreg, sreg)
AVR_IO_INLINE_GLOBAL(sreg_i)
AVR_IO_INLINE_GLOBAL(sreg_t)
AVR_IO_INLINE_GLOBAL(sreg_h)
AVR_IO_INLINE_GLOBAL(sreg_s)
AVR_IO_INLINE_GLOBAL(sreg_v)
AVR_IO_INLINE_GLOBAL(sreg_n)
AVR_IO_INLINE_GLOBAL(sreg_z)
AVR_IO_INLINE_GLOBAL(sreg_c)

/** SPH 0x3e */
using sph_t = reg<0x3e + 0x20>;
using sp10_t = bit<sph_t, 2>;
using sp9_t = bit<sph_t, 1>;
using sp8_t = bit<sph_t, 0>;
AVR_IO_INLINE_GLOBAL(sph)
AVR_IO_INLINE_GLOBAL(sp10)
AVR_IO_INLINE_GLOBAL(sp9)
AVR_IO_INLINE_GLOBAL(sp8)

/** SPL 0x3d */
using spl_t = reg<0x3d + 0x20>;
using sp7_t = bit<spl_t, 7>;
using sp6_t = bit<spl_t, 6>;
using sp5_t = bit<spl_t, 5>;
using sp4_t = bit<spl_t, 4>;
using sp3_t = bit<spl_t, 3>;
using sp2_t = bit<spl_t, 2>;
using sp1_t = bit<spl_t, 1>;
using sp0_t = bit<spl_t, 0>;
AVR_IO_INLINE_GLOBAL(spl)
AVR_IO_INLINE_GLOBAL(sp7)
AVR_IO_INLINE_GLOBAL(sp6)
AVR_IO_INLINE_GLOBAL(sp5)
AVR_IO_INLINE_GLOBAL(sp4)
AVR_IO_INLINE_GLOBAL(sp3)
AVR_IO_INLINE_GLOBAL(sp2)
AVR_IO_INLINE_GLOBAL(sp1)
AVR_IO_INLINE_GLOBAL(sp0)

/** SPMCSR 0x37 */
using spmcsr_t = reg<0x37 + 0x20>;
using spmie_t = bit<spmcsr_t,7>;
using rwwsb_t = bit<spmcsr_t,6>;
using rwwsre_t = bit<spmcsr_t,4>;
using blbset_t = bit<spmcsr_t,3>;
using pgwrt_t = bit<spmcsr_t,2>;
using pgers_t = bit<spmcsr_t,1>;
using selfprgen_t = bit<spmcsr_t,0>;
AVR_IO_INLINE_GLOBAL(spmcsr)
AVR_IO_INLINE_GLOBAL(spmie)
AVR_IO_INLINE_GLOBAL(rwwsb)
AVR_IO_INLINE_GLOBAL(rwwsre)
AVR_IO_INLINE_GLOBAL(blbset)
AVR_IO_INLINE_GLOBAL(pgwrt)
AVR_IO_INLINE_GLOBAL(pgers)
AVR_IO_INLINE_GLOBAL(selfprgen)

/** MCUCR 0x35 */
using mcucr_t = reg<0x35 + 0x20>;
using bods_t = bit<mcucr_t, 6>;
using bodse_t = bit<mcucr_t, 5>;
using pud_t = bit<mcucr_t, 4>;
using ivsel_t = bit<mcucr_t, 1>;
using ivce_t = bit<mcucr_t, 0>;
AVR_IO_INLINE_GLOBAL(mcucr)
AVR_IO_INLINE_GLOBAL(bods)
AVR_IO_INLINE_GLOBAL(bodse)
AVR_IO_INLINE_GLOBAL(pud)
AVR_IO_INLINE_GLOBAL(ivsel)
AVR_IO_INLINE_GLOBAL(ivce)

/** MCUSR 0x34 */
using mcusr_t = reg<0x34 + 0x20>;
using wdrf_t = bit<mcusr_t, 3>;
using borf_t = bit<mcusr_t, 2>;
using extrf_t = bit<mcusr_t, 1>;
using porf_t = bit<mcusr_t, 0>;
AVR_IO_INLINE_GLOBAL(mcusr)
AVR_IO_INLINE_GLOBAL(wdrf)
AVR_IO_INLINE_GLOBAL(borf)
AVR_IO_INLINE_GLOBAL(extrf)
AVR_IO_INLINE_GLOBAL(porf)

/** SMCR 0x33 */
using smcr_t = reg<0x33 + 0x20>;
using sm2_t = bit<smcr_t, 3>;
using sm1_t = bit<smcr_t, 2>;
using sm0_t = bit<smcr_t, 1>;
using se_t = bit<smcr_t, 0>;
AVR_IO_INLINE_GLOBAL(smcr)
AVR_IO_INLINE_GLOBAL(sm2)
AVR_IO_INLINE_GLOBAL(sm1)
AVR_IO_INLINE_GLOBAL(sm0)
AVR_IO_INLINE_GLOBAL(se)

/** ACSR 0x30 */
using acsr_t = reg<0x30 + 0x20>;
using acd_t = bit<acsr_t, 7>;
using acbg_t = bit<acsr_t, 6>;
using aco_t = bit<acsr_t, 5>;
using aci_t = bit<acsr_t, 4>;
using acie_t = bit<acsr_t, 3>;
using acic_t = bit<acsr_t, 2>;
using acis1_t = bit<acsr_t, 1>;
using acis0_t = bit<acsr_t, 0>;
AVR_IO_INLINE_GLOBAL(acsr)
AVR_IO_INLINE_GLOBAL(acd)
AVR_IO_INLINE_GLOBAL(acbg)
AVR_IO_INLINE_GLOBAL(aco)
AVR_IO_INLINE_GLOBAL(aci)
AVR_IO_INLINE_GLOBAL(acie)
AVR_IO_INLINE_GLOBAL(acic)
AVR_IO_INLINE_GLOBAL(acis1)
AVR_IO_INLINE_GLOBAL(acis0)

/** SPDR 0x2e */
using spdr_t = reg<0x2e + 0x20>;
using spdr7_t = bit<spdr_t, 7>;
using spdr6_t = bit<spdr_t, 6>;
using spdr5_t = bit<spdr_t, 5>;
using spdr4_t = bit<spdr_t, 4>;
using spdr3_t = bit<spdr_t, 3>;
using spdr2_t = bit<spdr_t, 2>;
using spdr1_t = bit<spdr_t, 1>;
using spdr0_t = bit<spdr_t, 0>;
AVR_IO_INLINE_GLOBAL(spdr)
AVR_IO_INLINE_GLOBAL(spdr7)
AVR_IO_INLINE_GLOBAL(spdr6)
AVR_IO_INLINE_GLOBAL(spdr5)
AVR_IO_INLINE_GLOBAL(spdr4)
AVR_IO_INLINE_GLOBAL(spdr3)
AVR_IO_INLINE_GLOBAL(spdr2)
AVR_IO_INLINE_GLOBAL(spdr1)
AVR_IO_INLINE_GLOBAL(spdr0)

/** SPSR 0x2d */
using spsr_t = reg<0x2d + 0x20>;
using spif_t = bit<spsr_t, 7>;
using wcol_t = bit<spsr_t, 6>;
using spi2x_t = bit<spsr_t, 0>;
AVR_IO_INLINE_GLOBAL(spsr)
AVR_IO_INLINE_GLOBAL(spif)
AVR_IO_INLINE_GLOBAL(wcol)
AVR_IO_INLINE_GLOBAL(spi2x)

/** SPCR 0x2c */
using spcr_t = reg<0x2c + 0x20>;
using spie_t = bit<spcr_t, 7>;
using spe_t = bit<spcr_t, 6>;
using dord_t = bit<spcr_t, 5>;
using mstr_t = bit<spcr_t, 4>;
using cpol_t = bit<spcr_t, 3>;
using cpha_t = bit<spcr_t, 2>;
using spr1_t = bit<spcr_t, 1>;
using spr0_t = bit<spcr_t, 0>;
AVR_IO_INLINE_GLOBAL(spcr)
AVR_IO_INLINE_GLOBAL(spie)
AVR_IO_INLINE_GLOBAL(spe)
AVR_IO_INLINE_GLOBAL(dord)
AVR_IO_INLINE_GLOBAL(mstr)
AVR_IO_INLINE_GLOBAL(cpol)
AVR_IO_INLINE_GLOBAL(cpha)
AVR_IO_INLINE_GLOBAL(spr1)
AVR_IO_INLINE_GLOBAL(spr0)

/** GPIOR2 0x2b */
using gpior2_t = reg<0x2b + 0x20>;
using gpior2_7_t = bit<gpior2_t, 7>;
using gpior2_6_t = bit<gpior2_t, 6>;
using gpior2_5_t = bit<gpior2_t, 5>;
using gpior2_4_t = bit<gpior2_t, 4>;
using gpior2_3_t = bit<gpior2_t, 3>;
using gpior2_2_t = bit<gpior2_t, 2>;
using gpior2_1_t = bit<gpior2_t, 1>;
using gpior2_0_t = bit<gpior2_t, 0>;
AVR_IO_INLINE_GLOBAL(gpior2)
AVR_IO_INLINE_GLOBAL(gpior2_7)
AVR_IO_INLINE_GLOBAL(gpior2_6)
AVR_IO_INLINE_GLOBAL(gpior2_5)
AVR_IO_INLINE_GLOBAL(gpior2_4)
AVR_IO_INLINE_GLOBAL(gpior2_3)
AVR_IO_INLINE_GLOBAL(gpior2_2)
AVR_IO_INLINE_GLOBAL(gpior2_1)
AVR_IO_INLINE_GLOBAL(gpior2_0)

/** GPIOR1 0x2a */
using gpior1_t = reg<0x2a + 0x20>;
using gpior1_7_t = bit<gpior1_t, 7>;
using gpior1_6_t = bit<gpior1_t, 6>;
using gpior1_5_t = bit<gpior1_t, 5>;
using gpior1_4_t = bit<gpior1_t, 4>;
using gpior1_3_t = bit<gpior1_t, 3>;
using gpior1_2_t = bit<gpior1_t, 2>;
using gpior1_1_t = bit<gpior1_t, 1>;
using gpior1_0_t = bit<gpior1_t, 0>;
AVR_IO_INLINE_GLOBAL(gpior1)
AVR_IO_INLINE_GLOBAL(gpior1_7)
AVR_IO_INLINE_GLOBAL(gpior1_6)
AVR_IO_INLINE_GLOBAL(gpior1_5)
AVR_IO_INLINE_GLOBAL(gpior1_4)
AVR_IO_INLINE_GLOBAL(gpior1_3)
AVR_IO_INLINE_GLOBAL(gpior1_2)
AVR_IO_INLINE_GLOBAL(gpior1_1)
AVR_IO_INLINE_GLOBAL(gpior1_0)

/** OCR0B 0x28 */
using ocr0b_t = reg<0x28 + 0x20>;
using ocr0b7_t = bit<ocr0b_t,7>;
using ocr0b6_t = bit<ocr0b_t,6>;
using ocr0b5_t = bit<ocr0b_t,5>;
using ocr0b4_t = bit<ocr0b_t,4>;
using ocr0b3_t = bit<ocr0b_t,3>;
using ocr0b2_t = bit<ocr0b_t,2>;
using ocr0b1_t = bit<ocr0b_t,1>;
using ocr0b0_t = bit<ocr0b_t,0>;
AVR_IO_INLINE_GLOBAL(ocr0b)
AVR_IO_INLINE_GLOBAL(ocr0b7)
AVR_IO_INLINE_GLOBAL(ocr0b6)
AVR_IO_INLINE_GLOBAL(ocr0b5)
AVR_IO_INLINE_GLOBAL(ocr0b4)
AVR_IO_INLINE_GLOBAL(ocr0b3)
AVR_IO_INLINE_GLOBAL(ocr0b2)
AVR_IO_INLINE_GLOBAL(ocr0b1)
AVR_IO_INLINE_GLOBAL(ocr0b0)

/** OCR0A 0x27 */
using ocr0a_t = reg<0x27 + 0x20>;
using ocr0a7_t = bit<ocr0a_t,7>;
using ocr0a6_t = bit<ocr0a_t,6>;
using ocr0a5_t = bit<ocr0a_t,5>;
using ocr0a4_t = bit<ocr0a_t,4>;
using ocr0a3_t = bit<ocr0a_t,3>;
using ocr0a2_t = bit<ocr0a_t,2>;
using ocr0a1_t = bit<ocr0a_t,1>;
using ocr0a0_t = bit<ocr0a_t,0>;
AVR_IO_INLINE_GLOBAL(ocr0a)
AVR_IO_INLINE_GLOBAL(ocr0a7)
AVR_IO_INLINE_GLOBAL(ocr0a6)
AVR_IO_INLINE_GLOBAL(ocr0a5)
AVR_IO_INLINE_GLOBAL(ocr0a4)
AVR_IO_INLINE_GLOBAL(ocr0a3)
AVR_IO_INLINE_GLOBAL(ocr0a2)
AVR_IO_INLINE_GLOBAL(ocr0a1)
AVR_IO_INLINE_GLOBAL(ocr0a0)

/** TCNT0 0x26 */
using tcnt0_t = reg<0x26 + 0x20>;
using tcnt0_7_t = bit<tcnt0_t, 7>;
using tcnt0_6_t = bit<tcnt0_t, 6>;
using tcnt0_5_t = bit<tcnt0_t, 5>;
using tcnt0_4_t = bit<tcnt0_t, 4>;
using tcnt0_3_t = bit<tcnt0_t, 3>;
using tcnt0_2_t = bit<tcnt0_t, 2>;
using tcnt0_1_t = bit<tcnt0_t, 1>;
using tcnt0_0_t = bit<tcnt0_t, 0>;
AVR_IO_INLINE_GLOBAL(tcnt0)
AVR_IO_INLINE_GLOBAL(tcnt0_7)
AVR_IO_INLINE_GLOBAL(tcnt0_6)
AVR_IO_INLINE_GLOBAL(tcnt0_5)
AVR_IO_INLINE_GLOBAL(tcnt0_4)
AVR_IO_INLINE_GLOBAL(tcnt0_3)
AVR_IO_INLINE_GLOBAL(tcnt0_2)
AVR_IO_INLINE_GLOBAL(tcnt0_1)
AVR_IO_INLINE_GLOBAL(tcnt0_0)

/** TCCR0B 0x25 */
using tccr0b_t = reg<0x25 + 0x20>;
using foc0a_t = bit<tccr0b_t, 7>;
using foc0b_t = bit<tccr0b_t, 6>;
using wgm02_t = bit<tccr0b_t, 3>;
using cs02_t = bit<tccr0b_t, 2>;
using cs01_t = bit<tccr0b_t, 1>;
using cs00_t = bit<tccr0b_t, 0>;
AVR_IO_INLINE_GLOBAL(tccr0b)
AVR_IO_INLINE_GLOBAL(foc0a)
AVR_IO_INLINE_GLOBAL(foc0b)
AVR_IO_INLINE_GLOBAL(wgm02)
AVR_IO_INLINE_GLOBAL(cs02)
AVR_IO_INLINE_GLOBAL(cs01)
AVR_IO_INLINE_GLOBAL(cs00)

/** TCCR0A 0x24 */
using tccr0a_t = reg<0x24 + 0x20>;
using com0a1_t = bit<tccr0a_t, 7>;
using com0a0_t = bit<tccr0a_t, 6>;
using com0b1_t = bit<tccr0a_t, 5>;
using com0b0_t = bit<tccr0a_t, 4>;
using wgm01_t = bit<tccr0a_t, 1>;
using wgm00_t = bit<tccr0a_t, 0>;
AVR_IO_INLINE_GLOBAL(tccr0a)
AVR_IO_INLINE_GLOBAL(com0a1)
AVR_IO_INLINE_GLOBAL(com0a0)
AVR_IO_INLINE_GLOBAL(com0b1)
AVR_IO_INLINE_GLOBAL(com0b0)
AVR_IO_INLINE_GLOBAL(wgm01)
AVR_IO_INLINE_GLOBAL(wgm00)

/** GTCCR 0x23 */
using gtccr_t = reg<0x23 + 0x20>;
using tsm_t = bit<gtccr_t,7>;
using psrasy_t = bit<gtccr_t,1>;
using psrsync_t = bit<gtccr_t,0>;
AVR_IO_INLINE_GLOBAL(gtccr)
AVR_IO_INLINE_GLOBAL(tsm)
AVR_IO_INLINE_GLOBAL(psrasy)
AVR_IO_INLINE_GLOBAL(psrsync)

/** EEARH 0x22 */
using eearh_t = reg<0x22 + 0x20>;
using eear8_t = bit<eearh_t, 0>;
AVR_IO_INLINE_GLOBAL(eearh)
AVR_IO_INLINE_GLOBAL(eear8)

/** EEARL 0x21 */
using eearl_t = reg<0x21 + 0x20>;
using eear7_t = bit<eearl_t, 7>;
using eear6_t = bit<eearl_t, 6>;
using eear5_t = bit<eearl_t, 5>;
using eear4_t = bit<eearl_t, 4>;
using eear3_t = bit<eearl_t, 3>;
using eear2_t = bit<eearl_t, 2>;
using eear1_t = bit<eearl_t, 1>;
using eear0_t = bit<eearl_t, 0>;
AVR_IO_INLINE_GLOBAL(eearl)
AVR_IO_INLINE_GLOBAL(eear7)
AVR_IO_INLINE_GLOBAL(eear6)
AVR_IO_INLINE_GLOBAL(eear5)
AVR_IO_INLINE_GLOBAL(eear4)
AVR_IO_INLINE_GLOBAL(eear3)
AVR_IO_INLINE_GLOBAL(eear2)
AVR_IO_INLINE_GLOBAL(eear1)
AVR_IO_INLINE_GLOBAL(eear0)

/** EEDR 0x20 */
using eedr_t = reg<0x20 + 0x20>;
using eedr7_t = bit<eedr_t, 7>;
using eedr6_t = bit<eedr_t, 6>;
using eedr5_t = bit<eedr_t, 5>;
using eedr4_t = bit<eedr_t, 4>;
using eedr3_t = bit<eedr_t, 3>;
using eedr2_t = bit<eedr_t, 2>;
using eedr1_t = bit<eedr_t, 1>;
using eedr0_t = bit<eedr_t, 0>;
AVR_IO_INLINE_GLOBAL(eedr)
AVR_IO_INLINE_GLOBAL(eedr7)
AVR_IO_INLINE_GLOBAL(eedr6)
AVR_IO_INLINE_GLOBAL(eedr5)
AVR_IO_INLINE_GLOBAL(eedr4)
AVR_IO_INLINE_GLOBAL(eedr3)
AVR_IO_INLINE_GLOBAL(eedr2)
AVR_IO_INLINE_GLOBAL(eedr1)
AVR_IO_INLINE_GLOBAL(eedr0)

/** EECR 0x1f */
using eecr_t = reg<0x1f + 0x20>;
using eepm1_t = bit<eecr_t, 5>;
using eepm0_t = bit<eecr_t, 4>;
using eerie_t = bit<eecr_t, 3>;
using eempe_t = bit<eecr_t, 2>;
using eepe_t = bit<eecr_t, 1>;
using eere_t = bit<eecr_t, 0>;
AVR_IO_INLINE_GLOBAL(eecr)
AVR_IO_INLINE_GLOBAL(eepm1)
AVR_IO_INLINE_GLOBAL(eepm0)
AVR_IO_INLINE_GLOBAL(eerie)
AVR_IO_INLINE_GLOBAL(eempe)
AVR_IO_INLINE_GLOBAL(eepe)
AVR_IO_INLINE_GLOBAL(eere)

/** GPIOR0 0x1e */
using gpior0_t = reg<0x1e + 0x20>;
using gpior0_7_t = bit<gpior0_t, 7>;
using gpior0_6_t = bit<gpior0_t, 6>;
using gpior0_5_t = bit<gpior0_t, 5>;
using gpior0_4_t = bit<gpior0_t, 4>;
using gpior0_3_t = bit<gpior0_t, 3>;
using gpior0_2_t = bit<gpior0_t, 2>;
using gpior0_1_t = bit<gpior0_t, 1>;
using gpior0_0_t = bit<gpior0_t, 0>;
AVR_IO_INLINE_GLOBAL(gpior0)
AVR_IO_INLINE_GLOBAL(gpior0_7)
AVR_IO_INLINE_GLOBAL(gpior0_6)
AVR_IO_INLINE_GLOBAL(gpior0_5)
AVR_IO_INLINE_GLOBAL(gpior0_4)
AVR_IO_INLINE_GLOBAL(gpior0_3)
AVR_IO_INLINE_GLOBAL(gpior0_2)
AVR_IO_INLINE_GLOBAL(gpior0_1)
AVR_IO_INLINE_GLOBAL(gpior0_0)

/** EIMSK 0x1d */
using eimsk_t = reg<0x1d + 0x20>;
using int1_t = bit<eimsk_t, 1>;
using int0_t = bit<eimsk_t, 0>;
AVR_IO_INLINE_GLOBAL(eimsk)
AVR_IO_INLINE_GLOBAL(int1)
AVR_IO_INLINE_GLOBAL(int0)

/** EIFR 0x1c */
using eifr_t = reg<0x1c + 0x20>;
using intf1_t = bit<eifr_t, 1>;
using intf0_t = bit<eifr_t, 0>;
AVR_IO_INLINE_GLOBAL(eifr)
AVR_IO_INLINE_GLOBAL(intf1)
AVR_IO_INLINE_GLOBAL(intf0)

/** PCIFR 0x1b */
using pcifr_t = reg<0x1b + 0x20>;
using pcif2_t = bit<pcifr_t, 2>;
using pcif1_t = bit<pcifr_t, 1>;
using pcif0_t = bit<pcifr_t, 0>;
AVR_IO_INLINE_GLOBAL(pcifr)
AVR_IO_INLINE_GLOBAL(pcif2)
AVR_IO_INLINE_GLOBAL(pcif1)
AVR_IO_INLINE_GLOBAL(pcif0)

/** TIFR2 0x17 */
using tifr2_t = reg<0x17 + 0x20>;
using ocf2b_t = bit<tifr2_t,2>;
using ocf2a_t = bit<tifr2_t,1>;
using tov2_t = bit<tifr2_t,0>;
AVR_IO_INLINE_GLOBAL(tifr2)
AVR_IO_INLINE_GLOBAL(ocf2b)
AVR_IO_INLINE_GLOBAL(ocf2a)
AVR_IO_INLINE_GLOBAL(tov2)

/** TIFR1 0x16 */
using tifr1_t = reg<0x16 + 0x20>;
using icf1_t = bit<tifr1_t,5>;
using ocf1b_t = bit<tifr1_t,2>;
using ocf1a_t = bit<tifr1_t,1>;
using tov1_t = bit<tifr1_t,0>;
AVR_IO_INLINE_GLOBAL(tifr1)
AVR_IO_INLINE_GLOBAL(icf1)
AVR_IO_INLINE_GLOBAL(ocf1b)
AVR_IO_INLINE_GLOBAL(ocf1a)
AVR_IO_INLINE_GLOBAL(tov1)

/** TIFR0 0x15 */
using tifr0_t = reg<0x15 + 0x20>;
using ocf0b_t = bit<tifr0_t,2>;
using ocf0a_t = bit<tifr0_t,1>;
using tov0_t = bit<tifr0_t,0>;
AVR_IO_INLINE_GLOBAL(tifr0)
AVR_IO_INLINE_GLOBAL(ocf0b)
AVR_IO_INLINE_GLOBAL(ocf0a)
AVR_IO_INLINE_GLOBAL(tov0)

/** PORTD 0x0B */
using portd_t = reg<0x0B + 0x20>;
using portd7_t = bit<portd_t, 7>;
using portd6_t = bit<portd_t, 6>;
using portd5_t = bit<portd_t, 5>;
using portd4_t = bit<portd_t, 4>;
using portd3_t = bit<portd_t, 3>;
using portd2_t = bit<portd_t, 2>;
using portd1_t = bit<portd_t, 1>;
using portd0_t = bit<portd_t, 0>;
AVR_IO_INLINE_GLOBAL(portd)
AVR_IO_INLINE_GLOBAL(portd7)
AVR_IO_INLINE_GLOBAL(portd6)
AVR_IO_INLINE_GLOBAL(portd5)
AVR_IO_INLINE_GLOBAL(portd4)
AVR_IO_INLINE_GLOBAL(portd3)
AVR_IO_INLINE_GLOBAL(portd2)
AVR_IO_INLINE_GLOBAL(portd1)
AVR_IO_INLINE_GLOBAL(portd0)

/** DDRD 0x0a */
using ddrd_t = reg<0x0a + 0x20>;
using ddd7_t = bit<ddrd_t, 7>;
using ddd6_t = bit<ddrd_t, 6>;
using ddd5_t = bit<ddrd_t, 5>;
using ddd4_t = bit<ddrd_t, 4>;
using ddd3_t = bit<ddrd_t, 3>;
using ddd2_t = bit<ddrd_t, 2>;
using ddd1_t = bit<ddrd_t, 1>;
using ddd0_t = bit<ddrd_t, 0>;
AVR_IO_INLINE_GLOBAL(ddrd)
AVR_IO_INLINE_GLOBAL(ddd7)
AVR_IO_INLINE_GLOBAL(ddd6)
AVR_IO_INLINE_GLOBAL(ddd5)
AVR_IO_INLINE_GLOBAL(ddd4)
AVR_IO_INLINE_GLOBAL(ddd3)
AVR_IO_INLINE_GLOBAL(ddd2)
AVR_IO_INLINE_GLOBAL(ddd1)
AVR_IO_INLINE_GLOBAL(ddd0)

/** PIND 0x09 */
using pind_t = reg<0x09 + 0x20>;
using pind7_t = bit<pind_t, 7>;
using pind6_t = bit<pind_t, 6>;
using pind5_t = bit<pind_t, 5>;
using pind4_t = bit<pind_t, 4>;
using pind3_t = bit<pind_t, 3>;
using pind2_t = bit<pind_t, 2>;
using pind1_t = bit<pind_t, 1>;
using pind0_t = bit<pind_t, 0>;
AVR_IO_INLINE_GLOBAL(pind)
AVR_IO_INLINE_GLOBAL(pind7)
AVR_IO_INLINE_GLOBAL(pind6)
AVR_IO_INLINE_GLOBAL(pind5)
AVR_IO_INLINE_GLOBAL(pind4)
AVR_IO_INLINE_GLOBAL(pind3)
AVR_IO_INLINE_GLOBAL(pind2)
AVR_IO_INLINE_GLOBAL(pind1)
AVR_IO_INLINE_GLOBAL(pind0)

/** PORTC 0x08 */
using portc_t = reg<0x08 + 0x20>;
using portc6_t = bit<portc_t, 6>;
using portc5_t = bit<portc_t, 5>;
using portc4_t = bit<portc_t, 4>;
using portc3_t = bit<portc_t, 3>;
using portc2_t = bit<portc_t, 2>;
using portc1_t = bit<portc_t, 1>;
using portc0_t = bit<portc_t, 0>;
AVR_IO_INLINE_GLOBAL(portc)
AVR_IO_INLINE_GLOBAL(portc6)
AVR_IO_INLINE_GLOBAL(portc5)
AVR_IO_INLINE_GLOBAL(portc4)
AVR_IO_INLINE_GLOBAL(portc3)
AVR_IO_INLINE_GLOBAL(portc2)
AVR_IO_INLINE_GLOBAL(portc1)
AVR_IO_INLINE_GLOBAL(portc0)

/** DDRC 0x07 */
using ddrc_t = reg<0x07 + 0x20>;
using ddc7_t = bit<ddrc_t, 7>;
using ddc6_t = bit<ddrc_t, 6>;
using ddc5_t = bit<ddrc_t, 5>;
using ddc4_t = bit<ddrc_t, 4>;
using ddc3_t = bit<ddrc_t, 3>;
using ddc2_t = bit<ddrc_t, 2>;
using ddc1_t = bit<ddrc_t, 1>;
using ddc0_t = bit<ddrc_t, 0>;
AVR_IO_INLINE_GLOBAL(ddrc)
AVR_IO_INLINE_GLOBAL(ddc7)
AVR_IO_INLINE_GLOBAL(ddc6)
AVR_IO_INLINE_GLOBAL(ddc5)
AVR_IO_INLINE_GLOBAL(ddc4)
AVR_IO_INLINE_GLOBAL(ddc3)
AVR_IO_INLINE_GLOBAL(ddc2)
AVR_IO_INLINE_GLOBAL(ddc1)
AVR_IO_INLINE_GLOBAL(ddc0)

/** PINC 0x06 */
using pinc_t = reg<0x06 + 0x20>;
using pinc7_t = bit<pinc_t, 7>;
using pinc6_t = bit<pinc_t, 6>;
using pinc5_t = bit<pinc_t, 5>;
using pinc4_t = bit<pinc_t, 4>;
using pinc3_t = bit<pinc_t, 3>;
using pinc2_t = bit<pinc_t, 2>;
using pinc1_t = bit<pinc_t, 1>;
using pinc0_t = bit<pinc_t, 0>;
AVR_IO_INLINE_GLOBAL(pinc)
AVR_IO_INLINE_GLOBAL(pinc7)
AVR_IO_INLINE_GLOBAL(pinc6)
AVR_IO_INLINE_GLOBAL(pinc5)
AVR_IO_INLINE_GLOBAL(pinc4)
AVR_IO_INLINE_GLOBAL(pinc3)
AVR_IO_INLINE_GLOBAL(pinc2)
AVR_IO_INLINE_GLOBAL(pinc1)
AVR_IO_INLINE_GLOBAL(pinc0)

/** PORTB 0x05 */
using portb_t = reg<0x05 + 0x20>;
using portb7_t = bit<portb_t, 7>;
using portb6_t = bit<portb_t, 6>;
using portb5_t = bit<portb_t, 5>;
using portb4_t = bit<portb_t, 4>;
using portb3_t = bit<portb_t, 3>;
using portb2_t = bit<portb_t, 2>;
using portb1_t = bit<portb_t, 1>;
using portb0_t = bit<portb_t, 0>;
AVR_IO_INLINE_GLOBAL(portb)
AVR_IO_INLINE_GLOBAL(portb7)
AVR_IO_INLINE_GLOBAL(portb6)
AVR_IO_INLINE_GLOBAL(portb5)
AVR_IO_INLINE_GLOBAL(portb4)
AVR_IO_INLINE_GLOBAL(portb3)
AVR_IO_INLINE_GLOBAL(portb2)
AVR_IO_INLINE_GLOBAL(portb1)
AVR_IO_INLINE_GLOBAL(portb0)

/** DDRB 0x04 */
using ddrb_t = reg<0x04 + 0x20>;
using ddb7_t = bit<ddrb_t, 7>;
using ddb6_t = bit<ddrb_t, 6>;
using ddb5_t = bit<ddrb_t, 5>;
using ddb4_t = bit<ddrb_t, 4>;
using ddb3_t = bit<ddrb_t, 3>;
using ddb2_t = bit<ddrb_t, 2>;
using ddb1_t = bit<ddrb_t, 1>;
using ddb0_t = bit<ddrb_t, 0>;
AVR_IO_INLINE_GLOBAL(ddrb)
AVR_IO_INLINE_GLOBAL(ddb7)
AVR_IO_INLINE_GLOBAL(ddb6)
AVR_IO_INLINE_GLOBAL(ddb5)
AVR_IO_INLINE_GLOBAL(ddb4)
AVR_IO_INLINE_GLOBAL(ddb3)
AVR_IO_INLINE_GLOBAL(ddb2)
AVR_IO_INLINE_GLOBAL(ddb1)
AVR_IO_INLINE_GLOBAL(ddb0)

/** PINB 0x03 */
using pinb_t = reg<0x03 + 0x20>;
using pinb7_t = bit<pinb_t, 7>;
using pinb6_t = bit<pinb_t, 6>;
using pinb5_t = bit<pinb_t, 5>;
using pinb4_t = bit<pinb_t, 4>;
using pinb3_t = bit<pinb_t, 3>;
using pinb2_t = bit<pinb_t, 2>;
using pinb1_t = bit<pinb_t, 1>;
using pinb0_t = bit<pinb_t, 0>;
AVR_IO_INLINE_GLOBAL(pinb)
AVR_IO_INLINE_GLOBAL(pinb7)
AVR_IO_INLINE_GLOBAL(pinb6)
AVR_IO_INLINE_GLOBAL(pinb5)
AVR_IO_INLINE_GLOBAL(pinb4)
AVR_IO_INLINE_GLOBAL(pinb3)
AVR_IO_INLINE_GLOBAL(pinb2)
AVR_IO_INLINE_GLOBAL(pinb1)
AVR_IO_INLINE_GLOBAL(pinb0)

}}

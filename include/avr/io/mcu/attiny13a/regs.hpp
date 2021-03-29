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

/** GIMSK 0x3b */
using gimsk_t = reg<0x3b + 0x20>;
using int0_t = bit<gimsk_t,6>;
using pcie_t = bit<gimsk_t,5>;
AVR_IO_INLINE_GLOBAL(gimsk)
AVR_IO_INLINE_GLOBAL(int0)
AVR_IO_INLINE_GLOBAL(pcie)

/** GIFR 0x3a */
using gifr_t = reg<0x3a + 0x20>;
using intf0_t = bit<gifr_t,6>;
using pcif_t = bit<gifr_t,5>;
AVR_IO_INLINE_GLOBAL(gifr)
AVR_IO_INLINE_GLOBAL(intf0)
AVR_IO_INLINE_GLOBAL(pcif)

/** TIMSK0 0x39 */
using timsk0_t = reg<0x39 + 0x20>;
using ocie0b_t = bit<timsk0_t,3>;
using ocie0a_t = bit<timsk0_t,2>;
using toie0_t = bit<timsk0_t,1>;
AVR_IO_INLINE_GLOBAL(timsk0)
AVR_IO_INLINE_GLOBAL(ocie0b)
AVR_IO_INLINE_GLOBAL(ocie0a)
AVR_IO_INLINE_GLOBAL(toie0)

/** TIFR0 0x38 */
using tifr0_t = reg<0x38 + 0x20>;
using ocf0b_t = bit<tifr0_t,3>;
using ocf0a_t = bit<tifr0_t,2>;
using tov0_t = bit<tifr0_t,1>;
AVR_IO_INLINE_GLOBAL(tifr0)
AVR_IO_INLINE_GLOBAL(ocf0b)
AVR_IO_INLINE_GLOBAL(ocf0a)
AVR_IO_INLINE_GLOBAL(tov0)

/** SPMCSR 0x37 */
using spmcsr_t = reg<0x37 + 0x20>;
using ctpb_t = bit<spmcsr_t,4>;
using rflb_t = bit<spmcsr_t,3>;
using pgwrt_t = bit<spmcsr_t,2>;
using pgers_t = bit<spmcsr_t,1>;
using selfprgen_t = bit<spmcsr_t,0>;
AVR_IO_INLINE_GLOBAL(spmcsr)
AVR_IO_INLINE_GLOBAL(ctpb)
AVR_IO_INLINE_GLOBAL(rflb)
AVR_IO_INLINE_GLOBAL(pgwrt)
AVR_IO_INLINE_GLOBAL(pgers)
AVR_IO_INLINE_GLOBAL(selfprgen)

/** OCR0A 0x36 */
using ocr0a_t = reg<0x36 + 0x20>;
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

/** MCUCR 0x35 */
using mcucr_t = reg<0x35 + 0x20>;
using pud_t = bit<mcucr_t,6>;
using se_t = bit<mcucr_t,5>;
using sm1_t = bit<mcucr_t,4>;
using sm0_t = bit<mcucr_t,3>;
using isc01_t = bit<mcucr_t,1>;
using isc00_t = bit<mcucr_t,0>;
AVR_IO_INLINE_GLOBAL(mcucr)
AVR_IO_INLINE_GLOBAL(pud)
AVR_IO_INLINE_GLOBAL(se)
AVR_IO_INLINE_GLOBAL(sm1)
AVR_IO_INLINE_GLOBAL(sm0)
AVR_IO_INLINE_GLOBAL(isc01)
AVR_IO_INLINE_GLOBAL(isc00)

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

/** TCCR0B 0x33 */
using tccr0b_t = reg<0x33 + 0x20>;
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

/** TCNT0 0x32 */
using tcnt0_t = reg<0x32 + 0x20>;
using tcnt07_t = bit<tcnt0_t,7>;
using tcnt06_t = bit<tcnt0_t,6>;
using tcnt05_t = bit<tcnt0_t,5>;
using tcnt04_t = bit<tcnt0_t,4>;
using tcnt03_t = bit<tcnt0_t,3>;
using tcnt02_t = bit<tcnt0_t,2>;
using tcnt01_t = bit<tcnt0_t,1>;
using tcnt00_t = bit<tcnt0_t,0>;
AVR_IO_INLINE_GLOBAL(tcnt0)
AVR_IO_INLINE_GLOBAL(tcnt07)
AVR_IO_INLINE_GLOBAL(tcnt06)
AVR_IO_INLINE_GLOBAL(tcnt05)
AVR_IO_INLINE_GLOBAL(tcnt04)
AVR_IO_INLINE_GLOBAL(tcnt03)
AVR_IO_INLINE_GLOBAL(tcnt02)
AVR_IO_INLINE_GLOBAL(tcnt01)
AVR_IO_INLINE_GLOBAL(tcnt00)

/** OSCCAL 0x31 */
using osccal_t = reg<0x31 + 0x20>;
using cal6_t = bit<osccal_t,6>;
using cal5_t = bit<osccal_t,5>;
using cal4_t = bit<osccal_t,4>;
using cal3_t = bit<osccal_t,3>;
using cal2_t = bit<osccal_t,2>;
using cal1_t = bit<osccal_t,1>;
using cal0_t = bit<osccal_t,0>;
AVR_IO_INLINE_GLOBAL(osccal)
AVR_IO_INLINE_GLOBAL(cal6)
AVR_IO_INLINE_GLOBAL(cal5)
AVR_IO_INLINE_GLOBAL(cal4)
AVR_IO_INLINE_GLOBAL(cal3)
AVR_IO_INLINE_GLOBAL(cal2)
AVR_IO_INLINE_GLOBAL(cal1)
AVR_IO_INLINE_GLOBAL(cal0)

/** BODCR 0x30 */
using bodcr_t = reg<0x30 + 0x20>;
using bods_t = bit<bodcr_t,1>;
using bodse_t = bit<bodcr_t,0>;
AVR_IO_INLINE_GLOBAL(bodcr)
AVR_IO_INLINE_GLOBAL(bods)
AVR_IO_INLINE_GLOBAL(bodse)

/** TCCR0A 0x2f */
using tccr0a_t = reg<0x2f + 0x20>;
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

/** DWDR 0x2e */
using dwdr_t = reg<0x2e + 0x20>;
using dwdr7_t = bit<dwdr_t,7>;
using dwdr6_t = bit<dwdr_t,6>;
using dwdr5_t = bit<dwdr_t,5>;
using dwdr4_t = bit<dwdr_t,4>;
using dwdr3_t = bit<dwdr_t,3>;
using dwdr2_t = bit<dwdr_t,2>;
using dwdr1_t = bit<dwdr_t,1>;
using dwdr0_t = bit<dwdr_t,0>;
AVR_IO_INLINE_GLOBAL(dwdr)
AVR_IO_INLINE_GLOBAL(dwdr7)
AVR_IO_INLINE_GLOBAL(dwdr6)
AVR_IO_INLINE_GLOBAL(dwdr5)
AVR_IO_INLINE_GLOBAL(dwdr4)
AVR_IO_INLINE_GLOBAL(dwdr3)
AVR_IO_INLINE_GLOBAL(dwdr2)
AVR_IO_INLINE_GLOBAL(dwdr1)
AVR_IO_INLINE_GLOBAL(dwdr0)

/** OCR0B 0x29 */
using ocr0b_t = reg<0x29 + 0x20>;
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

/** GTCCR 0x28 */
using gtccr_t = reg<0x28 + 0x20>;
using tsm_t = bit<gtccr_t,7>;
using psr10_t = bit<gtccr_t,0>;
AVR_IO_INLINE_GLOBAL(gtccr)
AVR_IO_INLINE_GLOBAL(tsm)
AVR_IO_INLINE_GLOBAL(psr10)

/** CLKPR 0x26 */
using clkpr_t = reg<0x26 + 0x20>;
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

/** PRR 0x25 */
using prr_t = reg<0x25 + 0x20>;
using prtim0_t = bit<prr_t, 1>;
using pradc_t = bit<prr_t, 0>;
AVR_IO_INLINE_GLOBAL(prr)
AVR_IO_INLINE_GLOBAL(prtim0)
AVR_IO_INLINE_GLOBAL(pradc)

/** WDTCR 0x21 */
using wdtcr_t = reg<0x21 + 0x20>;
using wdtif_t = bit<wdtcr_t, 7>;
using wdtie_t = bit<wdtcr_t, 6>;
using wdp3_t = bit<wdtcr_t, 5>;
using wdce_t = bit<wdtcr_t, 4>;
using wde_t = bit<wdtcr_t, 3>;
using wdp2_t = bit<wdtcr_t, 2>;
using wdp1_t = bit<wdtcr_t, 1>;
using wdp0_t = bit<wdtcr_t, 0>;
AVR_IO_INLINE_GLOBAL(wdtcr)
AVR_IO_INLINE_GLOBAL(wdtif)
AVR_IO_INLINE_GLOBAL(wdtie)
AVR_IO_INLINE_GLOBAL(wdp3)
AVR_IO_INLINE_GLOBAL(wdce)
AVR_IO_INLINE_GLOBAL(wde)
AVR_IO_INLINE_GLOBAL(wdp2)
AVR_IO_INLINE_GLOBAL(wdp1)
AVR_IO_INLINE_GLOBAL(wdp0)

#define AVR_IO_WDT_HAS_WDRF 1
#define AVR_IO_WDT_HAS_WDP3 1
#define AVR_IO_WDT_HAS_INTERRUPT_MODE 1
#define AVR_IO_WDT_NEEDS_ON_TIMED_SEQ 0
#define AVR_IO_WDT_NEEDS_OFF_TIMED_SEQ 1

/** EEARL 0x1e */
using eearl_t = reg<0x1e + 0x20>;
using eear5_t = bit<eearl_t, 5>;
using eear4_t = bit<eearl_t, 4>;
using eear3_t = bit<eearl_t, 3>;
using eear2_t = bit<eearl_t, 2>;
using eear1_t = bit<eearl_t, 1>;
using eear0_t = bit<eearl_t, 0>;
AVR_IO_INLINE_GLOBAL(eearl)
AVR_IO_INLINE_GLOBAL(eear5)
AVR_IO_INLINE_GLOBAL(eear4)
AVR_IO_INLINE_GLOBAL(eear3)
AVR_IO_INLINE_GLOBAL(eear2)
AVR_IO_INLINE_GLOBAL(eear1)
AVR_IO_INLINE_GLOBAL(eear0)

/** EEDR 0x1d */
using eedr_t = reg<0x1d + 0x20>;
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

/** EECR 0x1c */
using eecr_t = reg<0x1c + 0x20>;
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

/** PORTB 0x18 */
using portb_t = reg<0x18 + 0x20>;
using portb5_t = bit<portb_t, 5>;
using portb4_t = bit<portb_t, 4>;
using portb3_t = bit<portb_t, 3>;
using portb2_t = bit<portb_t, 2>;
using portb1_t = bit<portb_t, 1>;
using portb0_t = bit<portb_t, 0>;
AVR_IO_INLINE_GLOBAL(portb)
AVR_IO_INLINE_GLOBAL(portb5)
AVR_IO_INLINE_GLOBAL(portb4)
AVR_IO_INLINE_GLOBAL(portb3)
AVR_IO_INLINE_GLOBAL(portb2)
AVR_IO_INLINE_GLOBAL(portb1)
AVR_IO_INLINE_GLOBAL(portb0)

/** DDRB 0x17 */
using ddrb_t = reg<0x17 + 0x20>;
using ddb5_t = bit<ddrb_t, 5>;
using ddb4_t = bit<ddrb_t, 4>;
using ddb3_t = bit<ddrb_t, 3>;
using ddb2_t = bit<ddrb_t, 2>;
using ddb1_t = bit<ddrb_t, 1>;
using ddb0_t = bit<ddrb_t, 0>;
AVR_IO_INLINE_GLOBAL(ddrb)
AVR_IO_INLINE_GLOBAL(ddb5)
AVR_IO_INLINE_GLOBAL(ddb4)
AVR_IO_INLINE_GLOBAL(ddb3)
AVR_IO_INLINE_GLOBAL(ddb2)
AVR_IO_INLINE_GLOBAL(ddb1)
AVR_IO_INLINE_GLOBAL(ddb0)

/** PINB 0x16 */
using pinb_t = reg<0x16 + 0x20>;
using pinb5_t = bit<pinb_t, 5>;
using pinb4_t = bit<pinb_t, 4>;
using pinb3_t = bit<pinb_t, 3>;
using pinb2_t = bit<pinb_t, 2>;
using pinb1_t = bit<pinb_t, 1>;
using pinb0_t = bit<pinb_t, 0>;
AVR_IO_INLINE_GLOBAL(pinb)
AVR_IO_INLINE_GLOBAL(pinb5)
AVR_IO_INLINE_GLOBAL(pinb4)
AVR_IO_INLINE_GLOBAL(pinb3)
AVR_IO_INLINE_GLOBAL(pinb2)
AVR_IO_INLINE_GLOBAL(pinb1)
AVR_IO_INLINE_GLOBAL(pinb0)

/** PCMSK 0x15 */
using pcmsk_t = reg<0x15 + 0x20>;
using pcint5_t = bit<pcmsk_t, 5>;
using pcint4_t = bit<pcmsk_t, 4>;
using pcint3_t = bit<pcmsk_t, 3>;
using pcint2_t = bit<pcmsk_t, 2>;
using pcint1_t = bit<pcmsk_t, 1>;
using pcint0_t = bit<pcmsk_t, 0>;
AVR_IO_INLINE_GLOBAL(pcmsk)
AVR_IO_INLINE_GLOBAL(pcint5)
AVR_IO_INLINE_GLOBAL(pcint4)
AVR_IO_INLINE_GLOBAL(pcint3)
AVR_IO_INLINE_GLOBAL(pcint2)
AVR_IO_INLINE_GLOBAL(pcint1)
AVR_IO_INLINE_GLOBAL(pcint0)

/** DIDR0 0x14 */
using didr0_t = reg<0x14 + 0x20>;
using adc0d_t = bit<didr0_t, 5>;
using adc2d_t = bit<didr0_t, 4>;
using adc3d_t = bit<didr0_t, 3>;
using adc1d_t = bit<didr0_t, 2>;
using ain1d_t = bit<didr0_t, 1>;
using ain0d_t = bit<didr0_t, 0>;
AVR_IO_INLINE_GLOBAL(didr0)
AVR_IO_INLINE_GLOBAL(adc0d)
AVR_IO_INLINE_GLOBAL(adc2d)
AVR_IO_INLINE_GLOBAL(adc3d)
AVR_IO_INLINE_GLOBAL(adc1d)
AVR_IO_INLINE_GLOBAL(ain1d)
AVR_IO_INLINE_GLOBAL(ain0d)

/** ACSR 0x08 */
using acsr_t = reg<0x08 + 0x20>;
using acd_t = bit<acsr_t, 7>;
using acbg_t = bit<acsr_t, 6>;
using aco_t = bit<acsr_t, 5>;
using aci_t = bit<acsr_t, 4>;
using acie_t = bit<acsr_t, 3>;
using acis1_t = bit<acsr_t, 1>;
using acis0_t = bit<acsr_t, 0>;
AVR_IO_INLINE_GLOBAL(acsr)
AVR_IO_INLINE_GLOBAL(acd)
AVR_IO_INLINE_GLOBAL(acbg)
AVR_IO_INLINE_GLOBAL(aco)
AVR_IO_INLINE_GLOBAL(aci)
AVR_IO_INLINE_GLOBAL(acie)
AVR_IO_INLINE_GLOBAL(acis1)
AVR_IO_INLINE_GLOBAL(acis0)

/** ADMUX 0x07 */
using admux_t = reg<0x07 + 0x20>;
using refs0_t = bit<admux_t, 6>;
using adlar_t = bit<admux_t, 5>;
using mux1_t = bit<admux_t, 1>;
using mux0_t = bit<admux_t, 0>;
AVR_IO_INLINE_GLOBAL(admux)
AVR_IO_INLINE_GLOBAL(refs0)
AVR_IO_INLINE_GLOBAL(adlar)
AVR_IO_INLINE_GLOBAL(mux1)
AVR_IO_INLINE_GLOBAL(mux0)

/** ADCSRA 0x06 */
using adcsra_t = reg<0x06 + 0x20>;
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

/** ADCH 0x05 */
using adch_t = reg<0x05 + 0x20>;
using adch7_t = bit<adch_t, 7>;
using adch6_t = bit<adch_t, 6>;
using adch5_t = bit<adch_t, 5>;
using adch4_t = bit<adch_t, 4>;
using adch3_t = bit<adch_t, 3>;
using adch2_t = bit<adch_t, 2>;
using adch1_t = bit<adch_t, 1>;
using adch0_t = bit<adch_t, 0>;
AVR_IO_INLINE_GLOBAL(adch)
AVR_IO_INLINE_GLOBAL(adch7)
AVR_IO_INLINE_GLOBAL(adch6)
AVR_IO_INLINE_GLOBAL(adch5)
AVR_IO_INLINE_GLOBAL(adch4)
AVR_IO_INLINE_GLOBAL(adch3)
AVR_IO_INLINE_GLOBAL(adch2)
AVR_IO_INLINE_GLOBAL(adch1)
AVR_IO_INLINE_GLOBAL(adch0)

/** ADCL 0x04 */
using adcl_t = reg<0x04 + 0x20>;
using adcl7_t = bit<adcl_t, 7>;
using adcl6_t = bit<adcl_t, 6>;
using adcl5_t = bit<adcl_t, 5>;
using adcl4_t = bit<adcl_t, 4>;
using adcl3_t = bit<adcl_t, 3>;
using adcl2_t = bit<adcl_t, 2>;
using adcl1_t = bit<adcl_t, 1>;
using adcl0_t = bit<adcl_t, 0>;
AVR_IO_INLINE_GLOBAL(adcl)
AVR_IO_INLINE_GLOBAL(adcl7)
AVR_IO_INLINE_GLOBAL(adcl6)
AVR_IO_INLINE_GLOBAL(adcl5)
AVR_IO_INLINE_GLOBAL(adcl4)
AVR_IO_INLINE_GLOBAL(adcl3)
AVR_IO_INLINE_GLOBAL(adcl2)
AVR_IO_INLINE_GLOBAL(adcl1)
AVR_IO_INLINE_GLOBAL(adcl0)

/** ADCSRB 0x03 */
using adcsrb_t = reg<0x03 + 0x20>;
using acme_t = bit<adcsrb_t, 6>;
using adts2_t = bit<adcsrb_t, 2>;
using adts1_t = bit<adcsrb_t, 1>;
using adts0_t = bit<adcsrb_t, 0>;
AVR_IO_INLINE_GLOBAL(adcsrb)
AVR_IO_INLINE_GLOBAL(acme)
AVR_IO_INLINE_GLOBAL(adts2)
AVR_IO_INLINE_GLOBAL(adts1)
AVR_IO_INLINE_GLOBAL(adts0)

}}

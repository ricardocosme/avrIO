#pragma once

#include "avr/io/attiny85.hpp"
#include "avr/io/detail/global.hpp"
#include "avr/io/reg.hpp"

namespace avr { namespace io {

using mcucr_t = reg_t<0x35 + 0x20>;
using pud_t = reg_bit_t<mcucr_t,6>;
using se_t = reg_bit_t<mcucr_t,5>;
using sm1_t = reg_bit_t<mcucr_t,4>;
using sm0_t = reg_bit_t<mcucr_t,3>;
using isc01_t = reg_bit_t<mcucr_t,1>;
using isc00_t = reg_bit_t<mcucr_t,0>;

#if __cplusplus >= 201703L
constexpr inline mcucr_t mcucr;
constexpr inline pud_t pud;
constexpr inline se_t se;
constexpr inline sm1_t sm1;
constexpr inline sm0_t sm0;
constexpr inline isc01_t isc01;
constexpr inline isc00_t isc00;
#else
namespace {
constexpr auto& mcucr{detail::global<mcucr_t>::instance};
constexpr auto& pud{detail::global<pud_t>::instance};
constexpr auto& se{detail::global<se_t>::instance};
constexpr auto& sm1{detail::global<sm1_t>::instance};
constexpr auto& sm0{detail::global<sm0_t>::instance};
constexpr auto& isc01{detail::global<isc01_t>::instance};
constexpr auto& isc00{detail::global<isc00_t>::instance};
}//anonymous namespace
#endif

using wdtcr_t = reg_t<0x21 + 0x20>;
using wdtif_t = reg_bit_t<wdtcr_t, 7>;
using wdtie_t = reg_bit_t<wdtcr_t, 6>;
using wdp3_t = reg_bit_t<wdtcr_t, 5>;
using wdce_t = reg_bit_t<wdtcr_t, 4>;
using wde_t = reg_bit_t<wdtcr_t, 3>;
using wdp2_t = reg_bit_t<wdtcr_t, 2>;
using wdp1_t = reg_bit_t<wdtcr_t, 1>;
using wdp0_t = reg_bit_t<wdtcr_t, 0>;

#if __cplusplus >= 201703L
constexpr inline wdtcr_t wdtcr;
constexpr inline wdtif_t wdtif;
constexpr inline wdtie_t wdtie;
constexpr inline wdp3_t wdp3;
constexpr inline wdce_t wdce;
constexpr inline wde_t wde;
constexpr inline wdp2_t wdp2;
constexpr inline wdp1_t wdp1;
constexpr inline wdp0_t wdp0;
#else
namespace {
constexpr auto& wdtcr{detail::global<wdtcr_t>::instance};
constexpr auto& wdtif{detail::global<wdtif_t>::instance};
constexpr auto& wdtie{detail::global<wdtie_t>::instance};
constexpr auto& wdp3{detail::global<wdp3_t>::instance};
constexpr auto& wdce{detail::global<wdce_t>::instance};
constexpr auto& wde{detail::global<wde_t>::instance};
constexpr auto& wdp2{detail::global<wdp2_t>::instance};
constexpr auto& wdp1{detail::global<wdp1_t>::instance};
constexpr auto& wdp0{detail::global<wdp0_t>::instance};
}//anonymous namespace
#endif

}}

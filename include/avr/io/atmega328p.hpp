#pragma once

#include <avr/io/detail/global.hpp>
#include <avr/io/pxn.hpp>

namespace avr { namespace io {

// Port B
//
// The following global object are defined to represent each pin of the
// I/O port B: pb0, pb1, pb2, pb3, pb4, pb5, pb6 and pb7.
//
// The port can also be accessed through the respective types, which
// are: pb0_t, pb1_t ,pb2_t, pb3_t, pb4_t, pb5_t, pb6_t and pb7_t.
//
// See pxn.hpp to know to use the abstraction.
//
template<uint8_t n>
using portBn = pxn<0x03 + 0x20, n>;

using pb0_t = portBn<0>;
using pb1_t = portBn<1>;
using pb2_t = portBn<2>;
using pb3_t = portBn<3>;
using pb4_t = portBn<4>;
using pb5_t = portBn<5>;
using pb6_t = portBn<6>;
using pb7_t = portBn<7>;

#if (__cplusplus >= 201703L)
inline constexpr pb0_t pb0;
inline constexpr pb1_t pb1;
inline constexpr pb2_t pb2;
inline constexpr pb3_t pb3;
inline constexpr pb4_t pb4;
inline constexpr pb5_t pb5;
inline constexpr pb6_t pb6;
inline constexpr pb7_t pb7;
#else
namespace {
constexpr auto& pb0{detail::global<pb0_t>::instance};
constexpr auto& pb1{detail::global<pb1_t>::instance};
constexpr auto& pb2{detail::global<pb2_t>::instance};
constexpr auto& pb3{detail::global<pb3_t>::instance};
constexpr auto& pb4{detail::global<pb4_t>::instance};
constexpr auto& pb5{detail::global<pb5_t>::instance};
constexpr auto& pb6{detail::global<pb6_t>::instance};
constexpr auto& pb7{detail::global<pb7_t>::instance};
} //anonymous namespace
#endif

// Port C
//
// The following global object are defined to represent each pin of the
// I/O port C: pc0, pc1, pc2, pc3, pc4, pc5 and pc6.
//
// The port can also be accessed through the respective types, which
// are: pc0_t, pc1_t ,pc2_t, pc3_t, pc4_t, pc5_t and pc6_t.
//
// See pxn.hpp to know to use the abstraction.
//
template<uint8_t n>
using portCn = pxn<0x06 + 0x20, n>;

using pc0_t = portCn<0>;
using pc1_t = portCn<1>;
using pc2_t = portCn<2>;
using pc3_t = portCn<3>;
using pc4_t = portCn<4>;
using pc5_t = portCn<5>;
using pc6_t = portCn<6>;

#if (__cplusplus >= 201703L)
inline constexpr pc0_t pc0;
inline constexpr pc1_t pc1;
inline constexpr pc2_t pc2;
inline constexpr pc3_t pc3;
inline constexpr pc4_t pc4;
inline constexpr pc5_t pc5;
inline constexpr pc6_t pc6;
#else
namespace {
constexpr auto& pc0{detail::global<pc0_t>::instance};
constexpr auto& pc1{detail::global<pc1_t>::instance};
constexpr auto& pc2{detail::global<pc2_t>::instance};
constexpr auto& pc3{detail::global<pc3_t>::instance};
constexpr auto& pc4{detail::global<pc4_t>::instance};
constexpr auto& pc5{detail::global<pc5_t>::instance};
constexpr auto& pc6{detail::global<pc6_t>::instance};
} //anonymous namespace
#endif

// Port D
//
// The following global object are defined to represent each pin of the
// I/O port D: pd0, pd1, pd2, pd3, pd4, pd5 and pd6.
//
// The port can also be accessed through the respective types, which
// are: pd0_t, pd1_t ,pd2_t, pd3_t, pd4_t, pd5_t and pd6_t.
//
// See pxn.hpp to know to use the abstraction.
//
template<uint8_t n>
using portDn = pxn<0x09 + 0x20, n>;

using pd0_t = portCn<0>;
using pd1_t = portCn<1>;
using pd2_t = portCn<2>;
using pd3_t = portCn<3>;
using pd4_t = portCn<4>;
using pd5_t = portCn<5>;
using pd6_t = portCn<6>;

#if (__cplusplus >= 201703L)
inline constexpr pd0_t pd0;
inline constexpr pd1_t pd1;
inline constexpr pd2_t pd2;
inline constexpr pd3_t pd3;
inline constexpr pd4_t pd4;
inline constexpr pd5_t pd5;
inline constexpr pd6_t pd6;
#else
namespace {
constexpr auto& pd0{detail::global<pd0_t>::instance};
constexpr auto& pd1{detail::global<pd1_t>::instance};
constexpr auto& pd2{detail::global<pd2_t>::instance};
constexpr auto& pd3{detail::global<pd3_t>::instance};
constexpr auto& pd4{detail::global<pd4_t>::instance};
constexpr auto& pd5{detail::global<pd5_t>::instance};
constexpr auto& pd6{detail::global<pd6_t>::instance};
} //anonymous namespace
#endif

}}

#pragma once

#include <avr/io/detail/global.hpp>
#include <avr/io/pxn.hpp>

namespace avr { namespace io {

// Port B
//
// The following global object are defined to represent each pin of the
// I/O port B: pb0, pb1, pb2, pb3, pb4 and pb5.
//
// The port can also be accessed through the respective types, which
// are: pb0_t, pb1_t ,pb2_t, pb3_t, pb4_t and pb5_t.
//
// See pxn.hpp to know to use the abstraction.
//
template<uint8_t n>
using portBn = pxn<0x16 + 0x20, n>;

using pb0_t = portBn<0>;
using pb1_t = portBn<1>;
using pb2_t = portBn<2>;
using pb3_t = portBn<3>;
using pb4_t = portBn<4>;
using pb5_t = portBn<5>;

#if (__cplusplus >= 201703L)
inline constexpr pb0_t pb0;
inline constexpr pb1_t pb1;
inline constexpr pb2_t pb2;
inline constexpr pb3_t pb3;
inline constexpr pb4_t pb4;
inline constexpr pb5_t pb5;
#else
namespace {
constexpr auto& pb0{detail::global<pb0_t>::instance};
constexpr auto& pb1{detail::global<pb1_t>::instance};
constexpr auto& pb2{detail::global<pb2_t>::instance};
constexpr auto& pb3{detail::global<pb3_t>::instance};
constexpr auto& pb4{detail::global<pb4_t>::instance};
constexpr auto& pb5{detail::global<pb5_t>::instance};
} //anonymous namespace
#endif

}}

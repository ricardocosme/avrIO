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
// are: Pb0, Pb1, Pb2, Pb3, Pb4 and Pb5.
//
// See pxn.hpp to know to use the abstraction.
//
template<uint8_t n>
using portBn = pxn<0x16 + 0x20, n>;

using Pb0 = portBn<0>;
using Pb1 = portBn<1>;
using Pb2 = portBn<2>;
using Pb3 = portBn<3>;
using Pb4 = portBn<4>;
using Pb5 = portBn<5>;

#if (__cplusplus >= 201703L)
inline constexpr Pb0 pb0;
inline constexpr Pb1 pb1;
inline constexpr Pb2 pb2;
inline constexpr Pb3 pb3;
inline constexpr Pb4 pb4;
inline constexpr Pb5 pb5;
#else
namespace {
constexpr auto& pb0{detail::global<Pb0>::instance};
constexpr auto& pb1{detail::global<Pb1>::instance};
constexpr auto& pb2{detail::global<Pb2>::instance};
constexpr auto& pb3{detail::global<Pb3>::instance};
constexpr auto& pb4{detail::global<Pb4>::instance};
constexpr auto& pb5{detail::global<Pb5>::instance};
} //anonymous namespace
#endif

}}

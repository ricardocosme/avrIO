#pragma once

#include <avr/io/detail/global.hpp>
#include <avr/io/pxn.hpp>

namespace avr { namespace io {

/** Port B

Implementation of the class template `pxn<n>` at
`avr/io/pxn.hpp`. Basic functions to operate port pins at
`avr/io/functions.hpp`.
*/
template<uint8_t n>
using portBn = pxn<0x16 + 0x20, n>;

/** Types to represent each port pin.

Besides the natural purpose of a type, like the usage of type traits
or something that is inherent to it, the types below are useful too to
instantiate objects that represents port pin but using the constructor
of the type to define the mode of operation of the pin, for example,
an object `pb3` can be an instantiation of `Pb3` that configures the
port pin to be an input port with the pull-up resistor activated:

avr::io::Pb3 pb3{avr::io::pullup};
*/
using Pb0 = portBn<0>;
using Pb1 = portBn<1>;
using Pb2 = portBn<2>;
using Pb3 = portBn<3>;
using Pb4 = portBn<4>;
using Pb5 = portBn<5>;

/** Global objects to represent each port pin.

These are intended to be used when the port pin doesn't need any
initialization, instead of something like `avr::io::Pb0 pb0{}`, a shorthand notation can be used: `avr::io::pb0`.
*/
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

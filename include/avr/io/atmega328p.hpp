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
using portBn = pxn<0x03 + 0x20, n>;

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
using Pb6 = portBn<6>;
using Pb7 = portBn<7>;

/** Global objects to represent each port pin.

These are intended to be used when the port pin doesn't need any
initialization, instead of something like `avr::io::Pb0 pb0{}`, a short
hand notation can be used: `avr::io::pb0`.
*/
#if (__cplusplus >= 201703L)
inline constexpr Pb0 pb0;
inline constexpr Pb1 pb1;
inline constexpr Pb2 pb2;
inline constexpr Pb3 pb3;
inline constexpr Pb4 pb4;
inline constexpr Pb5 pb5;
inline constexpr Pb6 pb6;
inline constexpr Pb7 pb7;
#else
namespace {
constexpr auto& pb0{detail::global<Pb0>::instance};
constexpr auto& pb1{detail::global<Pb1>::instance};
constexpr auto& pb2{detail::global<Pb2>::instance};
constexpr auto& pb3{detail::global<Pb3>::instance};
constexpr auto& pb4{detail::global<Pb4>::instance};
constexpr auto& pb5{detail::global<Pb5>::instance};
constexpr auto& pb6{detail::global<Pb6>::instance};
constexpr auto& pb7{detail::global<Pb7>::instance};
} //anonymous namespace
#endif

/** Port C

The same documentation to Port B applies here, see above.
*/
template<uint8_t n>
using portCn = pxn<0x06 + 0x20, n>;

using Pc0 = portCn<0>;
using Pc1 = portCn<1>;
using Pc2 = portCn<2>;
using Pc3 = portCn<3>;
using Pc4 = portCn<4>;
using Pc5 = portCn<5>;
using Pc6 = portCn<6>;

#if (__cplusplus >= 201703L)
inline constexpr Pc0 pc0;
inline constexpr Pc1 pc1;
inline constexpr Pc2 pc2;
inline constexpr Pc3 pc3;
inline constexpr Pc4 pc4;
inline constexpr Pc5 pc5;
inline constexpr Pc6 pc6;
#else
namespace {
constexpr auto& pc0{detail::global<Pc0>::instance};
constexpr auto& pc1{detail::global<Pc1>::instance};
constexpr auto& pc2{detail::global<Pc2>::instance};
constexpr auto& pc3{detail::global<Pc3>::instance};
constexpr auto& pc4{detail::global<Pc4>::instance};
constexpr auto& pc5{detail::global<Pc5>::instance};
constexpr auto& pc6{detail::global<Pc6>::instance};
} //anonymous namespace
#endif

/** Port D

The same documentation to Port B applies here, see above.
*/
template<uint8_t n>
using portDn = pxn<0x09 + 0x20, n>;

using Pd0 = portCn<0>;
using Pd1 = portCn<1>;
using Pd2 = portCn<2>;
using Pd3 = portCn<3>;
using Pd4 = portCn<4>;
using Pd5 = portCn<5>;
using Pd6 = portCn<6>;

#if (__cplusplus >= 201703L)
inline constexpr Pd0 pd0;
inline constexpr Pd1 pd1;
inline constexpr Pd2 pd2;
inline constexpr Pd3 pd3;
inline constexpr Pd4 pd4;
inline constexpr Pd5 pd5;
inline constexpr Pd6 pd6;
#else
namespace {
constexpr auto& pd0{detail::global<Pd0>::instance};
constexpr auto& pd1{detail::global<Pd1>::instance};
constexpr auto& pd2{detail::global<Pd2>::instance};
constexpr auto& pd3{detail::global<Pd3>::instance};
constexpr auto& pd4{detail::global<Pd4>::instance};
constexpr auto& pd5{detail::global<Pd5>::instance};
constexpr auto& pd6{detail::global<Pd6>::instance};
} //anonymous namespace
#endif

}}

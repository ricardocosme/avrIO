#pragma once

#include <avr/io/detail/global.hpp>
#include "avr/io/mcu/atmega328p/regs.hpp"
#include <avr/io/pin/pxn.hpp>

namespace avr { namespace io {

/** Port B

Implementation of the class template `pxn<n>` at
`avr/io/pin/pxn.hpp`. Basic functions to operate port pins at
`avr/io/pin/functions.hpp`.
*/
template<uint8_t n>
using portBn = pxn<portb_t, pinb_t, ddrb_t, n>;

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
AVR_IO_INLINE_GLOBAL_T(Pb0, pb0)
AVR_IO_INLINE_GLOBAL_T(Pb1, pb1)
AVR_IO_INLINE_GLOBAL_T(Pb2, pb2)
AVR_IO_INLINE_GLOBAL_T(Pb3, pb3)
AVR_IO_INLINE_GLOBAL_T(Pb4, pb4)
AVR_IO_INLINE_GLOBAL_T(Pb5, pb5)
AVR_IO_INLINE_GLOBAL_T(Pb6, pb6)
AVR_IO_INLINE_GLOBAL_T(Pb7, pb7)

/** Port C

The same documentation to Port B applies here, see above.
*/
template<uint8_t n>
using portCn = pxn<portc_t, pinc_t, ddrc_t, n>;

using Pc0 = portCn<0>;
using Pc1 = portCn<1>;
using Pc2 = portCn<2>;
using Pc3 = portCn<3>;
using Pc4 = portCn<4>;
using Pc5 = portCn<5>;
using Pc6 = portCn<6>;

AVR_IO_INLINE_GLOBAL_T(Pc0, pc0)
AVR_IO_INLINE_GLOBAL_T(Pc1, pc1)
AVR_IO_INLINE_GLOBAL_T(Pc2, pc2)
AVR_IO_INLINE_GLOBAL_T(Pc3, pc3)
AVR_IO_INLINE_GLOBAL_T(Pc4, pc4)
AVR_IO_INLINE_GLOBAL_T(Pc5, pc5)
AVR_IO_INLINE_GLOBAL_T(Pc6, pc6)

/** Port D

The same documentation to Port B applies here, see above.
*/
template<uint8_t n>
using portDn = pxn<portd_t, pind_t, ddrd_t, n>;

using Pd0 = portDn<0>;
using Pd1 = portDn<1>;
using Pd2 = portDn<2>;
using Pd3 = portDn<3>;
using Pd4 = portDn<4>;
using Pd5 = portDn<5>;
using Pd6 = portDn<6>;
using Pd7 = portDn<7>;

AVR_IO_INLINE_GLOBAL_T(Pd0, pd0)
AVR_IO_INLINE_GLOBAL_T(Pd1, pd1)
AVR_IO_INLINE_GLOBAL_T(Pd2, pd2)
AVR_IO_INLINE_GLOBAL_T(Pd3, pd3)
AVR_IO_INLINE_GLOBAL_T(Pd4, pd4)
AVR_IO_INLINE_GLOBAL_T(Pd5, pd5)
AVR_IO_INLINE_GLOBAL_T(Pd6, pd6)
AVR_IO_INLINE_GLOBAL_T(Pd7, pd7)

}}

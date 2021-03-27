#pragma once

#include "avr/io/detail/global.hpp"
#include "avr/io/mcu/attiny85/regs.hpp"
#include "avr/io/pin/pxn.hpp"

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

/** Global objects to represent each port pin.

These are intended to be used when the port pin doesn't need any
initialization, instead of something like `avr::io::Pb0 pb0{}`, a
shorthand notation can be used: `avr::io::pb0`.
*/
AVR_IO_INLINE_GLOBAL_T(Pb0, pb0)
AVR_IO_INLINE_GLOBAL_T(Pb1, pb1)
AVR_IO_INLINE_GLOBAL_T(Pb2, pb2)
AVR_IO_INLINE_GLOBAL_T(Pb3, pb3)
AVR_IO_INLINE_GLOBAL_T(Pb4, pb4)
AVR_IO_INLINE_GLOBAL_T(Pb5, pb5)

}}

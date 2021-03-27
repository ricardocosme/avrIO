#pragma once

#include "avr/io/detail/global.hpp"

/** Pin modes

    Tags to allow tag dispatching.
*/

namespace avr { namespace io {

/** Tag to represent the input mode with the pull-up resistor
    activated. */
struct pullup_t{};

/** Tag to represent the input mode with the pull-up resistor
    deactivated. */
struct input_t{};

/** Tag to represent the output mode. */
struct output_t{};

AVR_IO_INLINE_GLOBAL(pullup)
AVR_IO_INLINE_GLOBAL(input)
AVR_IO_INLINE_GLOBAL(output)

}}

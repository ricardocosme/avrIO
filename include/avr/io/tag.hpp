#pragma once

#include "avr/io/detail/global.hpp"

/** Tags to do tag dispatching. */

namespace avr { namespace io {

/** Tag to represent the input mode with the pull-up resistor
 * activated. */
struct pullup_t{};

/** Tag to represent the input mode with the pull-up resistor
 * deactivated. */
struct input_t{};

/** Tag to represent the output mode. */
struct output_t{};

#if (__cplusplus >= 201703L) //C++17/20
constexpr inline input_t input;
constexpr inline pullup_t pullup;
constexpr inline output_t output;
#else
namespace {
constexpr auto& input{detail::global<input_t>::instance};
constexpr auto& pullup{detail::global<pullup_t>::instance};
constexpr auto& output{detail::global<output_t>::instance};
} //anonymous namespace    
#endif

}}

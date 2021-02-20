#pragma once

#include "avr/io/detail/type_traits/integral_constant.hpp"

namespace avr { namespace io { namespace detail {

template<typename B, typename D>
struct is_base_of : integral_constant<bool, __is_base_of(B, D)> {};

}}}

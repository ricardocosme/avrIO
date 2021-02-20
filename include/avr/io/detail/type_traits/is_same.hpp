#pragma once

#include "avr/io/detail/type_traits/integral_constant.hpp"

namespace avr { namespace io { namespace detail {

template<typename, typename>
struct is_same : false_type {};

template<typename T>
struct is_same<T, T> : true_type {};

}}}

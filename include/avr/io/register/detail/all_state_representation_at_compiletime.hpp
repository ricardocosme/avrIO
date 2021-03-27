#pragma once

#include "avr/io/detail/type_traits/enable_if.hpp"

namespace avr { namespace io { namespace detail {

template<typename Bit, typename... Rest>
struct all_state_representation_at_compiletime {
    constexpr static bool value =
        all_state_representation_at_compiletime<Bit>::value
        && all_state_representation_at_compiletime<Rest...>::value;
};

template<typename Bit>
struct all_state_representation_at_compiletime<Bit>
{ constexpr static bool value = !Bit::representation_at_runtime; };


template<typename... Bits>
using enable_if_state_representation_at_runtime = enable_if_t<
    !all_state_representation_at_compiletime<Bits...>::value>;

template<typename... Bits>
using enable_if_state_representation_at_compiletime = enable_if_t<
    all_state_representation_at_compiletime<Bits...>::value>;

}}}

#pragma once

#include "avr/io/detail/type_traits/is_same.hpp"

namespace avr { namespace io { namespace detail {

template<typename... Bit>
struct belongs_same_reg;

template<typename Bit>
struct belongs_same_reg<Bit>
{ constexpr static bool value{true}; };

template<typename Bit, typename Bit2>
struct belongs_same_reg<Bit, Bit2> {
    constexpr static bool value = detail::is_same<
        typename Bit::reg, typename Bit2::reg>::value;
};

template<typename Bit, typename Bit2, typename... Bits>
struct belongs_same_reg<Bit, Bit2, Bits...> {
    constexpr static bool value =
        belongs_same_reg<Bit, Bit2>::value
        && belongs_same_reg<Bit2, Bits...>::value;
};

}}}

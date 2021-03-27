#pragma once

#include "avr/io/detail/type_traits/is_same.hpp"

namespace avr { namespace io { namespace detail {

template<typename Reg, typename Bit, typename... Bits>
struct belongs_to_reg {
    constexpr static bool value =
        belongs_to_reg<Reg, Bit>::value
        && belongs_to_reg<Reg, Bits...>::value;
};

template<typename Reg, typename Bit>
struct belongs_to_reg<Reg, Bit>
{ constexpr static bool value{detail::is_same<Reg, typename Bit::reg>::value}; };

}}}

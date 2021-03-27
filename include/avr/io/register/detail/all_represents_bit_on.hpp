#pragma once

namespace avr { namespace io { namespace detail {

template<typename Bit, typename... Bits>
struct all_represents_bit_on {
    constexpr static bool value =
        all_represents_bit_on<Bit>::value
        && all_represents_bit_on<Bits...>::value;
};

template<typename Bit>
struct all_represents_bit_on<Bit> {
    constexpr static bool value{Bit::represents_bit_on()};
};

}}}

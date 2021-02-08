#pragma once

#include "avr/io/detail/macros.hpp"

#include <stdint.h>

namespace avr { namespace io { namespace traits {

template<uint8_t bit_number>
struct bit_from_8bit_port
{ static constexpr bool value{bit_number >= 0 && bit_number <= 7}; };

template<typename T>
struct pin {
    template<typename T_>
#if __cplusplus > 201703L    
    requires (bit_from_8bit_port<T_::value>::value)
#endif
    auto number(const T_&) AVR_IO_DECLTYPE_AUTO_RETURN ( T_::value )

    template<typename T_>
    auto pinx(const T_& o) AVR_IO_DECLTYPE_AUTO_RETURN ( o.pin() )
        
    template<typename T_>
    auto ddrx(const T_& o) AVR_IO_DECLTYPE_AUTO_RETURN ( o.ddr() )
        
    template<typename T_>
    auto portx(const T_& o) AVR_IO_DECLTYPE_AUTO_RETURN ( o.port() )
};

}}}

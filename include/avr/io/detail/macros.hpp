#pragma once

namespace avr { namespace io { namespace detail {

#if (__cplusplus >= 201402L)
#define AVR_IO_CONSTEXPR_CTOR constexpr
#else
#define AVR_IO_CONSTEXPR_CTOR 
#endif

    
}}}

#pragma once

namespace avr { namespace io { namespace detail {

#if (__cplusplus >= 201402L)
#define AVR_IO_CONSTEXPR_CTOR constexpr
#else
#define AVR_IO_CONSTEXPR_CTOR 
#endif

#define AVR_IO_DECLTYPE_AUTO_RETURN(...)                        \
    -> decltype(__VA_ARGS__)                                    \
    { return (__VA_ARGS__); }                                   
    
}}}

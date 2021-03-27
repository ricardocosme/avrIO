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

#if __cplusplus > 201703L
#define AVR_IO_REQUIRES_CONCEPT_PIN requires avr::io::Pin<T>
#else
#define AVR_IO_REQUIRES_CONCEPT_PIN
#endif

#if __cplusplus > 201703L
#define AVR_IO_REQUIRES_CONCEPT_PINS requires (avr::io::Pin<Pins> && ...)
#else
#define AVR_IO_REQUIRES_CONCEPT_PINS
#endif

#if __cplusplus > 201703L
#define AVR_IO_REQUIRES_CONCEPT_BITS requires (avr::io::Bit<Bits> && ...)
#else
#define AVR_IO_REQUIRES_CONCEPT_BITS
#endif

#define AVR_IO_ALWAYS_INLINE [[gnu::always_inline]] inline

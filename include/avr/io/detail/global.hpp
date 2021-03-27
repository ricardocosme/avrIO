#pragma once

namespace avr { namespace io { namespace detail {

// [C++11/14] Workaround to allow global objects using header only
// sources.
template<typename T>
struct global
{ static constexpr T instance{}; };

template<typename T>
constexpr T global<T>::instance;

}}}

//Defines an inline constexpr global object of type <name>_t with name
//<name>.
#if __cplusplus >= 201703L
#define AVR_IO_INLINE_GLOBAL(name) \
inline constexpr name##_t name;
#else
#define AVR_IO_INLINE_GLOBAL(name) \
namespace { \
constexpr auto& name{detail::global<name##_t>::instance}; \
}
#endif

//Defines an inline constexpr global object of type <type> with name
//<name>.
#if __cplusplus >= 201703L
#define AVR_IO_INLINE_GLOBAL_T(type, name)     \
inline constexpr type name;
#else
#define AVR_IO_INLINE_GLOBAL_T(type, name)     \
namespace { \
constexpr auto& name{detail::global<type>::instance}; \
}
#endif


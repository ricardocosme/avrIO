#pragma once

#include "avr/io/detail/type_traits/integral_constant.hpp"

//FIXME
//Experimental draft

namespace std {
  template<typename... _Elements>
  struct tuple_size;

  template<unsigned long __i, typename... _Tail>
  struct tuple_element;
}

namespace avr { namespace io { namespace detail {

template<typename... Ts>
struct tup;

template<unsigned long Idx, typename... Elements>
struct tup_impl;

template<unsigned long Idx, typename T>
struct tup_impl<Idx, T> {
    tup_impl() = default;
    tup_impl(T o) : obj(o) {}
    static constexpr T& get(tup_impl& o) { return o.obj; }
    static constexpr const T& get(const tup_impl& o)  { return o.obj; }
    T obj;
};
    
template<unsigned long Idx, typename T, typename... Rest>
struct tup_impl<Idx, T, Rest...> : tup_impl<Idx + 1, Rest...> {
    tup_impl() = default;
    tup_impl(T o) : obj(o) {}
    static constexpr T& get(tup_impl& o) noexcept{ return o.obj; }
    static constexpr const T& get(const tup_impl& o) { return o.obj; }
    T obj;
};

template<typename... Ts>
struct tup : tup_impl<0, Ts...> {
    using base = tup_impl<0, Ts...>;
    using base::base;
};

}}}

template<typename... _Elements>
struct std::tuple_size<avr::io::detail::tup<_Elements...>>
    : public avr::io::detail::integral_constant<unsigned long, sizeof...(_Elements)> { };

template<unsigned long __i, typename _Head, typename... _Tail>
struct std::tuple_element<__i, avr::io::detail::tup<_Head, _Tail...> >
    : tuple_element<__i - 1, avr::io::detail::tup<_Tail...> > { };
template<typename _Head, typename... _Tail>
struct std::tuple_element<0, avr::io::detail::tup<_Head, _Tail...> >
{
    typedef _Head type;
};

namespace avr { namespace io { namespace detail {
template<unsigned long Idx, typename T, typename... Ts>
T get_helper(const tup_impl<Idx, T, Ts...>& o) {
    return tup_impl<Idx, T, Ts...>::get(o);
}

template<unsigned long Idx, typename... Ts>
typename std::tuple_element<Idx, tup<Ts...>>::type
get(const tup<Ts...>& o) {
    return get_helper<Idx>(o);
}

}}}

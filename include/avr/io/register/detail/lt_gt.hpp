#pragma once

namespace avr { namespace io {

/** Reg < int */
template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, Reg>::value,
    bool>
operator<(const Reg& lhs, int rhs)
{ return *lhs < rhs; }

/** int < Reg */
template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, Reg>::value,
    bool>
operator<(int lhs, const Reg& rhs)
{ return lhs < *rhs; }

/** Reg > int */
template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, Reg>::value,
    bool>
operator>(const Reg& lhs, int rhs)
{ return rhs < *lhs; }

/** int > Reg */
template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, Reg>::value,
    bool>
operator>(int lhs, const Reg& rhs)
{ return rhs < lhs; }

/** Reg <= int */
template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, Reg>::value,
    bool>
operator<=(const Reg& lhs, int rhs)
{ return !(rhs < lhs); }

/** int <= Reg */
template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, Reg>::value,
    bool>
operator<=(int lhs, const Reg& rhs)
{ return !(rhs < lhs); }

/** Reg >= int */
template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, Reg>::value,
    bool>
operator>=(const Reg& lhs, int rhs)
{ return !(lhs < rhs); }

/** int >= Reg */
template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, Reg>::value,
    bool>
operator>=(int lhs, const Reg& rhs)
{ return !(lhs < rhs); }

}}

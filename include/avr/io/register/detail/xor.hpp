#pragma once

namespace avr { namespace io {

/** Reg ^ int */
template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, Reg>::value,
    detail::reg_value_t<Reg>>
operator^(const Reg& lhs, int rhs)
{ return {static_cast<uint8_t>(*lhs ^ rhs)}; }

template<typename Reg>
detail::reg_value_t<Reg>
operator^(const detail::reg_value_t<Reg>& lhs, int rhs)
{ return {static_cast<uint8_t>(lhs.value ^ rhs)}; }

/** int ^ Reg */
template<typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, Reg>::value,
    detail::reg_value_t<Reg>>
operator^(int lhs, const Reg& rhs)
{ return {static_cast<uint8_t>(lhs ^ *rhs)}; }

template<typename Reg>
detail::reg_value_t<Reg>
operator^(int lhs, const detail::reg_value_t<Reg>& rhs)
{ return {static_cast<uint8_t>(lhs ^ rhs.value)}; }

/** RegBit ^ int */
template<typename LRegBit>
detail::enable_if_t<
    detail::is_base_of<detail::bit_base, LRegBit>::value,
    detail::reg_value_t<typename LRegBit::reg>>
operator^(const LRegBit& lhs, int rhs)
{ return {static_cast<uint8_t>(lhs.bv() ^ rhs)}; }

/** int ^ RegBit */
template<typename RRegBit>
detail::enable_if_t<
    detail::is_base_of<detail::bit_base, RRegBit>::value,
    detail::reg_value_t<typename RRegBit::reg>>
operator^(int lhs, const RRegBit& rhs)
{ return {static_cast<uint8_t>(lhs ^ rhs.bv())}; }

/** Reg ^ RegBit */
template<typename LReg, typename RRegBit>
detail::enable_if_t<
    detail::is_base_of<detail::bit_base, RRegBit>::value
    && detail::is_base_of<detail::reg_base, LReg>::value,
    detail::reg_value_t<typename RRegBit::reg>>
operator^(const LReg& lhs, const RRegBit& rhs) {
    static_assert(detail::is_same<LReg, typename RRegBit::reg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(*lhs ^ rhs.bv())};
}

template<typename RRegBit, typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::bit_base, RRegBit>::value,
    detail::reg_value_t<typename RRegBit::reg>>
operator^(detail::reg_value_t<Reg> lhs, const RRegBit& rhs) {
    static_assert(detail::is_same<typename detail::reg_value_t<Reg>::reg, typename RRegBit::reg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.value ^ rhs.bv())};
}


/** RegBit ^ Reg */
template<typename LRegBit, typename RReg>
detail::enable_if_t<
    detail::is_base_of<detail::bit_base, LRegBit>::value
    && detail::is_base_of<detail::reg_base, RReg>::value,
    detail::reg_value_t<typename LRegBit::reg>>
operator^(const LRegBit& lhs, const RReg& rhs) {
    static_assert(detail::is_same<typename LRegBit::reg, RReg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.bv() ^ *rhs)};
}

template<typename LRegBit, typename Reg>
detail::enable_if_t<
    detail::is_base_of<detail::bit_base, LRegBit>::value,
    detail::reg_value_t<typename LRegBit::reg>>
operator^(const LRegBit& lhs, detail::reg_value_t<Reg> rhs) {
    static_assert(detail::is_same<typename LRegBit::reg, typename detail::reg_value_t<Reg>::reg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.bv() ^ rhs.value)};
}

/** RegBit ^ RegBit */
template<typename LRegBit, typename RRegBit>
detail::enable_if_t<
    detail::is_base_of<detail::bit_base, LRegBit>::value
    && detail::is_base_of<detail::bit_base, RRegBit>::value,
    detail::reg_value_t<typename LRegBit::reg>>
operator^(const LRegBit& lhs, const RRegBit& rhs) {
    static_assert(detail::is_same<typename LRegBit::reg, typename RRegBit::reg>::value,
                  "Bits related to different registers.");
    return {static_cast<uint8_t>(lhs.bv() ^ rhs.bv())};
}

/** Reg ^ Reg */
template<typename LReg, typename RReg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, LReg>::value
    && detail::is_base_of<detail::reg_base, RReg>::value,
    detail::reg_value_t<LReg>>
operator^(const LReg& lhs, const RReg& rhs)
{ return {static_cast<uint8_t>(*lhs ^ *rhs)}; }

template<typename LReg, typename RReg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, LReg>::value,
    detail::reg_value_t<LReg>>
operator^(const LReg& lhs, const detail::reg_value_t<RReg>& rhs)
{ return {static_cast<uint8_t>(*lhs ^ rhs.value)}; }

template<typename LReg, typename RReg>
detail::enable_if_t<
    detail::is_base_of<detail::reg_base, RReg>::value,
    detail::reg_value_t<RReg>>
operator^(const detail::reg_value_t<LReg>& lhs, const RReg& rhs)
{ return {static_cast<uint8_t>(lhs.value ^ *rhs)}; }

template<typename LReg, typename RReg>
detail::reg_value_t<RReg>
operator^(const detail::reg_value_t<LReg>& lhs, const detail::reg_value_t<RReg>& rhs)
{ return {static_cast<uint8_t>(lhs.value ^ rhs.value)}; }

}}

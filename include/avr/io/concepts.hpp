#pragma once

namespace avr { namespace io {

template<int bit_number>
constexpr bool valid_bit_number{bit_number >= 0 && bit_number <= 7};

/** Concept to an IO register

    This specifies the constraints that a type should satisfy to model
    the concept of an IO register. For example, the abstractions 'reg'
    located at 'register/reg.hpp' models this concept.
 */
template<typename T>
concept Register =
    requires(T o) {

    /** memory address of the register */
    T::addr;

    /** volatile uint8_t& to read/write */
    {T::ref()};

    /** assignment operator to assign an uint8_t as a value to the
     * register. */
    { o = 0xff };
};

/** Concept to a bit of an IO register

    This specifies the constraints that a type should satisfy to model
    the concept of one bit of an IO register. The abstractions 'bit',
    'bit_state_as_bool' and 'bit_state_as_func' are examples of models
    of this concept.
 */
template<typename T>
concept Bit =
    requires {

    /** register which owns the bit */
    typename T::reg;

    /** bit position in the register 'T::reg'*/
    T::value; 
    
    /** 'true' if the bit state represented by 'T' is not know at
      compile-time and 'false' if the state can only be know at
      runtime. */
    T::representation_at_runtime;

    /** predicate that returns 'true' if the 'T' represents the state
        'on' and 'false' if it represents the state 'off' */
    {T::represents_bit_on()};

    //TODO: Replace this by a free function that receives the
    //represents_bit_on() and the T::value.
    /** byte value representation of the bit. If
        'T::represents_bit_on() == true' then 'bv() == (1<<T::value)
        otherwise 'bv() == ~(1<<value)'. */
    {T::bv()};
    
    }
    && valid_bit_number<T::value>
    && Register<typename T::reg>
;

/** Concept to a read/write IO port pin (Pxn) 
    
    This specifies the constraints that a type should satisfy to model
    the concept of a read/write IO port pin. One example of model is
    the class template 'pxn' located at 'pin/pxn.hpp'.
*/
template<typename T>
concept Pin =
    requires{
    T::value; /** bit number that represents the pin in the register PORTX*/
    typename T::portx; /** type that represents the register PORTX */
    typename T::pinx; /** type that represents the register PINX */
    typename T::ddrx; /** type that represents the register DDRX */
    }
    && valid_bit_number<T::value>
    && Bit<T>
    && Register<typename T::portx>
    && Register<typename T::pinx>
    && Register<typename T::ddrx>
;

}}

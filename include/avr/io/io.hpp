#pragma once

#include <avr/io/functions.hpp>
#include <avr/io/traits.hpp>

#ifdef __AVR_ATtiny85__
  #include <avr/io/attiny85.hpp>
#elif defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__)
  #include <avr/io/attiny13.hpp>
#elif defined(__AVR_ATmega328P__)
  #include <avr/io/atmega328p.hpp>
#endif

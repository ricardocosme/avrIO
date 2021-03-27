#pragma once

#include "avr/io/pin/functions.hpp"

#if defined(__AVR_ATmega328P__)
  #include <avr/io/mcu/atmega328p.hpp>
#elif defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__)
  #include <avr/io/mcu/attiny13a.hpp>
#elif defined(__AVR_ATtiny25__) \
    || defined(__AVR_ATtiny45__) \
    || defined(__AVR_ATtiny85__)
  #include <avr/io/mcu/attiny85.hpp>
#endif

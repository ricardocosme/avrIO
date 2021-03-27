#pragma once

#include <avr/io.h>

// The comments below have the purpose of relate a test with what we
// want to test in reg.cpp
void test_operations_with_sreg() {
    //operator=(uint8_t)
    SREG = 0x0f;
    
    //operator=(reg_bit_t)
    SREG = _BV(SREG_C);
    SREG = _BV(SREG_Z);
    SREG = _BV(SREG_N);
    SREG = _BV(SREG_V);
    SREG = _BV(SREG_S);
    SREG = _BV(SREG_H);
    SREG = _BV(SREG_T);
    SREG = _BV(SREG_I);
    
    //pxn::operator~
    SREG = ~(1<<SREG_C);
    
    SREG = _BV(SREG_N);
    SREG = _BV(SREG_Z) | _BV(SREG_T);
    SREG = _BV(SREG_C) | _BV(SREG_Z) | _BV(SREG_N) | _BV(SREG_V)
        | _BV(SREG_S) | _BV(SREG_H) | _BV(SREG_T) | _BV(SREG_I);
    
    //operator=(reg_value_t)
    //Reg | int
    SREG |= 0xf0;
    SREG |= 0x01 | 0xf0;
    //int | Reg
    SREG |= 0xf0;
    SREG |= 0x01 | 0xf0;
    //RegBit | int
    SREG = _BV(SREG_Z) | 0xff;
    SREG = _BV(SREG_Z) | _BV(SREG_T);
    //int | RegBit
    SREG = _BV(SREG_Z) | 0xff;
    SREG = _BV(SREG_Z) | _BV(SREG_T);
    
    //TODO: And what about var_reg_bit?
    
    //Reg | RegBit
    SREG |= _BV(SREG_I);
    //RegBit | Reg
    SREG |= _BV(SREG_I);
    //RegBit | RegBit
    SREG = _BV(SREG_Z) | _BV(SREG_T);
    
    //Reg | Reg
    SREG = (SREG | SREG) | 0x01;
    SREG = (SREG | (SREG | 0x02)) | 0x01;
    SREG = (SREG | (0x02 | SREG)) | 0x01;
    SREG = ((SREG | SREG) | (SREG | SREG));
    
    SREG = _BV(SREG_C) | _BV(SREG_Z) | _BV(SREG_N) | _BV(SREG_V)
        | _BV(SREG_S) | _BV(SREG_H) | _BV(SREG_T) | _BV(SREG_I);
    SREG = _BV(SREG_C) | _BV(SREG_Z) | _BV(SREG_I);
    SREG = _BV(SREG_C) | _BV(SREG_Z) | _BV(SREG_I);
        
    SREG |= 0xf0;
    SREG |= _BV(SREG_N);
    //sreg_n = true;
    SREG |= _BV(SREG_N);
    
    SREG |= _BV(SREG_Z) | _BV(SREG_T);
    SREG |= _BV(SREG_C) | _BV(SREG_Z) | _BV(SREG_N) | _BV(SREG_V)
        | _BV(SREG_S) | _BV(SREG_H) | _BV(SREG_T) | _BV(SREG_I);
    SREG |= _BV(SREG_V);
    SREG |= _BV(SREG_Z) | _BV(SREG_T);
    SREG |= _BV(SREG_C) | _BV(SREG_Z) | _BV(SREG_N) | _BV(SREG_V)
        | _BV(SREG_S) | _BV(SREG_H) | _BV(SREG_T) | _BV(SREG_I);
    SREG = _BV(SREG_Z) & _BV(SREG_T);
    SREG = _BV(SREG_Z) & _BV(SREG_T);
    SREG = _BV(SREG_Z) & _BV(SREG_T);
    SREG = _BV(SREG_C) & _BV(SREG_Z) & _BV(SREG_N) & _BV(SREG_V)
        & _BV(SREG_S) & _BV(SREG_H) & _BV(SREG_T) & _BV(SREG_I);
    SREG &= 0xf0;
    SREG &= 0xf0;
    SREG &= _BV(SREG_I);
    SREG &= _BV(SREG_I);
    SREG = _BV(SREG_C) & _BV(SREG_Z) & _BV(SREG_I);
    SREG = _BV(SREG_C) & _BV(SREG_Z) & _BV(SREG_I);
    SREG &= 0xf0;
    SREG &= _BV(SREG_N);
    SREG &= _BV(SREG_Z) | _BV(SREG_T);
    SREG &= _BV(SREG_C) | _BV(SREG_Z) | _BV(SREG_N) | _BV(SREG_V)
        | _BV(SREG_S) | _BV(SREG_H) | _BV(SREG_T) | _BV(SREG_I);
    SREG &= _BV(SREG_V);
    SREG &= _BV(SREG_Z) | _BV(SREG_T);
    SREG &= _BV(SREG_C) | _BV(SREG_Z) | _BV(SREG_N) | _BV(SREG_V)
        | _BV(SREG_S) | _BV(SREG_H) | _BV(SREG_T) | _BV(SREG_I);

    SREG = _BV(SREG_Z) ^ _BV(SREG_T);
    SREG = _BV(SREG_Z) ^ _BV(SREG_T);
    SREG = _BV(SREG_Z) ^ _BV(SREG_T);    
    SREG = _BV(SREG_C) ^ _BV(SREG_Z) ^ _BV(SREG_N) ^ _BV(SREG_V)
        ^ _BV(SREG_S) ^ _BV(SREG_H) ^ _BV(SREG_T) ^ _BV(SREG_I);
    SREG ^= 0xf0;
    SREG ^= 0xf0;
    SREG ^= _BV(SREG_I);
    SREG ^= _BV(SREG_I);
    SREG = _BV(SREG_C) ^ _BV(SREG_Z) ^ _BV(SREG_I);
    SREG = _BV(SREG_C) ^ _BV(SREG_Z) ^ _BV(SREG_I);
    
    SREG ^= 0xf0;
    SREG ^= _BV(SREG_N);
    SREG ^= _BV(SREG_Z) | _BV(SREG_T);
    SREG ^= _BV(SREG_C) | _BV(SREG_Z) | _BV(SREG_N) | _BV(SREG_V)
        | _BV(SREG_S) | _BV(SREG_H) | _BV(SREG_T) | _BV(SREG_I);
    SREG ^= _BV(SREG_V);
    SREG ^= _BV(SREG_Z) | _BV(SREG_T);
    SREG ^= _BV(SREG_C) | _BV(SREG_Z) | _BV(SREG_N) | _BV(SREG_V)
        | _BV(SREG_S) | _BV(SREG_H) | _BV(SREG_T) | _BV(SREG_I);

    //sreg = ~sreg;
    SREG = ~SREG;
    //sreg.set(sreg_z);
    SREG |= _BV(SREG_Z);
    //sreg.set(sreg_z, sreg_s, sreg_h, sreg_i);
    SREG |= _BV(SREG_Z) | _BV(SREG_S) | _BV(SREG_H) | _BV(SREG_I);
    //sreg.set(sreg_z, sreg_s(0), sreg_h, sreg_i(0));
    SREG = (SREG & ~(_BV(SREG_S) | _BV(SREG_I))) | (_BV(SREG_H) | _BV(SREG_Z));
    //sreg.set(sreg_s(off));
    SREG &= ~(_BV(SREG_S));
    //sreg.set(sreg_s(0), sreg_i(0));
    SREG &= ~(_BV(SREG_S) | _BV(SREG_I));
    //sreg.set(~n, ~v, i, t);
    SREG = (SREG & ~((1<<SREG_N) | (1<<SREG_V))) | (1<<SREG_I) | (1<<SREG_T);
    //set(~sreg_n, ~sreg_v, sreg_i, sreg_t);
    SREG = (SREG & ~((1<<SREG_N) | (1<<SREG_V))) | (1<<SREG_I) | (1<<SREG_T);
    
    SREG &= ~_BV(SREG_Z);
    SREG &= ~(_BV(SREG_Z) | _BV(SREG_S) | _BV(SREG_H) | _BV(SREG_I));
    SREG = (SREG & ~(_BV(SREG_Z) | _BV(SREG_H))) | (_BV(SREG_S) | _BV(SREG_I));
    SREG |= _BV(SREG_S) | _BV(SREG_I);
    //sreg.clear(sreg_s(0), sreg_i);
    SREG = (SREG & ~_BV(SREG_I)) | _BV(SREG_S);

    SREG = ~SREG;
    
    /** SREG = (SREG & ~(_BV(SREG_Z) | _BV(SREG_H))) | (_BV(SREG_S) | _BV(SREG_I)); */
    uint8_t reg;
    asm volatile(
        "in %0, __SREG__ \n"
        "andi %0, 0xdd \n"
        "ori %0, 0x90 \n"
        "out __SREG__, %0 \n"
        : "=r" (reg)
        );

    //reg_value_t::operator bool
    (void)bool(SREG & 1);
    //reg_t::operator bool
    (void)bool(SREG);
    //sreg_n.state();
    (void)(SREG & (1<<SREG_N));
    
    (void)(SREG == 0x0f);
    (void)(SREG == (SREG & 0xf0));
    (void)(SREG != 0x0f);
    (void)(SREG != (SREG & 0xf0));
    (void)(0x0f == SREG);
    (void)(0x0f != SREG);

    (void)(SREG > 1);
    (void)(SREG >= 1);
    (void)(SREG < 1);
    (void)(SREG <= 1);
}

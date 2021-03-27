#pragma once

#include <avr/io.hpp>

// This is a set of cases to test operations on IO register. We only
// use sreg register here because it is the one that is presented in
// all supported mcus.
void test_operations_with_sreg() {
    using namespace avr::io;
    //operator=(uint8_t)
    sreg = 0x0f;

    //operator=(reg_bit_t)
    sreg = sreg_c;
    sreg = sreg_z;
    sreg = sreg_n;
    sreg = sreg_v;
    sreg = sreg_s;
    sreg = sreg_h;
    sreg = sreg_t;
    sreg = sreg_i;

    //pxn::operator~
    sreg = ~sreg_c;
    
    sreg = {sreg_n};
    sreg = {sreg_z, sreg_t};
    sreg = {sreg_c, sreg_z, sreg_n, sreg_v, sreg_s, sreg_h,  sreg_t, sreg_i};
    
    //operator=(reg_value_t)
    //Reg | int
    sreg = sreg | 0xf0;
    sreg = (sreg | 0x01) | 0xf0;
    //int | Reg
    sreg = 0xf0 | sreg;
    sreg =  0xf0 | (sreg | 0x01);
    //RegBit | int
    sreg = sreg_z | 0xff;
    sreg = sreg_z | (1<<sreg_t.value);
    //int | RegBit
    sreg = 0xff | sreg_z;
    sreg = (1<<sreg_t.value) | sreg_z;

    //TODO: And what about var_reg_bit?

    //Reg | RegBit
    sreg = sreg | sreg_i;
    //RegBit | Reg
    sreg = sreg_i | sreg;
    //RegBit | RegBit
    sreg = sreg_z | sreg_t;

    //Reg | Reg
    sreg = (sreg | sreg) | 0x01;
    //Reg | RegValue
    sreg = (sreg | (sreg | 0x02)) | 0x01;
    //RegValue | Reg
    sreg = ((sreg | 0x02) | sreg) | 0x01;
    //RegValue | RegValue
    sreg = ((sreg | sreg) | (sreg | sreg));
    
    sreg = sreg_c | sreg_z | sreg_n | sreg_v | sreg_s | sreg_h |  sreg_t | sreg_i;
    sreg = (sreg_c | sreg_z) | sreg_i;
    sreg = sreg_i | (sreg_c | sreg_z);
    
    sreg |= 0xf0;
    sreg |= {sreg_n};
    sreg_n = true;
    sreg |= {sreg_z, sreg_t};
    sreg |= {sreg_c, sreg_z, sreg_n, sreg_v, sreg_s, sreg_h,  sreg_t, sreg_i};
    sreg |= sreg_v;
    sreg |= sreg_z | sreg_t;
    sreg |= sreg_c | sreg_z | sreg_n | sreg_v | sreg_s | sreg_h |  sreg_t | sreg_i;
    sreg = sreg_z & sreg_t;
    sreg = sreg_z & (1<<sreg_t.value);
    sreg = (1<<sreg_t.value) & sreg_z;
    sreg = sreg_c & sreg_z & sreg_n & sreg_v & sreg_s & sreg_h &  sreg_t & sreg_i;
    sreg = sreg & 0xf0;
    sreg = 0xf0 & sreg;
    sreg = sreg & sreg_i;
    sreg = sreg_i & sreg;
    sreg = (sreg_c & sreg_z) & sreg_i;
    sreg = sreg_i & (sreg_c & sreg_z);
    sreg &= 0xf0;
    sreg &= {sreg_n};
    sreg &= {sreg_z, sreg_t};
    sreg &= {sreg_c, sreg_z, sreg_n, sreg_v, sreg_s, sreg_h,  sreg_t, sreg_i};
    sreg &= sreg_v;
    sreg &= sreg_z | sreg_t;
    sreg &= sreg_c | sreg_z | sreg_n | sreg_v | sreg_s | sreg_h |  sreg_t | sreg_i;

    sreg = sreg_z ^ sreg_t;
    sreg = sreg_z ^ (1<<sreg_t.value);
    sreg = (1<<sreg_t.value) ^ sreg_z;
    sreg = sreg_c ^ sreg_z ^ sreg_n ^ sreg_v ^ sreg_s ^ sreg_h ^  sreg_t ^ sreg_i;
    sreg = sreg ^ 0xf0;
    sreg = 0xf0 ^ sreg;
    sreg = sreg ^ sreg_i;
    sreg = sreg_i ^ sreg;
    sreg = (sreg_c ^ sreg_z) ^ sreg_i;
    sreg = sreg_i ^ (sreg_c ^ sreg_z);
    
    sreg ^= 0xf0;
    sreg ^= {sreg_n};
    sreg ^= {sreg_z, sreg_t};
    sreg ^= {sreg_c, sreg_z, sreg_n, sreg_v, sreg_s, sreg_h,  sreg_t, sreg_i};
    sreg ^= sreg_v;
    sreg ^= sreg_z | sreg_t;
    sreg ^= sreg_c | sreg_z | sreg_n | sreg_v | sreg_s | sreg_h |  sreg_t | sreg_i;

    sreg = ~sreg;
    
    sreg.set(sreg_z);
    sreg.set(sreg_z, sreg_s, sreg_h, sreg_i);
    sreg.set(sreg_z, sreg_s(off), sreg_h, sreg_i(off));
    sreg.set(sreg_s(off));
    sreg.set(sreg_s(off), sreg_i(off));
    sreg.set(~sreg_n, ~sreg_v, sreg_i, sreg_t);
    set(~sreg_n, ~sreg_v, sreg_i, sreg_t);
    sreg.clear(sreg_z);
    sreg.clear(sreg_z, sreg_s, sreg_h, sreg_i);
    sreg.clear(sreg_z, sreg_s(off), sreg_h, sreg_i(off));
    sreg.clear(sreg_s(off), sreg_i(off));
    sreg.clear(sreg_s(off), sreg_i);

    sreg = ~sreg;
    sreg = (sreg & ~(sreg_z | sreg_h)) | (sreg_s | sreg_i);

    (void)bool(sreg & 1);
    (void)bool(sreg);
    (void)sreg_n.state();
        
    sreg == 0x0f;
    sreg == (sreg & 0xf0);
    sreg != 0x0f;
    sreg != (sreg & 0xf0);
    0x0f == sreg;
    0x0f != sreg;

    sreg > 1;
    sreg >= 1;
    sreg < 1;
    sreg <= 1;
}

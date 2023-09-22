stdcxx=c++17
mcu=attiny85

CXX=avr-g++
CC=avr-gcc
OBJCOPY=avr-objcopy
OBJDUMP=avr-objdump
INCLUDE=-I../../include
CXXFLAGS=-std=$(stdcxx) -mmcu=$(mcu) -Wall -Os $(INCLUDE)

all: pins.diff regs.diff

%.diff: pins.hex expected_pins.hex regs.hex expected_regs.hex
	diff pins.hex expected_pins.hex > pins.diff
	diff regs.hex expected_regs.hex > regs.diff

%.s: %.cpp
	$(CXX) $(CXXFLAGS) -S $^

%.hex: %.o
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

.PHONY: clean
clean:
	rm -f *.hex *.o *.s *.diff


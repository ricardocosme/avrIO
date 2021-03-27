stdcxx=c++17
mcu=atmega328p

all: pins.diff regs.diff

%.diff: pins.hex expected_pins.hex regs.hex expected_regs.hex
	diff pins.hex expected_pins.hex > pins.diff
	diff regs.hex expected_regs.hex > regs.diff

%.hex: %.o
	avr-objcopy -O ihex $< $@

%.s: %.o
	avr-objdump -d $< > $@

%.o: %.cpp
	avr-g++ -std=$(stdcxx) -Os -mmcu=$(mcu) -Wall -I../../include -c $<

.PHONY: clean
clean:
	rm -f *.hex *.o *.s *.diff


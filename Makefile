demos=demo/c++11 demo/c++17 demo/c++20
tests=test/attiny13a test/attiny85 test/atmega328p

all: demo test
demo: $(demos)
test: $(tests)

.PHONY: $(demos) $(tests)
$(demos) $(tests):
	make -C $@

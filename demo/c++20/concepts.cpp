#include <avr/io/io.hpp>

using namespace avr::io;

template<Pin Data>
struct sensor {
    sensor(Data pin) { /*...*/ }
};

int main() {
    sensor o{pb0};
}

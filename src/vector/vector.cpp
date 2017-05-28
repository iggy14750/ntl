

#include "vector.h"

vector::vector() {
    _size = 0;
    _capacity = 8;
}

vector::vector(int default_cap) {
    _size = 0;
    _capacity = default_cap;
}

int vector::size() {
    return _size;
}

int vector::capacity() {
    return _capacity;
}

/* Implementation of a string class, the interface of which is
 * defined in `string.h`. */

#include "string.h"
#include <cstdio>
#include <cstring>


string::string() {
    _base = NULL;
    _length = 0;
    _capacity = 0;
}

string::~string() {
    if (_base != NULL) {
        delete _base;
    }
}

string::string(const char * def) {
    // count length of def
    _length = std::strlen(def);
    if (_length == 0) {
        // no heap allocation for empty strings
        _base = NULL;
        _capacity = 0;
        return;
    }
    // allocate heap buffer.
    _base = new char[_capacity = _length + 1];
    // copy elements into it
    std::strcpy(_base, def);
    _base[_length] = '\0';
}


void string::append(string s) {
    
    if (_base == NULL) {
        // should probably just farm out to a copy constructor
        _length = s.length();
        _capacity = _length + 1;
        _base = new char[_capacity];
        std::strcpy(_base, s.c_str());
        return;
    }
    // Now we can assume this is a non-empty string.
    _capacity += s.length();
    char* temp = new char[_capacity];
    std::strcpy(temp, _base);
    delete _base;
    std::strcpy(temp + _length, s.c_str());
    _length = _capacity - 1;
    _base = temp;
}

int string::length() const {
    return _length;
}

char* string::c_str() const {
    return _base;
}

bool operator == (string a, string b) {
    // Quick bail out.
    if (a.length() != b.length()) return false;
    const char* x = a.c_str();
    const char* y = b.c_str();
    // Empty strings have NULL c_str's
    if (x == NULL || y == NULL) return true;
    for (int i = 0; x[i]; i++) {
        if (x[i] != y[i]) return false;
    }
    return true;
}

bool operator != (string a, string b) {
    return !(a == b);
}
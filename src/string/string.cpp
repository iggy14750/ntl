
#include "string.h"
/* Implementation of a string class, the interface of which is
 * defined in `string.h`. */
#define NULL 0

string::string() {
    _base = NULL;
    _length = 0;
}

string::string(const char * def) {
    // count length of def
    for (_length = 0; def[_length]; _length++);
    // allocate heap buffer.
    _base = new char[_length + 1];
    // copy elements into it
    for (int i = 0; def[i]; i++) {
        _base[i] = def[i];
    }
    _base[_length] = '\0';
}

int string::length() const {
    return _length;
}

char* string::c_str() const {
    return _base;
}

bool operator==(string a, string b) {
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
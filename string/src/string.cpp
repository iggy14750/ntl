
/* Implementation of a string class, the interface of which is
 * defined in `string.h`. */

#include "string.h"
#include <cstdio>
#include <cstring>
using namespace ntl;

string::string() {
    clear();
}

string::~string() {
    clean_up();
}

string::string(const string& s) {
    copy(s.c_str(), s.length());
}

string::string(const char * s) {
    copy(s, std::strlen(s));
}

string& string::operator=(const string& s) {
    copy(s.c_str(), s.length());
    return *this;
}

void string::append(const string& s) {
    
    if (_base == nullptr) {
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
    delete[] _base;
    std::strcpy(temp + _length, s.c_str());
    _length = _capacity - 1;
    _base = temp;
}

int string::length() const {
    return _length;
}

const char* string::c_str() const {
    return _base;
}

bool ntl::operator == (const string& a, const string& b) {
    // Quick bail out.
    if (a.length() != b.length()) return false;
    const char* x = a.c_str();
    const char* y = b.c_str();
    // Empty strings have NULL c_str's
    if (x == nullptr || y == nullptr) return true;
    for (int i = 0; x[i]; i++) {
        if (x[i] != y[i]) return false;
    }
    return true;
}

bool ntl::operator != (const string& a, const string& b) {
    return !(a == b);
}

/* PRIVATE HELPER FUNCTIONS */

// safely deallocates heap data
void string::clean_up() {
    if (_base != nullptr) {
        delete[] _base;
    }
}

// sets data to defaults to represent empty strings
void string::clear() {
    _base = nullptr;
    _length = _capacity = 0;
}

// abstracts over the common copy pattern.
void string::copy(const char* s, int len) {
    clean_up();

    if (s == nullptr) {
        clear();
        return;
    }
    _length = len;
    _capacity = _length + 1;
    _base = new char[_capacity];
    std::strcpy(_base, s);
    _base[_capacity] = '\0';
}
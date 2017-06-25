
/* Implementation of a string class, the interface of which is
 * defined in `string.h`. */

#include <cstdio>
#include <cstring>
#include <stdexcept>

#include "assert.h"
#include "string.h"

using namespace ntl;

#define BUFF_SIZE 512
static char buff[BUFF_SIZE];

/* Constructs an empty string, allocating no dynamic memory. */
string::string() {
    clear();
}

/* Deep copy from another string; (possibly) allocates new dynamic memory.
 * No new memory is allocated if an "empty" (length 0) string is passed in.
 */
string::string(const string& s) {
    clear();
    copy(s.c_str(), s.length());
}

/* Constructs string instance from a *valid non-null c-string*. */
string::string(const char * s) {
    if (s == nullptr)
        throw std::invalid_argument("input must be non-null");
    unsigned int len = std::strlen(s);
    if (len == 0)
        clear();
    else
        copy(s, len);
}

/* Assigns this stirng object to be semantically equivalent to another.
 * Possibly allocates dynamic memory, distinct from that owned by the other string.
 */
string& string::operator=(const string& s) {
    if (this != &s)
        copy(s.c_str(), s.length());
    return *this;
}


/* De-allocates dynamic memory, if this object owns any. */
string::~string() {
    clean_up();
}

/* Returns the character at the position "pos". */
char& string::operator [] (size_t pos) {
    if (pos > _length) {
        snprintf(buff, BUFF_SIZE, "Invalid position: %d\n", pos);
        throw std::out_of_range(buff);
    }
    return _base[pos];
}

/* A const method which returns the character at position "pos". */
const char& string::operator [] (size_t pos) const {
    if (pos > _length) {
        snprintf(buff, BUFF_SIZE, "Invalid position: %d\n", pos);
        throw std::out_of_range(buff);
    }
    return _base[pos];
}

/* Appends the content of "s" to the end of this object.
 * May allocate new heap data.
 */
void string::append(const string& s) {
    
    // Quick bail for empty strings.
    if (s.length() == 0) return;
    
    // Need to allocate new heap memory
    if (_length + s.length() + 1 > _capacity) {
        unsigned int new_capacity = _length + s.length() + 1;
        unsigned int len = _length;
        char* temp = new char[new_capacity];
        std::strcpy(temp, _base);
        clean_up();
        _base = temp;
        _capacity = new_capacity;
        _length = len;
    }

    // We can now assume _capacity is sufficient.
    std::strcpy(_base + _length, s.c_str());
    _length += s.length();
}

/* Returns the number of semantic characters in the string.
 * Does not count NUL terminal.
 */
unsigned int string::length() const {
    ASSERT(std::strlen(_base) == _length);
    return _length;
}

/* Returns a pointer to a valid c-string, with the same data as this object. */
const char* string::c_str() const {
    ASSERT(_base != nullptr);
    return _base;
}

/* Returns true iff the sequence of characters these 
 * two strings represent are exactly the same.*/
bool ntl::operator == (const string& a, const string& b) {
    // Quick bail out.
    if (a.length() != b.length()) return false;
    const char* x = a.c_str();
    const char* y = b.c_str();
    for (int i = 0; x[i]; i++) {
        if (x[i] != y[i]) return false;
    }
    return true;
}

/* Returns the inverse of the equality operator. */
bool ntl::operator != (const string& a, const string& b) {
    return !(a == b);
}

/* PRIVATE HELPER FUNCTIONS */

/* Safely deallocates heap data, assuming "_base" not garbage. */
void string::clean_up() {
    if (_base != &empty_str) {
        delete[] _base;
        clear();
    }
}

/* Sets data to defaults to represent empty strings.
 * Assumes "_base" is not currently pointing to data owned by this object.
 */
void string::clear() {
    _base = &empty_str;
    _length = _capacity = 0;
}


/* Copies data from s into memory owned by this object destructively.
 * Relies on a number of assumptions:
 * 1. Param "s" is NON-NULL, and points to a valid, nul-terminated c-string.
 * 2. Param "len" accurately counts the number of bytes needed to represent
 *      the data in "s", not including a NUL-terminal char.
 * 3. No data is currently owned by this object. New memory will (probably) be allocated.
 */
void string::copy(const char* s, unsigned int len) {
    ASSERT(s != nullptr);
    ASSERT(std::strlen(s) == len);

    _length = len;
    _capacity = _length + 1;
    _base = new char[_capacity];
    std::strcpy(_base, s);
}
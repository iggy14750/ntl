

/*
 * My `string` class definition. The implementation 
 * of which is in the file `string.cpp`.
*/
#ifndef __STRING_H__ 
#define __STRING_H__ 

namespace ntl {

class string {
    char* _base;
    int _length;
    int _capacity;
public:
    string();
    ~string();
    // copy constructor
    string(const string&);
    // assignment operator
    string& operator = (const string&);
    // conversion from c_str
    string(const char* def);
    int length() const;
    const char* c_str() const;
    void append(const string&);
};

bool operator == (const string& a, const string& b);
bool operator != (const string& a, const string& b);
} /* namespace ntl */

#endif
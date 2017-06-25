

/*
 * My `string` class definition. The implementation 
 * of which is in the file `string.cpp`.
*/
#ifndef __STRING_H__ 
#define __STRING_H__ 

namespace ntl {

class string {
    char* _base;
    unsigned int _length;
    unsigned int _capacity;
    char empty_str = '\0';

    void clean_up();
    void clear();
    void copy(const char*, unsigned int);
public:
    string();
    string(const string&);
    string(const char* def);
    string& operator = (const string&);
    ~string();

    char& operator [] (size_t);
    const char& operator [] (size_t) const;
    void append(const string&);
    const char* c_str() const;
    unsigned int length() const;
};

bool operator == (const string& a, const string& b);
bool operator != (const string& a, const string& b);
} /* namespace ntl */

#endif


/*
 * My `string` class definition. The implementation 
 * of which is in the file `string.cpp`.
*/
#ifndef __STRING_H__ 
#define __STRING_H__ 

class string {
    char* _base;
    int _length;
    int _capacity;
public:
    string();
    ~string();
    string(const char* def);
    int length() const;
    char* c_str() const;
    void append(string);
};

bool operator == (string a, string b);
bool operator != (string a, string b);

#endif
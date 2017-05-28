

#ifndef __VECTOR_H__
#define __VECTOR_H__

class vector {
    int _capacity;
    int _size;
public:
    vector();
    vector(int def_cap);
    int size();
    int capacity();
};

#endif
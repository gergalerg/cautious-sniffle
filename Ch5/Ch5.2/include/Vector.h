#ifndef __Vector_h_
#define __Vector_h_

#include <vector>

template <typename T>
struct Vector {
private:
    int sz;
    T* elem;
public:
    Vector(int s) : sz{s}, elem{new T[s]{0} } {}
    T& operator[](int );
    int size() const;
};

#endif

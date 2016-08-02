#ifndef __Vector_h_
#define __Vector_h_


template <typename T>
struct Vector {
private:
    int sz;
    T* elem;
public:
    Vector(int s) : sz{s}, elem{new T[s]{0} } {}
    T& operator[](int t) { return elem[t]; }
    int size() const { return sz; }
};

#endif

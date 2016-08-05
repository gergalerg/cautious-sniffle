#ifndef __Vector_h_
#define __Vector_h_

#include <stdexcept>

template <typename T>
struct Vector {
private:
    int sz;
    T* elem;
public:
    Vector(int); 
    T& operator[](int );
    T& operator*() const { return *this; }
    int size() const;
    int* begin() const { return elem; }
    int* end() const { return (elem + (size() -1)); }
};

template <typename T>
int Vector<T>::size() const { return sz; }

template <typename T>
Vector<T>::Vector(int s) : sz {s} { 
    if (s < 0)
        throw std::length_error{"Length error"};
    elem = new T[s];
    sz = s;
}

template <typename T>
T& Vector<T>::operator[](int i) { 
    if (i < 0 || Vector<T>::size() <= i)
        throw std::out_of_range("Vector<T>::operator[]");
    return elem[i]; }

#endif

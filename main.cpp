#include <iostream>
#include <vector>
#include "Vector.h"


template <typename T>
void vector_init(Vector<T>& v, int s)
{
    v.elem = new T[s];
    v.sz = s;
}

template <typename T>
auto read_and_sum(const Vector<T>& v) -> T
{
    T sum = 0;
    const int size = v.size();
    for (int i = 0; i != size; ++i)
        sum += v[i];
    return sum;
}

enum class Color { red, blue = 10 , yellow };

Color& operator++(Color& r)
{
    switch(r) {
        case Color::red: return r = Color::blue;
        case Color::blue: return  r = Color::yellow;
        case Color::yellow: return r = Color::red;
    }
}

int main(int argc, char const *argv[])
{
    Vector<int> v1(10);
    v1[0]= 100;
    for (int i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << "\t";
    }

    return 0;
}
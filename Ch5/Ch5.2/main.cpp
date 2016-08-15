#include <iostream>
#include <vector>
#include <numeric>
#include <vector>
#include <string>
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
    return r;
}

template <typename T>
void f(Vector<T>& v)
{
    try {
        v[v.size()-1] = 7;
    } catch (std::out_of_range) {
        throw std::out_of_range("Vector: operator[]");
    }

}

int main(int argc, char const *argv[])
{
    Vector<int> v1(10);
    Vector<std::string> vs(32);
    for (auto& x : vs) x = "A";

    f2(vs);
    std::cout << "\n\n";
    return 0;
}
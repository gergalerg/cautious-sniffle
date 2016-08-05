#include <iostream>
#include <vector>
#include <numeric>
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


template <typename T>
void light_speed(T speed) 
{
    const T local_speed = static_cast<const T>(speed);
    const T C   = static_cast<const T>(299792.458);
    const T local_max = static_cast<const T>( 160.0/(60*60) ); // 160 km/h == 160.0 / 60*60 km/s
    static_assert(local_max < C, "Can't go that fast");
    std::cout << "You're going << " << local_speed << "\n";
}
int main(int argc, char const *argv[])
{
    /*
    Vector<int> v1(10);
    std::iota(&v1[0], &v1[9], 1);
    v1[9] = 100;
    std::cout << v1[9] << "\n";
    std::cout << "Begin: " << v1.begin() << " end: " << v1.end() << "\n";
    for (int i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << "\t";
    }
    f(v1);
    */
    light_speed(15000);



    std::cout << "\n\n";
    return 0;
}
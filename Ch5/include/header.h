#ifndef _HEADER_H_
#define _HEADER_H_

#include <vector>
#include <memory>

template <typename T>
struct Shape {
    T _x;
    T _y;
public:
    Shape () {}
    Shape(T x, T y) : _x(x),_y(y) {}
    ~Shape() {}
    void draw() { std::cout << "x: " << _x << " y: " << _y << "\n";}
};

template <typename T, int N>
struct Buffer {
    using value_type = T;
    constexpr int size() { return N; }
};

// 5.5 Function objects
template <typename T>
class Less_than {
    const T val; // value to compare against
public:
    Less_than(const T& v) : val(v) {}
    bool operator()(const T& x) const { return x < val; }
};

template <typename C, typename P>
int counter(const C& c, P pred)
{
    int count =0;
    for (const auto& x : c)
        if (pred(x))
            ++count;

    return count;


}

template <typename C, typename Oper>
void for_all(C& c, Oper op)
{
    for (auto& x: c)
        op(*x);
}
#endif
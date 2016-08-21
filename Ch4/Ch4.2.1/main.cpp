#include <iostream>
#include <list>
#include "complex.h"

// Ch 5.3 

template <typename Container, typename Value>
Value sum(const Container& c, Value v)
{
    for (auto x: c)
        v += x;
    return v;
}

static int count = 0;

int main(int argc, char const *argv[])
{
    Complex<double> z1 = 3.14;
    Complex<double> z2 = z1*2;
    //std::list<Complex<double>> lc {};
    std::list<int> ld;
    while (count != 10) 
        ld.push_back(++count);

    int res = sum(ld, 0);

    for  (auto z1: ld) std::cout << z1 << "\n";
    std::cout << "res = " << res << "\n";
    return 0;
}
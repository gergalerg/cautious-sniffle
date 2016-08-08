#include <iostream>
#include "complex.h"


int main(int argc, char const *argv[])
{
    Complex<double> x1(1,2);
    Complex<double> x2(100,400);
    Complex<double> res;
    res = x1 * x2;
    std::cout << res;
    return 0;
}
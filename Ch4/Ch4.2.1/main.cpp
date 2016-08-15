#include <iostream>
#include "complex.h"


int main(int argc, char const *argv[])
{
    Complex<double> z1 = 3.14;
    Complex<double> z2 = z1*2;
    std::cout << z2;
    return 0;
}
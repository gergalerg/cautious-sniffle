#include "Vector.h"

void f2(Vector<std::string>& vs)
{
    std::cout << "This is from source vector.cpp\n";
    int count = 0;
    for (auto& s : vs) {
        if (count % 8 == 0 && count != 0) std::cout << "\n";
        ++count;
        std::cout << s << "\t";
    }

    std::cout << "\n";
}


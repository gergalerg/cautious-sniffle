#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<double> v1;
    for (double d; std::cin >> d;) {
        while (d) 
            v1.push_back(d);
        break;
    }
    return 0;
}
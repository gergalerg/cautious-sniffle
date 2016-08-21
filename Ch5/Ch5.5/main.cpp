#include <iostream>
#include <vector>
#include "header.h"

int main(int argc, char const *argv[])
{
    std::vector<std::unique_ptr<Shape<int>>> v;
    for (int i =0; i<10; i++) {
        std::unique_ptr<Shape<int>> si(new Shape<int>{3+i,4+i});
        v.push_back(std::move(si));
    }

    for_all(v, [](Shape<int>& s) { s.draw(); });

    return 0;
}
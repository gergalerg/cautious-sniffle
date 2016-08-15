#include <iostream>

struct X{
    int data = 0;
    X printer() { return *this; }
};

int main(int argc, char const *argv[])
{
    X x;
    X x1 = x.printer();
    return 0;
}
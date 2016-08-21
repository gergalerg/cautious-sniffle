#include <iostream>

void f() {}

static int count = 0;

template <typename T, typename... Tail>
void f(T head, Tail... tail)
{
    count += 1;
    std::cout << count << " : " << head << "\n";
    f(tail...);
}

int main(int argc, char const *argv[])
{
    f(1, 3.0, "Nice one", 'c');
    return 0;
}
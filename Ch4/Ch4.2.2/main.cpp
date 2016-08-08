#include <iostream>

template <typename T>
class Vector {
private:
    T* elem;
    int sz;
public:
    Vector(int s) : elem{ new T[s]{0}}, sz{s} {}
    ~Vector() { delete[] elem; }
    T& operator[](int i) { return elem[i]; }
    int size() const { return sz; }
};

#define SIZE 10

int main(int argc, char const *argv[])
{
    Vector<double> v1{SIZE};
    for (int i = 0; i < SIZE; i++) {
        std::cout << v1[i] << "\t";
    }
    std::cout << "\n";
    return 0;
}
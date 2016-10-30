#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct Matrix
{
    T data;
    Matrix(int x) : data(x) {}
    Matrix& operator+(const Matrix<T>& m1) { data = m1.data + data; return *this; }
    //Matrix operator+(const Matrix<T>& m1, const Matrix<T>& m2) { data = m1.data + m2.data; return *this; }
};

void fp(int* t){
    if (t == nullptr)
        std::cout << "Nullptr!\n";
    else
        std::cout << "else called t = " << *t;
}

int main(int argc, char const *argv[])
{
    int* t = new int(3);
    fp(t);
}
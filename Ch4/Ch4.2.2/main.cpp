#include <iostream>
#include <fstream>
#include <vector>
#include <initializer_list>

template <typename T>
class Vector {
private:
    T* elem;
    int sz;
public:
    Vector(std::initializer_list<T> lst) : elem{ new T[lst.size()]{0}}, 
        sz{static_cast<T>(lst.size())} { std::copy(lst.begin(), lst.end(), elem); }
    ~Vector() { delete[] elem; }
    T& operator[](int i) { return elem[i]; }
    int size() const { return sz; }

    void push_back(T t) { }
    void Printer();
};

template <typename T>
void Vector<T>::Printer() { for (int i = 0; i < sz; i++) std::cout << elem[i] << "\t"; }

#define SIZE 10

int main(int argc, char const *argv[])
{
    std::cout << "\n";

    std::initializer_list<int> l = {1,2,3,4,5,6,7,8,9,10};
    //std::initializer_list<int>::iterator it = l.begin();
    Vector<int> v1(l);
    std::cout << "Vector copy to int[]\n";
    std::cout << "\n";
    v1.Printer();
    return 0;
}
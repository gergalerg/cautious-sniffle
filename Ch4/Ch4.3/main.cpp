#include <iostream>
#include <vector>
#include <initializer_list>
#include <list>

template <typename T>
class Container {
public:
    virtual T& operator[](int) = 0; // pure virtual function
    virtual int size() const = 0; // const member function
    virtual ~Container() {} // destructor
};

template <typename T>
class Vector_container : public Container<T> {
    std::vector<T> v{0};
public:
    Vector_container(int s) : v(s) {}
    Vector_container(std::initializer_list<T> lst) : v(lst) {}
    ~Vector_container() {}

    T& operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};

template <typename T>
class List_container : public Container<T> {
    std::list<T> ld{0};
    int sz;
public:
    List_container(std::initializer_list<T> il) : ld(il), sz(il.size()) {}
    ~List_container() {}

    T& operator[](int i) { return ; }
    int size() const { return sz; }
};

template <typename T>
void use(Container<T>& c) 
{
    const int sz = c.size();

    for (int i  = 0; i != sz; ++i) 
        std::cout << c[i] << '\t';
}

int main(int argc, char const *argv[])
{
    
    std::initializer_list<double> lst {1,2,3,4,5,6,7,8,9,10};
    Vector_container<double> vc1(lst); 
    std::initializer_list<int> lst2 {1,2,3,4,5,6,7,8,9,10};
    List_container<int> lc1(lst2);
    use(vc1);
    std::cout << "\n";
    return 0;
}

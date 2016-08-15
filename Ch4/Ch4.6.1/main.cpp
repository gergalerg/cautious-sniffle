#include <iostream>
#include <stdexcept>

class Vector {
private:
    double* elem; // elem points to an array of sz doubles
    int sz;
public:
    Vector(int s) : elem{ new double[sz] }, sz{s} {}
    ~Vector() {  }

    Vector(const Vector& a); // Copy constructor
    Vector& operator=(const Vector& a);

    Vector(Vector&& a) : elem{a.elem}, sz{a.sz}{ 
        std::cout << "Move Ctor called\n"; a.elem = nullptr; a.sz =0; } //move Ctor
    Vector& operator=(Vector&& a) { std::cout << "Move assign called\n";
        Vector res = Vector(std::move(a)); return res; } // Move assignment

    double& operator[](int i) { return elem[i]; }
    const double& operator[](int i) const { return elem[i]; }

    int size() const { return sz; }
    void Printer() { for (int i=0;i!=sz;++i) std::cout << elem[i] << "\t"; }
};

Vector::Vector(const Vector& a)  // Copy constructor
    : elem{new double[a.sz]},   // allocate space for elements
    sz{a.sz}
{
    for (int i = 0; i != sz; ++i)
        elem[i] = a.elem[i];
}

Vector& Vector::operator=(const Vector& a)
{
    double* p = new double[a.sz];
    for (int i=0; i!=a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;          // delete old elements
    elem = p;
    sz = a.sz;
    return *this;
}

Vector operator+(const Vector& a, const Vector& b)  // Moving containers
{
    if (a.size() != b.size())
        throw std::out_of_range("Out of range"); 
    Vector res(a.size());
    for (int i=0; i<a.size(); ++i)
        res[i] = a[i] + b[i];
    return res;
}

int main(int argc, char const *argv[])
{
    Vector v1{10}; 
    v1[3] = 3.0;
    Vector v2 = v1;

    v1.Printer();
    std::cout << "\n";
    v2.Printer();
    std::cout << "\n";

    Vector v3 =  Vector{10};
    v3.Printer();
    std::cout << "\n";
    return 0;
}
#ifndef __complex_h_
#define __complex_h_
#include <iostream>

template <typename T>
class Complex {
    T re, im;
public:
    Complex(T r, T i) : re{r}, im{i} {} // construct complex from 2 scalars
    Complex(T r) : re{r}, im{0} {}      // construct complex from 1 scalar
    Complex() : re{0}, im{0} {}

    T real() const { return re; }
    void real(T d) { re = d; }
    double imag() const { return im; }
    void imag(T d) { im = d; }

    Complex& operator+=(Complex z) { re += z.re, im += z.im; return *this; }
    Complex& operator-=(Complex z) { re -= z.re, im-=z.im; return *this; }

    Complex& operator*=(Complex);  // defined out of class somewhere
    Complex& operator/=(Complex);

    Complex operator*(Complex<T> a) { return *this*=a; }

    bool operator!=(Complex<T> a) { return !(*this == a); }
    bool operator==(Complex<T> a) { return (*this == a); }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Complex<U>& t);
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const Complex<U>& t) {
    os << "(" << t.re << " + " << t.im << "i)\n";
    return os;
}

template <typename T>
inline Complex<T>& Complex<T>::operator*=(Complex<T> lhs) {
    re = re * lhs.re;
    im =  im * lhs.im;
    return *this;
}
#endif
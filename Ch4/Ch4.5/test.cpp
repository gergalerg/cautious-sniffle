#include <iostream>
#include <memory>

class Shape
{
};

std::unique_ptr<Shape> read_shape()
{
    return std::unique_ptr<Shape>{new Shape() };
}

int main(int argc, char const *argv[])
{
    std::unique_ptr<Shape> s = read_shape();
    return 0;
}
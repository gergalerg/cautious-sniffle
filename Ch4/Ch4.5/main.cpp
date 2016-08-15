#include <iostream>
#include <vector>
#include <utility>

class Point {
private:
    int _x, _y;
public:
    Point() : _x(0), _y(0) {}
    Point(int x, int y) : _x(x), _y(y) {}
};

class Shape {
public: 
    virtual Point center() const =0; // pure virtual
    virtual void move(Point to) =0;

    virtual void draw() const =0;
    virtual void rotate(int angle) =0;
    virtual ~Shape() {}  // Destructor
};

class Circle : public Shape {
    Point _p;
    int radius;
public:
    Circle(Point p, int rr) : _p{p}, radius{rr} {}
    Point center() const { return _p; }
    void move(Point to) { _p = to; }

    void draw() const {}
    void rotate(int t) { std::cout << "Circle::rotate called: " << t << " degrees\n"; }
    ~Circle() {}
};

class Smiley : public Circle {
public:
    Smiley(Point p, int r) : Circle{p, r}, mouth{nullptr} {}
    ~Smiley();

    void move(Point to) override { Circle::move(to); }

    void draw() const override;
    void rotate(int) override {}

    void add_eye(Shape* s) { eyes.push_back(s); }
    void set_mouth(Shape* s);
    virtual void wink(int i) {} // Wink eye number i
private:
    std::vector<Shape*> eyes;
    Shape* mouth;
};

Smiley::~Smiley() 
{
    delete mouth;
    for (auto p : eyes)
        delete p;
}

void Smiley::draw() const
{
    Circle::draw();
    for (auto p : eyes)
        p->draw();
    mouth->draw();
}
template <typename T>
void rotate_all(std::vector<T *>& v, int angle) 
{
    for (auto p:v)
        p->rotate(angle);
}

int main(int argc, char const *argv[])
{
    std::vector<Circle*> circle_vector;
    Point p1(3,4);
    Point p2(6,8);
    Circle c1(p1, 10); 
    Circle c2(p2, 10);
    circle_vector.push_back(&c1);
    circle_vector.push_back(&c2);
    rotate_all(circle_vector, 3);
    return 0;
    return 0;
}
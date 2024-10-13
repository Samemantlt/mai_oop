#include "Triangle.h"

Triangle::Triangle(const Point& a, const Point& b, const Point& c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

void Triangle::print(std::ostream &output) const {
    output << "Triangle {A = " << a << "; B = " << b << "; C = " << c << "}";
}

void Triangle::read(std::istream &input) {
    input >> a >> b >> c;
}

bool Triangle::operator==(const Triangle &other) const {
    return Figure::operator==(other);
}

std::vector<Point> Triangle::getPoints() const {
    return {a, b, c};
}

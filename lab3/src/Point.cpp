#include "Figure.h"

#include <math.h>

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

double Point::get_x() const { return x; }

void Point::set_x(double value) { x = value; }

double Point::get_y() const { return y; }

void Point::set_y(double value) { y = value; }

double Point::length() const {
  return std::sqrt(x * x + y * y);
}

std::ostream &operator<<(std::ostream &output, const Point &point) {
  output << "(" << point.get_x() << "; " << point.get_y() << ")";
  return output;
}

std::istream &operator>>(std::istream &input, Point &point) {
  input >> point.x >> point.y;
  return input;
}

Point Point::operator-() const{
  return Point(-x, -y);
}

Point Point::operator-=(Point& other) {
  x -= other.x;
  y -= other.y;
  return *this;
}

Point Point::operator+=(Point& other){
  x += other.x;
  y += other.y;
  return *this;
}

Point operator+(Point& other, Point& other2) {
  Point result(other);
  result += other2;
  return result;
}

Point operator-(Point& other, Point& other2) {
  Point result(other);
  result -= other2;
  return result;
}

bool Point::operator==(const Point &other) const {
  return x == other.x && y == other.y;
}

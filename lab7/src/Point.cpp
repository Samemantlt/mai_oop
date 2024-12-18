// Point class was almost fully copied from lab3

#include "Point.h"

#include <cmath>

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(Scalar x, Scalar y) {
	this->x = x;
	this->y = y;
}

Point::Scalar Point::get_x() const { return x; }

void Point::set_x(Scalar value) { x = value; }

Point::Scalar Point::get_y() const { return y; }

void Point::set_y(Scalar value) { y = value; }

double Point::length() const {
	return std::sqrt(x * x + y * y);
}

std::ostream& operator<<(std::ostream& output, const Point& point) {
	output << point.get_x() << " " << point.get_y();
	return output;
}

std::istream& operator>>(std::istream& input, Point& point) {
	input >> point.x >> point.y;
	return input;
}

Point Point::operator-() const {
	return Point(-x, -y);
}

Point Point::operator-=(const Point& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Point Point::operator+=(const Point& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Point operator+(const Point& other, const Point& other2) {
	Point result = other;
	result += other2;
	return result;
}

Point operator-(const Point& other, const Point& other2) {
	Point result(other);
	result -= other2;
	return result;
}

bool Point::operator==(const Point& other) const {
	return x == other.x && y == other.y;
}

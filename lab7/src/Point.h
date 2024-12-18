// Point class was almost fully copied from lab3

#pragma once

#include <iostream>

class Point {
public:
	using Scalar = int;
	
	Point();

	explicit Point(Scalar x, Scalar y);

	[[nodiscard]] Scalar get_x() const;
	void set_x(Scalar value);

	[[nodiscard]] Scalar get_y() const;
	void set_y(Scalar value);

	[[nodiscard]] double length() const;

	friend std::ostream& operator<<(std::ostream& output, const Point& point);
	friend std::istream& operator>>(std::istream& input, Point& point);

	Point operator-() const;
	Point operator-=(const Point& other);
	Point operator+=(const Point& other);

	friend Point operator+(const Point& other, const Point& other2);
	friend Point operator-(const Point& other, const Point& other2);

	bool operator==(const Point& other) const;

private:
	Scalar x, y;
};
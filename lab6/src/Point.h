// Point class was almost fully copied from lab3

#pragma once

#include <iostream>

class Point {
public:
	Point();

	explicit Point(double x, double y);

	[[nodiscard]] double get_x() const;
	void set_x(double value);

	[[nodiscard]] double get_y() const;
	void set_y(double value);

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
	double x, y;
};
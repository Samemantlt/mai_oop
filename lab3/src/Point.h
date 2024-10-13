#pragma once

#include <iostream>

class Point {
public:
    Point();

    explicit Point(double x, double y);

    [[nodiscard]] double getX() const;
    void setX(double value);

    [[nodiscard]] double getY() const;
    void setY(double value);

    [[nodiscard]] double length() const;

    friend std::ostream &operator<<(std::ostream &output, const Point &point);
    friend std::istream &operator>>(std::istream &input, Point &point);

    Point operator-() const;
    Point operator-=(Point& other);
    Point operator+=(Point& other);

    friend Point operator+(Point& other, Point& other2);
    friend Point operator-(Point& other, Point& other2);

    bool operator==(const Point& other) const;

private:
    double x, y;
};
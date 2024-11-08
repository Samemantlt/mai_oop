#pragma once

#include "Point.h"

#include <cmath>

template<Scalar T>
Point<T>::Point() {
    x = 0;
    y = 0;
}

template<Scalar T>
Point<T>::Point(T x, T y) {
    this->x = x;
    this->y = y;
}

template<Scalar T>
T Point<T>::get_x() const { return x; }

template<Scalar T>
void Point<T>::set_x(T value) { x = value; }

template<Scalar T>
T Point<T>::get_y() const { return y; }

template<Scalar T>
void Point<T>::set_y(T value) { y = value; }

template<Scalar T>
T Point<T>::length() const {
    return std::sqrt(x * x + y * y);
}

template<Scalar U>
std::ostream &operator<<(std::ostream &output, const Point<U> &point) {
    output << "(" << point.get_x() << "; " << point.get_y() << ")";
    return output;
}

template<Scalar U>
std::istream &operator>>(std::istream &input, Point<U> &point) {
    U x, y;
    input >> x >> y;
    point.set_x(x);
    point.set_y(y);
    return input;
}

template<Scalar T>
Point<T> Point<T>::operator-() const{
    return Point<T>(-x, -y);
}

template<Scalar T>
Point<T> Point<T>::operator-=(Point<T>& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

template<Scalar T>
Point<T> Point<T>::operator+=(Point<T>& other){
    x += other.x;
    y += other.y;
    return *this;
}

template<Scalar T>
Point<T> operator+(Point<T>& other, Point<T>& other2) {
    Point<T> result(other);
    result += other2;
    return result;
}

template<Scalar T>
Point<T> operator-(Point<T>& other, Point<T>& other2) {
    Point<T> result(other);
    result -= other2;
    return result;
}

template<Scalar T>
bool Point<T>::operator==(const Point<T> &other) const {
    return x == other.x && y == other.y;
}

#pragma once

#include <iostream>

template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
class Point {
public:
    Point();

    explicit Point(T x, T y);

    [[nodiscard]] T getX() const;
    void setX(T value);

    [[nodiscard]] T getY() const;
    void setY(T value);

    [[nodiscard]] T length() const;

    template <Scalar U>
    friend std::ostream &operator<<(std::ostream &output, const Point &point);

    template <Scalar U>
    friend std::istream &operator>>(std::istream &input, Point &point);

    Point operator-() const;
    Point operator-=(Point& other);
    Point operator+=(Point& other);

    template <Scalar U>
    friend Point<U> operator+(Point<U>& other, Point<U>& other2);

    template <Scalar U>
    friend Point<U> operator-(Point<U>& other, Point<U>& other2);

    bool operator==(const Point& other) const;

private:
    T x, y;
};


// Implementation

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
T Point<T>::getX() const { return x; }

template<Scalar T>
void Point<T>::setX(T value) { x = value; }

template<Scalar T>
T Point<T>::getY() const { return y; }

template<Scalar T>
void Point<T>::setY(T value) { y = value; }

template<Scalar T>
T Point<T>::length() const {
    return std::sqrt(x * x + y * y);
}

template<Scalar U>
std::ostream &operator<<(std::ostream &output, const Point<U> &point) {
    output << "(" << point.getX() << "; " << point.getY() << ")";
    return output;
}

template<Scalar U>
std::istream &operator>>(std::istream &input, Point<U> &point) {
    U x, y;
    input >> x >> y;
    point.setX(x);
    point.setY(y);
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

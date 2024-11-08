#pragma once

#include <iostream>

template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
class Point {
public:
    Point();

    explicit Point(T x, T y);

    [[nodiscard]] T get_x() const;
    void set_x(T value);

    [[nodiscard]] T get_y() const;
    void set_y(T value);

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

// Include implementation explicitly because header file contains templates
#include "Point.ipp"

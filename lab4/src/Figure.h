#pragma once

#include "Point.h"

#include <iostream>
#include <vector>

template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    [[nodiscard]] virtual T getSize() const;
    [[nodiscard]] virtual Point<T> getCenter() const;

    virtual void print(std::ostream& output) const = 0;
    virtual void read(std::istream& input) = 0;

    template<Scalar U>
    friend std::ostream &operator<<(std::ostream &output, const Figure<U> &figure);

    template<Scalar U>
    friend std::istream &operator>>(std::istream &input, Figure<U> &figure);

    explicit operator T() const;

    bool operator==(const Figure& other) const;

protected:
    Figure() = default;

    [[nodiscard]] virtual std::vector<Point<T>> getPoints() const = 0;
};


// Implementation

template<Scalar U>
std::ostream &operator<<(std::ostream &output, const Figure<U> &figure) {
    figure.print(output);
    return output;
}

template<Scalar U>
std::istream &operator>>(std::istream &input, Figure<U> &figure) {
    figure.read(input);
    return input;
}

template<Scalar T>
T Figure<T>::getSize() const {
    std::vector<Point<T>> points = getPoints();

    if (points.size() < 3) {
        return 0.0; // Return 0 if the polygon has less than 3 points
    }

    T area{};
    for (size_t i = 0; i < points.size(); ++i) {
        const Point<T> &p1 = points[i];
        const Point<T> &p2 = points[(i + 1) % points.size()];
        area += (p1.getX() * p2.getY()) - (p2.getX() * p1.getY());
    }

    return 0.5 * (area >= 0 ? area : -area);
}

template<Scalar T>
Point<T> Figure<T>::getCenter() const {
    Point<T> result;
    int count = 0;

    for (auto point : getPoints()) {
        count++;
        result += point;
    }

    return Point<T>(result.getX() / count, result.getY() / count);
}

template<Scalar T>
Figure<T>::operator T() const {
    return getSize();
}

template<Scalar T>
bool Figure<T>::operator==(const Figure<T> &other) const {
    return getPoints() == other.getPoints();
}

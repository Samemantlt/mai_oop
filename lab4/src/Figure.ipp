#pragma once

#include "Figure.h"

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
T Figure<T>::get_size() const {
    std::vector<Point<T>> points = get_points();

    if (points.size() < 3) {
        return 0.0; // Return 0 if the polygon has less than 3 points
    }

    T area{};
    for (size_t i = 0; i < points.size(); ++i) {
        const Point<T> &p1 = points[i];
        const Point<T> &p2 = points[(i + 1) % points.size()];
        area += (p1.get_x() * p2.get_y()) - (p2.get_x() * p1.get_y());
    }

    return 0.5 * (area >= 0 ? area : -area);
}

template<Scalar T>
Point<T> Figure<T>::get_center() const {
    Point<T> result;
    int count = 0;

    for (auto point : get_points()) {
        count++;
        result += point;
    }

    return Point<T>(result.get_x() / count, result.get_y() / count);
}

template<Scalar T>
Figure<T>::operator T() const {
    return get_size();
}

template<Scalar T>
bool Figure<T>::operator==(const Figure<T> &other) const {
    return get_points() == other.get_points();
}

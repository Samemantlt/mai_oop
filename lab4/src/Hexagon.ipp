#pragma once

#include "Hexagon.h"

template<Scalar T>
Hexagon<T>::Hexagon() {
    for (size_t i = 0; i < points.size(); i++) {
        points[i] = std::make_unique<Point<T>>();
    }
}

template<Scalar T>
Hexagon<T>::Hexagon(const std::initializer_list<Point<T>> &points) {
    if (points.size() != PointsCount)
        throw std::runtime_error("Passed points list has invalid length");

    size_t i = 0;
    for (auto point : points) {
        this->points[i++] = std::make_unique<Point<T>>(point);
    }
}

template<Scalar T>
void Hexagon<T>::print(std::ostream &output) const {
    output << "Hexagon {A = " << *points[0]
        << "; B = " << *points[1]
        << "; C = " << *points[2]
        << "; D = " << *points[3]
        << "; E = " << *points[4]
        << "; F = " << *points[5]
        << "}";
}

template<Scalar T>
void Hexagon<T>::read(std::istream &input) {
    for (auto & point : points)
        input >> *point;
}

template<Scalar T>
std::vector<Point<T>> Hexagon<T>::get_points() const {
    std::vector<Point<T>> output;
    for (const auto& point : points) {
        output.push_back(*point);
    }
    return output;
}

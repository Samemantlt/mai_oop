#pragma once

#include "Figure.h"

#include <array>

template<Scalar T>
class Octagon : public Figure<T> {
public:
    static constexpr int PointsCount = 8;

    Octagon();
    Octagon(const std::initializer_list<Point<T>>& points);

    void print(std::ostream& output) const override;
    void read(std::istream& input) override;

    Octagon& operator=(const Octagon& other) = default;
    Octagon& operator=(Octagon&& other) = default;

protected:
    [[nodiscard]] std::vector<Point<T>> getPoints() const override;
private:
    std::array<std::unique_ptr<Point<T>>, PointsCount> points;
};


// Implementation

template<Scalar T>
Octagon<T>::Octagon() {
    for (size_t i = 0; i < points.size(); i++) {
        points[i] = std::make_unique<Point<T>>();
    }
}

template<Scalar T>
Octagon<T>::Octagon(const std::initializer_list<Point<T>> &points) {
    if (points.size() != PointsCount)
        throw std::runtime_error("Passed points list has invalid length");

    size_t i = 0;
    for (auto point : points) {
        this->points[i++] = std::make_unique<Point<T>>(point);
    }
}

template<Scalar T>
void Octagon<T>::print(std::ostream &output) const {
    output << "Octagon {A = " << *points[0]
        << "; B = " << *points[1]
        << "; C = " << *points[2]
        << "; D = " << *points[3]
        << "; E = " << *points[4]
        << "; F = " << *points[5]
        << "; G = " << *points[6]
        << "; H = " << *points[7]
        << "}";
}

template<Scalar T>
void Octagon<T>::read(std::istream &input) {
    for (auto & point : points)
        input >> *point;
}

template<Scalar T>
std::vector<Point<T>> Octagon<T>::getPoints() const {
    std::vector<Point<T>> output;
    for (const auto& point : points) {
        output.push_back(*point);
    }
    return output;
}
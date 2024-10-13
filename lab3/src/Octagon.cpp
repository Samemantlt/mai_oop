#include "Octagon.h"

Octagon::Octagon(const std::initializer_list<Point> &points) {
    if (points.size() != PointsCount)
        throw std::runtime_error("Passed points list has invalid length");

    std::copy(points.begin(), points.end(), this->points.begin());
}

void Octagon::print(std::ostream &output) const {
    output << "Octagon {A = " << points[0]
        << "; B = " << points[1]
        << "; C = " << points[2]
        << "; D = " << points[3]
        << "; E = " << points[4]
        << "; F = " << points[5]
        << "; G = " << points[6]
        << "; H = " << points[7]
        << "}";
}

void Octagon::read(std::istream &input) {
    for (auto & point : points)
        input >> point;
}

std::vector<Point> Octagon::getPoints() const {
    return {points.begin(), points.end()};
}

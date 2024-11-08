#include "Hexagon.h"

Hexagon::Hexagon(const std::initializer_list<Point> &points) {
    if (points.size() != PointsCount)
        throw std::runtime_error("Passed points list has invalid length");

    std::copy(points.begin(), points.end(), this->points.begin());
}

void Hexagon::print(std::ostream &output) const {
    output << "Hexagon {A = " << points[0]
        << "; B = " << points[1]
        << "; C = " << points[2]
        << "; D = " << points[3]
        << "; E = " << points[4]
        << "; F = " << points[5]
        << "}";
}

void Hexagon::read(std::istream &input) {
    for (auto & point : points)
        input >> point;
}

std::vector<Point> Hexagon::get_points() const {
    return {points.begin(), points.end()};
}

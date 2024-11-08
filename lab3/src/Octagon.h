#pragma once

#include "Figure.h"

#include <array>

class Octagon : public Figure {
public:
    static constexpr int PointsCount = 8;

    Octagon() = default;
    Octagon(const std::initializer_list<Point>& points);

    void print(std::ostream& output) const override;
    void read(std::istream& input) override;

    Octagon& operator=(const Octagon& other) = default;
    Octagon& operator=(Octagon&& other) = default;

protected:
    [[nodiscard]] std::vector<Point> get_points() const override;
private:
    std::array<Point, PointsCount> points;
};
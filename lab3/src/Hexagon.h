#pragma once

#include "Figure.h"

#include <array>

class Hexagon : public Figure {
public:
    static constexpr int PointsCount = 6;

    Hexagon() = default;
    Hexagon(const std::initializer_list<Point>& points);

    void print(std::ostream& output) const override;
    void read(std::istream& input) override;

    Hexagon& operator=(const Hexagon& other) = default;
    Hexagon& operator=(Hexagon&& other) = default;

protected:
    [[nodiscard]] std::vector<Point> getPoints() const override;
private:
    std::array<Point, 6> points;
};
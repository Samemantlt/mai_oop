#pragma once

#include "Figure.h"

#include <array>
#include <memory>

template<Scalar T>
class Hexagon : public Figure<T> {
public:
    static constexpr int PointsCount = 6;

    Hexagon();
    Hexagon(const std::initializer_list<Point<T>>& points);

    void print(std::ostream& output) const override;
    void read(std::istream& input) override;

    Hexagon& operator=(const Hexagon& other) = default;
    Hexagon& operator=(Hexagon&& other) = default;

protected:
    [[nodiscard]] std::vector<Point<T>> getPoints() const override;
private:
    std::array<std::unique_ptr<Point<T>>, PointsCount> points;
};

// Include implementation explicitly because header file contains templates
#include "Hexagon.ipp"

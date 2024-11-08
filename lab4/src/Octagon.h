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

// Include implementation explicitly because header file contains templates
#include "Octagon.ipp"

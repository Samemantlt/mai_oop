#pragma once

#include "Figure.h"

class Triangle : public Figure {
public:
    // using Figure::getSize, Figure::getCenter, Figure::operator==;

    Triangle() = default;;
    explicit Triangle(const Point& a, const Point& b, const Point& c);

    void print(std::ostream& output) const override;
    void read(std::istream& input) override;

    Triangle& operator=(const Triangle& other) = default;
    Triangle& operator=(Triangle&& other) = default;

    bool operator==(const Triangle &) const;

protected:
    [[nodiscard]] std::vector<Point> getPoints() const override;
private:
    Point a, b, c;
};
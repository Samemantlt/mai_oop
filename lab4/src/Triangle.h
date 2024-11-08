#pragma once

#include <memory>

#include "Figure.h"

template<Scalar T>
class Triangle : public Figure<T> {
public:
    Triangle();
    explicit Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c);

    void print(std::ostream& output) const override;
    void read(std::istream& input) override;

    Triangle& operator=(const Triangle& other) = default;
    Triangle& operator=(Triangle&& other) = default;

protected:
    [[nodiscard]] std::vector<Point<T>> get_points() const override;
private:
    std::unique_ptr<Point<T>> a, b, c;
};

// Include implementation explicitly because header file contains templates
#include "Triangle.ipp"

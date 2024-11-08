#pragma once

#include "Point.h"

#include <iostream>
#include <vector>

template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    [[nodiscard]] virtual T get_size() const;
    [[nodiscard]] virtual Point<T> get_center() const;

    virtual void print(std::ostream& output) const = 0;
    virtual void read(std::istream& input) = 0;

    template<Scalar U>
    friend std::ostream &operator<<(std::ostream &output, const Figure<U> &figure);

    template<Scalar U>
    friend std::istream &operator>>(std::istream &input, Figure<U> &figure);

    explicit operator T() const;

    bool operator==(const Figure& other) const;

protected:
    Figure() = default;

    [[nodiscard]] virtual std::vector<Point<T>> get_points() const = 0;
};

// Include implementation explicitly because header file contains templates
#include "Figure.ipp"

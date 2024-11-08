#pragma once

#include "Point.h"

#include <iostream>
#include <vector>

class Figure {
public:
    virtual ~Figure() = default;

    [[nodiscard]] virtual double getSize() const;
    [[nodiscard]] virtual Point getCenter() const;

    virtual void print(std::ostream& output) const = 0;
    virtual void read(std::istream& input) = 0;

    friend std::ostream &operator<<(std::ostream &output, const Figure &figure);
    friend std::istream &operator>>(std::istream &input, Figure &figure);

    explicit operator double() const;

    bool operator==(const Figure& other) const;

protected:
    Figure() = default;

    [[nodiscard]] virtual std::vector<Point> getPoints() const = 0;
};

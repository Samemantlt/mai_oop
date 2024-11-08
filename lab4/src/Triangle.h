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
    [[nodiscard]] std::vector<Point<T>> getPoints() const override;
private:
    std::unique_ptr<Point<T>> a, b, c;
};


// Implementation

template<Scalar T>
Triangle<T>::Triangle() {
    this->a = std::make_unique<Point<T>>();
    this->b = std::make_unique<Point<T>>();
    this->c = std::make_unique<Point<T>>();
}

template<Scalar T>
Triangle<T>::Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    this->a = std::make_unique<Point<T>>(a);
    this->b = std::make_unique<Point<T>>(b);
    this->c = std::make_unique<Point<T>>(c);
}

template<Scalar T>
void Triangle<T>::print(std::ostream &output) const {
    output << "Triangle {A = " << *a << "; B = " << *b << "; C = " << *c << "}";
}

template<Scalar T>
void Triangle<T>::read(std::istream &input) {
    input >> *a >> *b >> *c;
}

template<Scalar T>
std::vector<Point<T>> Triangle<T>::getPoints() const {
    return {*a, *b, *c};
}

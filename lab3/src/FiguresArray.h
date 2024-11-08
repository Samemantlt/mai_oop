#pragma once

#include <memory>

#include "Figure.h"

class FiguresArray {

public:
    FiguresArray() = default;

    ~FiguresArray() = default;

    void push_back(const std::shared_ptr<Figure> &figure);

    void remove_at(size_t index);

    size_t size() const;

    std::shared_ptr<Figure> operator[](size_t index) const;

    // Iterator support
    std::vector<std::shared_ptr<Figure>>::iterator begin() { return figures.begin(); }
    std::vector<std::shared_ptr<Figure>>::iterator end() { return figures.end(); }

private:
    std::vector<std::shared_ptr<Figure>> figures;
};

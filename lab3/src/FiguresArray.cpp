#include "FiguresArray.h"

void FiguresArray::push_back(const std::shared_ptr<Figure> &figure) {
    figures.push_back(figure);
}

void FiguresArray::remove_at(size_t index) {
    figures.erase(std::next(figures.begin(), index));
}

size_t FiguresArray::size() const {
    return figures.size();
}

std::shared_ptr<Figure> FiguresArray::operator[](size_t index) const {
    return figures[index];
}

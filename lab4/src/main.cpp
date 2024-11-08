#include <iostream>

#include "Figure.h"
#include "Hexagon.h"
#include "Triangle.h"
#include "Octagon.h"

#include <memory>

#include "Array.h"

#define ScalarType double

template<Scalar T>
std::shared_ptr<Figure<T>> readFigureFromConsole();

int main() {
    Array<std::shared_ptr<Figure<ScalarType>>> figures;

    while (true) {
        std::cout << "Commands:" << std::endl
            << "p - Print all figures (coordinates, center, size)" << std::endl
            << "a - Add new figure" << std::endl
            << "r - Remove figure" << std::endl
            << "s - Calculate size of a figure" << std::endl
            << "S - Calculate size of all figures" << std::endl
            << "g - Calculate center of a figure" << std::endl
            << "e - Exit" << std::endl
            << "Enter command: ";
        char command;
        std::cin >> command;

        switch (command) {
            case 'p': {
                std::cout << "All figures : {" << std::endl;
                for (const auto& f : figures) {
                    std::cout << "\t" << *f << ": { center() = " << f->getCenter() << ", size() = " << f->getSize() << " }," << std::endl;
                }
                std::cout << "}" << std::endl;
                break;
            }
            case 'a': {
                auto newFigure = readFigureFromConsole<ScalarType>();
                if (newFigure == nullptr) {
                    std::cout << "Not added!" << std::endl;
                    break;
                }
                figures.push_back(std::move(newFigure));
                std::cout << "Added!" << std::endl;
                break;
            }
            case 'r': {
                int index;
                std::cout << "Enter index: ";
                std::cin >> index;
                if (index >= figures.size() || index < 0) {
                    std::cout << "Index out of range" << std::endl;
                    break;
                }

                figures.remove_at(index);
                std::cout << "Removed" << std::endl;
                break;
            }
            case 's': {
                int index;
                std::cout << "Enter index: ";
                std::cin >> index;
                if (index >= figures.size() || index < 0) {
                    std::cout << "Index out of range" << std::endl;
                    break;
                }

                ScalarType size = figures[index]->getSize();
                std::cout << "Size: " << size << std::endl;
                break;
            }
            case 'S': {
                ScalarType result = 0;
                for (const auto& figure : figures)
                    result += figure->getSize();

                std::cout << "Size: " << result << std::endl;
                break;
            }
            case 'g': {
                int index;
                std::cout << "Enter index: ";
                std::cin >> index;
                if (index >= figures.size() || index < 0) {
                    std::cout << "Index out of range" << std::endl;
                    break;
                }

                auto center = figures[index]->getCenter();
                std::cout << "Center: " << center << std::endl;
                break;
            }
            case 'e': {
                return 0;
            }
        }
    }
}

template<Scalar T>
std::shared_ptr<Figure<T>> readFigureFromConsole() {
    while (true) {
        std::cout << "Enter type of figure (t - triangle, h - hexagon, o - octagon): ";

        char type;
        std::cin >> type;
        std::cout << std::endl;

        switch (type) {
            case 't': {
                std::shared_ptr<Figure<T>> figure = std::make_shared<Triangle<T>>();
                std::cout << "Enter Triangle points' coordinates (eg. 0 0 1 0 0 1): ";
                std::cin >> *figure;
                return figure;
            }
            case 'h': {
                std::shared_ptr<Figure<T>> figure = std::make_shared<Hexagon<T>>();
                std::cout << "Enter Hexagon points' coordinates (eg. 0 0 1 -1 2 0 2 1 1 2 0 1): ";
                std::cin >> *figure;
                return figure;
            }
            case 'o': {
                std::shared_ptr<Figure<T>> figure = std::make_shared<Octagon<T>>();
                std::cout << "Enter Hexagon points' coordinates (eg. 0 0 1 -1 2 -1 3 0 3 1 2 2 1 2 0 1): ";
                std::cin >> *figure;
                return figure;
            }
            default: {
                return {nullptr};
            }
        }
    }
}
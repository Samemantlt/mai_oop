#include <valarray>
#include <gtest/gtest.h>

#include "Array.h"
#include "Hexagon.h"
#include "Octagon.h"

TEST(FiguresInArrayTests, ArrayOfHexagons) {
    Array<Hexagon<double>> array;
    array.push_back(Hexagon{
        Point<double>(0, 0),
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(2, 1),
        Point<double>(1, 1),
        Point<double>(0, 1)
    });
    array.push_back(Hexagon{
        Point<double>(0, 0),
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(2, 1),
        Point<double>(1, 2),
        Point<double>(0, 1)
    });

    double size_sum = 0;
    for (const auto& hexagon : array) {
        size_sum += hexagon.get_size();
    }

    ASSERT_EQ(size_sum, 2 + 3);
}

TEST(FiguresInArrayTests, ArrayOfFiguresPtr) {
    Array<std::shared_ptr<Figure<double>>> array;
    array.push_back(std::make_shared<Hexagon<double>>(std::initializer_list{
        Point<double>(0, 0),
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(2, 1),
        Point<double>(1, 1),
        Point<double>(0, 1)
    }));
    array.push_back(std::make_shared<Hexagon<double>>(std::initializer_list{
        Point<double>(0, 0),
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(2, 1),
        Point<double>(1, 2),
        Point<double>(0, 1)
    }));
    array.push_back(std::make_shared<Octagon<double>>(std::initializer_list{
        Point<double>(0, 0),
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(3, 0),
        Point<double>(3, 1),
        Point<double>(2, 1),
        Point<double>(1, 2),
        Point<double>(0, 1)
    }));

    double size_sum = 0;
    for (const auto& hexagon : array) {
        size_sum += hexagon->get_size();
    }

    ASSERT_EQ(size_sum, 2 + 3 + 4);
}

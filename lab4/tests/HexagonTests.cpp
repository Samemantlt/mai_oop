#include <valarray>
#include <gtest/gtest.h>

#include "Hexagon.h"

TEST(HexagonTests, GetSizeValid) {
    EXPECT_DOUBLE_EQ((Hexagon{
        Point<char>(0, 0),
        Point<char>(1, 0),
        Point<char>(2, 0),
        Point<char>(2, 1),
        Point<char>(1, 1),
        Point<char>(0, 1)
    }).get_size(), 2);
    EXPECT_DOUBLE_EQ((Hexagon{
        Point<double>(0, 0),
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(2, 1),
        Point<double>(1, 2),
        Point<double>(0, 1)
    }).get_size(), 3);
}

TEST(HexagonTests, GetCenterValid) {
    EXPECT_EQ((Hexagon{
        Point<double>(0, 0),
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(2, 1),
        Point<double>(1, 1),
        Point<double>(0, 1)
    }).get_center(), Point<double>(1, 0.5));
    EXPECT_EQ((Hexagon{
        Point<double>(0, 0),
        Point<double>(1, -1),
        Point<double>(2, 0),
        Point<double>(2, 1),
        Point<double>(1, 3),
        Point<double>(0, 1)
    }).get_center(), Point<double>(1, 2.0/3));
}

TEST(HexagonTests, PrintValid) {
    std::ostringstream output;
    const Hexagon figure{
        Point<double>(0, 0),
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(2, 1),
        Point<double>(1, 1),
        Point<double>(0, 1)
    };

    figure.print(output);

    EXPECT_EQ(output.str(), "Hexagon {A = (0; 0); B = (1; 0); C = (2; 0); D = (2; 1); E = (1; 1); F = (0; 1)}");
}

TEST(HexagonTests, ReadValid) {
    std::istringstream input("0 0  1 0  2 0  2 1  1 1  0 1");
    const Hexagon target{
        Point<double>(0, 0),
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(2, 1),
        Point<double>(1, 1),
        Point<double>(0, 1)
    };
    Hexagon<double> figure;

    figure.read(input);

    EXPECT_EQ(figure, target);
}
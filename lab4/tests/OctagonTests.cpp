#include <valarray>
#include <gtest/gtest.h>

#include "Octagon.h"

TEST(OctagonTests, GetSizeValid) {
    EXPECT_DOUBLE_EQ((Octagon{
        Point(0, 0),
        Point(1, 0),
        Point(2, 0),
        Point(3, 0),
        Point(3, 1),
        Point(2, 1),
        Point(1, 1),
        Point(0, 1)
    }).getSize(), 3);
    EXPECT_DOUBLE_EQ((Octagon{
        Point(0, 0),
        Point(1, 0),
        Point(2, 0),
        Point(3, 0),
        Point(3, 1),
        Point(2, 1),
        Point(1, 2),
        Point(0, 1)
    }).getSize(), 4);
}

TEST(OctagonTests, GetCenterValid) {
    EXPECT_EQ((Octagon{
        Point<double>(0, 0),
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(3, 0),
        Point<double>(3, 1),
        Point<double>(2, 1),
        Point<double>(1, 1),
        Point<double>(0, 1)
    }).getCenter(), Point(1.5, 0.5));
    EXPECT_EQ((Octagon{
        Point<double>(0, 0),
        Point<double>(1, -2),
        Point<double>(2, -3),
        Point<double>(3, 0),
        Point<double>(3, 1),
        Point<double>(2, 2),
        Point<double>(1, 2),
        Point<double>(0, 1)
    }).getCenter(), Point(1.5, 1.0/8));
}

TEST(OctagonTests, PrintValid) {
    std::ostringstream output;
    const Octagon figure{
        Point(0, 0),
        Point(1, 0),
        Point(2, 0),
        Point(3, 0),
        Point(3, 1),
        Point(2, 1),
        Point(1, 1),
        Point(0, 1)
    };

    figure.print(output);

    EXPECT_EQ(output.str(), "Octagon {A = (0; 0); B = (1; 0); C = (2; 0); D = (3; 0); E = (3; 1); F = (2; 1); G = (1; 1); H = (0; 1)}");
}

TEST(OctagonTests, ReadValid) {
    std::istringstream input("0 0  1 0  2 0  3 0  3 1  2 1  1 1  0 1");
    const Octagon target{
        Point<double>(0, 0),
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(3, 0),
        Point<double>(3, 1),
        Point<double>(2, 1),
        Point<double>(1, 1),
        Point<double>(0, 1)
    };
    Octagon<double> figure;

    figure.read(input);

    EXPECT_EQ(figure, target);
}
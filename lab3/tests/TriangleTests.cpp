#include <valarray>
#include <gtest/gtest.h>

#include "Triangle.h"

TEST(TriangleTests, GetSizeValid) {
    EXPECT_DOUBLE_EQ(Triangle(Point(0, 0), Point(1, 0), Point(0, 1)).get_size(), 0.5);
    EXPECT_DOUBLE_EQ(Triangle(Point(0, 0), Point(2, 0), Point(0, 2)).get_size(), 2);
}

TEST(TriangleTests, GetCenterValid) {
    EXPECT_EQ(Triangle(Point(0, 0), Point(1, 0), Point(0, 1)).get_center(), Point(1.0/3, 1.0/3));
    EXPECT_EQ(Triangle(Point(0, 0), Point(3, 0), Point(0, 3)).get_center(), Point(1, 1));
}

TEST(TriangleTests, PrintValid) {
    std::ostringstream output;
    const Triangle triangle(Point(0, 0), Point(1, 0), Point(0, 1));

    triangle.print(output);

    EXPECT_EQ(output.str(), "Triangle {A = (0; 0); B = (1; 0); C = (0; 1)}");
}

TEST(TriangleTests, ReadValid) {
    std::istringstream input("0 0  1 0  0 1");
    const Triangle target(Point(0, 0), Point(1, 0), Point(0, 1));
    Triangle triangle;

    triangle.read(input);

    EXPECT_EQ(triangle, target);
}
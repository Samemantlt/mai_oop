#include <gtest/gtest.h>

#include "../src/four.h"


TEST(FourTests, ConstructorTests) {
    EXPECT_EQ(Four("123").toString(), "123");
    EXPECT_EQ(Four("1").toString(), "1");
    EXPECT_EQ(Four("0").toString(), "0");
}

TEST(FourTests, SumTests) {
    EXPECT_EQ(Four("1") + Four("2"), Four("3"));
    EXPECT_EQ(Four("1") + Four("13"), Four("20"));
}

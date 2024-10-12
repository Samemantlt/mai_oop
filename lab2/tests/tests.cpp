#include <gtest/gtest.h>

#include "four.h"

TEST(FourTests, ConstructorsValid) {
    EXPECT_EQ((Four{'1', '2'}).toString(), "12");
    EXPECT_EQ((Four{'3', '2'}).toString(), "32");

    EXPECT_EQ((Four(3, '1')).toString(), "111");
    EXPECT_EQ((Four(5, '2')).toString(), "22222");
    EXPECT_EQ((Four(0, '3')).toString(), "");

    EXPECT_EQ(Four("1").toString(), "1");
    EXPECT_EQ(Four("0").toString(), "0");
}

TEST(FourTests, ToStringValid) {
    EXPECT_EQ(Four("123").toString(), "123");
    EXPECT_EQ(Four("1").toString(), "1");
    EXPECT_EQ(Four("0").toString(), "0");
}

TEST(FourTests, ConstructorThrowsNonFourStringPassed) {
    EXPECT_THROW(Four(""), std::runtime_error);
    EXPECT_THROW(Four("5"), std::runtime_error);
    EXPECT_THROW(Four("01"), std::runtime_error);
}

class FourSumTestsFixture :
        public ::testing::Test,
        public ::testing::WithParamInterface<std::tuple<std::string, std::string, std::string>> {
};

TEST_P(FourSumTestsFixture, CommutativeAndValid) {
    auto args = GetParam();

    auto a = std::get<0>(args);
    auto b = std::get<1>(args);
    auto c = std::get<2>(args);

    EXPECT_EQ(Four(a) + Four(b), Four(c));
    EXPECT_EQ(Four(b) + Four(a), Four(c));
}

INSTANTIATE_TEST_CASE_P(
        FourSumTests,
        FourSumTestsFixture,
        ::testing::Values(
            std::make_tuple("1", "2", "3"),
            std::make_tuple("1", "13", "20"),
            std::make_tuple("1", "23", "30"),
            std::make_tuple("1", "33", "100"),

            std::make_tuple("3", "3", "12"),
            std::make_tuple("3", "13", "22")
        ));

TEST(FourTests, SubtractValid) {
    EXPECT_EQ(Four("0") - Four("0"), Four("0"));
    EXPECT_EQ(Four("1") - Four("0"), Four("1"));
    EXPECT_EQ(Four("22") - Four("0"), Four("22"));

    EXPECT_EQ(Four("2") - Four("1"), Four("1"));
    EXPECT_EQ(Four("3") - Four("1"), Four("2"));
    EXPECT_EQ(Four("11") - Four("3"), Four("2"));
    EXPECT_EQ(Four("11") - Four("10"), Four("1"));
    EXPECT_EQ(Four("123") - Four("22"), Four("101"));
}

TEST(FourTests, ComparisonValid) {
    EXPECT_EQ(Four("0") <=> Four("0"), std::strong_ordering::equal);
    EXPECT_EQ(Four("1") <=> Four("1"), std::strong_ordering::equal);
    EXPECT_EQ(Four("22") <=> Four("22"), std::strong_ordering::equal);
    EXPECT_EQ(Four("3123") <=> Four("3123"), std::strong_ordering::equal);

    EXPECT_EQ(Four("0") <=> Four("1"), std::strong_ordering::less);
    EXPECT_EQ(Four("0") <=> Four("11"), std::strong_ordering::less);
    EXPECT_EQ(Four("0") <=> Four("111"), std::strong_ordering::less);
    EXPECT_EQ(Four("2") <=> Four("3"), std::strong_ordering::less);
    EXPECT_EQ(Four("2") <=> Four("11"), std::strong_ordering::less);

    EXPECT_EQ(Four("1") <=> Four("0"), std::strong_ordering::greater);
    EXPECT_EQ(Four("11") <=> Four("0"), std::strong_ordering::greater);
    EXPECT_EQ(Four("111") <=> Four("0"), std::strong_ordering::greater);
    EXPECT_EQ(Four("3") <=> Four("2"), std::strong_ordering::greater);
    EXPECT_EQ(Four("11") <=> Four("3"), std::strong_ordering::greater);
}

TEST(FourTests, SubtractThrowRightValueGreaterThanLeftValue) {
    EXPECT_THROW(Four("0") - Four("1"), std::runtime_error);
    EXPECT_THROW(Four("2") - Four("3"), std::runtime_error);
    EXPECT_THROW(Four("2") - Four("11"), std::runtime_error);
    EXPECT_THROW(Four("12") - Four("21"), std::runtime_error);
    EXPECT_THROW(Four("2") - Four("333"), std::runtime_error);
    EXPECT_THROW(Four("21") - Four("22"), std::runtime_error);
}
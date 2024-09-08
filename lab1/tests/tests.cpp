#include <gtest/gtest.h>

#include "../src/polindrom.h"


TEST(PolyndromTests, TrueCases) {
    EXPECT_TRUE(is_polyndrom(""));
    EXPECT_TRUE(is_polyndrom("a"));
    EXPECT_TRUE(is_polyndrom("aa"));
    EXPECT_TRUE(is_polyndrom("bb"));
    EXPECT_TRUE(is_polyndrom("bbb"));
    EXPECT_TRUE(is_polyndrom("abba"));
    EXPECT_TRUE(is_polyndrom("abbba"));
    EXPECT_TRUE(is_polyndrom("abcba"));
    EXPECT_TRUE(is_polyndrom("abccba"));
}

TEST(PolyndromTests, FalseCases) {
    EXPECT_FALSE(is_polyndrom("ab"));
    EXPECT_FALSE(is_polyndrom("ba"));

    EXPECT_FALSE(is_polyndrom("bba"));
    EXPECT_FALSE(is_polyndrom("abb"));
    EXPECT_FALSE(is_polyndrom("aab"));
    EXPECT_FALSE(is_polyndrom("abc"));

    EXPECT_FALSE(is_polyndrom("abca"));

    EXPECT_FALSE(is_polyndrom("acbba"));
    EXPECT_FALSE(is_polyndrom("abbbc"));

    EXPECT_FALSE(is_polyndrom("bbccba"));
}

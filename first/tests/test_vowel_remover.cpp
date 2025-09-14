#include "gtest/gtest.h"
#include "vowel_utils.h"

TEST(VowelRemoverTest, EmptyString) {
    EXPECT_EQ(remove_vowels(""), "");
}

TEST(VowelRemoverTest, OnlyVowelsEnglish) {
    EXPECT_EQ(remove_vowels("aeiouy"), "");
}

TEST(VowelRemoverTest, OnlyConsonants) {
    EXPECT_EQ(remove_vowels("bcdfghjklmnpqrstvwxz"), "bcdfghjklmnpqrstvwxz");
}

TEST(VowelRemoverTest, MixedTextEnglish) {
    EXPECT_EQ(remove_vowels("Hello World!"), "Hll Wrld!");
}


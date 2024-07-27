#include <gtest/gtest.h>
#include "make_string.hpp"


TEST(MakeString, Return) {
    std::string output;
    output = make_string_return(3);
    EXPECT_EQ(output, "aaa");
}


TEST(MakeString, Arg) {
    std::string output;
    make_string_arg(output, 3);
    EXPECT_EQ(output, "aaa");
}


TEST(MakeChars, Test) {
    const int stringSize = 3;
    char output[stringSize + 1];

    make_chars(output, stringSize);
    EXPECT_EQ(std::string(output), "aaa");
}

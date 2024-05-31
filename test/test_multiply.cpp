#include <gtest/gtest.h>
#include "multiply.hpp"


void print_int(const int val) {
    EXPECT_EQ(6, val);
    std::cout << "stub function: " << val << std::endl;
}

TEST(Mock, Multiply) {
    print_multiply(2, 3);
}

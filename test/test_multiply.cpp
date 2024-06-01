#include <stdio.h>
#include <gtest/gtest.h>
#include "multiply.hpp"
#include "print_int.hpp"


// TODO: 非同期で動くときなどの排他制御の実装
static int expected_input = 0;

void print_int(const int actual_input) {
    EXPECT_EQ(actual_input, expected_input);
    printf("stub of print_int: (actual arg, expected arg) = (%d, %d)\n", actual_input, expected_input);
}

TEST(Mock, Multiply1) {
    expected_input = 6;
    print_multiply(2, 3);
}

TEST(Mock, Multiply2) {
    expected_input = 12;
    print_multiply(4, 3);
}

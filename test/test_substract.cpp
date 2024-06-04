#include <stdio.h>
#include <gtest/gtest.h>
#include "substract.hpp"


class FakeSubstract: public Substract {
public:
    FakeSubstract(const int expected_input): expected_input(expected_input) {}

private:
    void print_int(const int actual_input) const {
        EXPECT_EQ(actual_input, expected_input);
        printf("fake method of print_int: (actual arg, expected arg) = (%d, %d)\n", actual_input, expected_input);
    }

    const int expected_input;
};


TEST(FakeClass, Substract) {
    FakeSubstract fake = FakeSubstract(3);
    fake.print_substract(5, 2);

    FakeSubstract(-1).print_substract(1, 2);
}

#include <gtest/gtest.h>
#include "add.hpp"


TEST(Expect, Add) {
    EXPECT_EQ(3, add(1, 2));
}

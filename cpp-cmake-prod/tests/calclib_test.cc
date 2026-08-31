#include "calclib/calclib.h"

#include <gtest/gtest.h>

#include <array>

TEST(Calclib, SumsPositiveAndNegativeValues) {
  constexpr std::array values{1, -2, 4};

  EXPECT_EQ(calclib::sum(values), 3);
}
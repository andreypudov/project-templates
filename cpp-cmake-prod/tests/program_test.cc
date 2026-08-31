#include "program/command.h"

#include <gtest/gtest.h>

#include <array>
#include <sstream>
#include <string_view>

TEST(Program, WritesSumForValidArguments) {
  constexpr std::array<std::string_view, 3> arguments{"1", "2", "3"};
  std::ostringstream output;
  std::ostringstream error;

  const int exit_code = program::run(arguments, output, error);

  EXPECT_EQ(exit_code, 0);
  EXPECT_EQ(output.str(), "Sum: 6\n");
  EXPECT_TRUE(error.str().empty());
}

TEST(Program, ReportsInvalidArguments) {
  constexpr std::array<std::string_view, 1> arguments{"invalid"};
  std::ostringstream output;
  std::ostringstream error;

  const int exit_code = program::run(arguments, output, error);

  EXPECT_EQ(exit_code, 1);
  EXPECT_TRUE(output.str().empty());
  EXPECT_EQ(error.str(), "Invalid integer: invalid\n");
}
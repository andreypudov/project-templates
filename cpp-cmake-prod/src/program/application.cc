#include "program/application.h"
#include "program/internal/application.h"

#include "calclib/calclib.h"

#include <charconv>
#include <ostream>
#include <vector>

namespace program {

int run(
    std::span<const std::string_view> arguments,
    std::ostream& output,
    std::ostream& error) {
  std::vector<int> values;
  values.reserve(arguments.size());

  for (const std::string_view argument : arguments) {
    const std::optional<int> value = detail::parse_integer(argument);

    if (!value.has_value()) {
      error << "Invalid integer: " << argument << '\n';
      return 1;
    }

    values.push_back(*value);
  }

  output << "Sum: " << calclib::sum(values) << '\n';
  return 0;
}

}  // namespace program

namespace program::detail {

std::optional<int> parse_integer(std::string_view text) {
  int value{};
  const auto result = std::from_chars(text.data(), text.data() + text.size(), value);

  if (result.ec != std::errc{} || result.ptr != text.data() + text.size()) {
    return std::nullopt;
  }

  return value;
}

}  // namespace program::detail
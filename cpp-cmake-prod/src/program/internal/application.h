#pragma once

#include <optional>
#include <string_view>

namespace program::detail {

[[nodiscard]] std::optional<int> parse_integer(std::string_view text);

}  // namespace program::detail
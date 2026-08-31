#pragma once

#include <iosfwd>
#include <span>
#include <string_view>

namespace program {

[[nodiscard]] int run(std::span<const std::string_view> arguments,
                      std::ostream &output, std::ostream &error);

} // namespace program
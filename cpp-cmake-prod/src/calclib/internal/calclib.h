#pragma once

#include <span>

namespace calclib::detail {

[[nodiscard]] int sum_values(std::span<const int> values);

}
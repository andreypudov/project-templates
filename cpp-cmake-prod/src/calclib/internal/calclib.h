#pragma once

#include <span>

namespace calclib {
namespace detail {

[[nodiscard]] int sum_values(std::span<const int> values);

}
} // namespace calclib
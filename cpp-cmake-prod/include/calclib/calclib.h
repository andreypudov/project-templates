#pragma once

#include <span>

namespace calclib {

[[nodiscard]] int sum(std::span<const int> values);

}
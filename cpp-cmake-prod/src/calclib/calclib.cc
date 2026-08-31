#include "calclib/calclib.h"
#include "calclib/internal/calclib.h"

namespace calclib {

int sum(std::span<const int> values) { return detail::sum_values(values); }

namespace detail {

int sum_values(std::span<const int> values) {
  int result = 0;

  for (const int value : values) {
    result += value;
  }

  return result;
}

} // namespace detail

} // namespace calclib
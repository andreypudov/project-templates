#include <charconv>
#include <iostream>
#include <string_view>

int main(int argc, char *argv[]) {
  int sum = 0;

  for (int index = 1; index < argc; ++index) {
    std::string_view sv{argv[index]};
    int value{};
    auto result = std::from_chars(sv.data(), sv.data() + sv.size(), value);

    if (result.ec != std::errc{} || result.ptr != sv.data() + sv.size()) {
      std::cerr << "Invalid integer: " << sv << '\n';

      return 1;
    }

    sum += value;
  }

  std::cout << "Sum: " << sum << '\n';
}

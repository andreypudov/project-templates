#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  int sum = 0;

  for (int index = 1; index < argc; ++index) {
    sum += std::stoi(argv[index]);
  }

  std::cout << "Sum: " << sum << '\n';

  return 0;
}

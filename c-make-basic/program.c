#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int sum = 0;

  for (int index = 1; index < argc; ++index) {
    char *end = nullptr;
    long value = strtol(argv[index], &end, 10);

    if (end == argv[index] || *end != '\0') {
      fprintf(stderr, "Invalid integer: %s\n", argv[index]);

      return 1;
    }

    sum += (int)value;
  }

  printf("Sum: %d\n", sum);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
  int sum = 0;

  for (int index = 1; index < argc; ++index) {
    sum += atoi(argv[index]);
  }

  printf("Sum: %d\n", sum);

  return (EXIT_SUCCESS);
}

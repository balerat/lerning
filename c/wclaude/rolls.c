#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT_H 1000000
#define LIMIT_L 1


int main(void) {
  int nRoll;
  srand(time(NULL));

  printf("How many rolls?\n");
  int out = scanf("%d", &nRoll);
  if (out != 1 || nRoll < LIMIT_L || nRoll > LIMIT_H) {
    printf("Invalid.\n");
    return 1;
  }

  // Simulate the number of throw
  int sums[11] = {0};
  int throw1, throw2;
  for (int i = 0; i < nRoll; i++) {
    throw1 = rand() % 6 + 1;
    throw2 = rand() % 6 + 1;
    sums[throw1 + throw2 - 2] += 1;
  }

  // Print the histogram:
  for (int i = 0; i < 11; i++) {
    printf("%d:, %8d (%2.2f%%)\n", i+2, sums[i], sums[i] * 100.0 / nRoll);
    int count = (int)(sums[i] * 1.0 / nRoll * 50.0);
    for (int i = 0; i < count; i++) {
      printf("#");
    }
    printf("\n");

  }
}

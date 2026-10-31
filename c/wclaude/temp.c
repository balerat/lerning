#include <stdio.h>
#define STEP 20

const int start = 100;
const int end = -40;

double toF(int c) { return c * 9.0 / 5.0 + 32; }

double toK(int c) { return c + 273.15; }

int main(void) {
  printf("%4s %7s %8s\n", "C", "F", "K");
  for (int i = start; i >= end; i = i - STEP) {
    printf("%4d %7.1f %8.2f\n", i, toF(i), toK(i));
  }
  return 0;
}

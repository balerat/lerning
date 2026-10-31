#include <stdio.h>

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void reverse(int a[], size_t n) {
  for (int i = 0; i < n / 2 + 1; i++) {
    swap(&a[i], &a[n - i - 1]);
  }
}

int stats(const int a[], size_t n, int *min, int *max) {}

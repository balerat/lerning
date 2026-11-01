#include <limits.h>
#include <stdio.h>

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void reverse(int a[], size_t n) {
  for (int i = 0; i < (int)n / 2; i++) {
    swap(&a[i], &a[n - i - 1]);
  }
}

int stats(int a[], size_t n, int *min, int *max, double *mean) {
  if (n == 0) {
    return -1;
  }
  *max = a[0];
  *min = a[0];
  *mean = (double)a[0];
  int c;
  for (int i = 1; i < (int)n; i++) {
    c = a[i];
    if (c > *max) {
      *max = c;
    }
    if (c < *min) {
      *min = c;
    }
    *mean += (double)a[i];
  }
  *mean /= n;
  return 0;
}

void helperPrint(double *mean, int *max, int *min, int r[], int n) {
  printf("%d", n);
  printf("min %d, max %d, mean %f; reversed: ", *min, *max, *mean);
  for (int i = 0; i < (int)n; i++) {
    printf("%d ", r[i]);
  }
  printf("\n");
}


int main() {
  int a1[5] = {3, -1, 7, 0, 5};
  int a2[1] = {42};
  int a3[4] = {1, 2, 3, 4};
  int a4[2] = {INT_MAX, INT_MAX};

  int a1Size = sizeof(a1) / sizeof(a1[0]);
  int a2Size = sizeof(a2) / sizeof(a2[0]);
  int a3Size = sizeof(a3) / sizeof(a3[0]);
  int a4Size = sizeof(a4) / sizeof(a4[0]);

  int min1;
  int max1;
  double mean1;
  stats(a1, a1Size, &min1, &max1, &mean1);
  reverse(a1, a1Size);
  helperPrint(&mean1, &max1, &min1, a1, a1Size);

  int min2;
  int max2;
  double mean2;
  stats(a2, a2Size, &min2, &max2, &mean2);
  reverse(a2, a2Size);
  helperPrint(&mean2, &max2, &min2, a2, a2Size);

  int min3;
  int max3;
  double mean3;
  stats(a3, a3Size, &min3, &max3, &mean3);
  reverse(a3, a3Size);
  helperPrint(&mean3, &max3, &min3, a3, a3Size);

  int min4;
  int max4;
  double mean4;
  stats(a4, a4Size, &min4, &max4, &mean4);
  reverse(a4, a4Size);
  helperPrint(&mean4, &max4, &min4, a4, a4Size);

  int err = stats(a1, 0, &min1, &max1, &mean1);
  if (err ==-1) {return -1;}

  return 0;
}

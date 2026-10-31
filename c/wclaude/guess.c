#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOW 1
#define HIGH 100

int main(void) {
  int secret;
  int guess;
  int c;
  int x;
  int tries = 0;
  srand(time(NULL));
  secret = rand() % HIGH + 1;
  printf("Enter your guess:\n");
  for (;;) {

    if ((x = scanf("%d", &guess)) == 0) {
      printf("Not a number.\n");
      while ((c = getchar()) != EOF && c != '\n')
        ;
      continue;
    } else if (x == EOF) {
      printf("Bye.\n");
      return 1;
    } else if (guess < LOW || guess > HIGH) {
      printf("Out of range.\n");
      continue;
    }

    tries += 1;
    if (guess == secret) {
      printf("Correct! Found in %d.\n", tries);
      return 0;
    } else if (guess > secret) {
      printf("Too high.\n");
    } else {
      printf("Too low.\n");
    }
  }
}
// %%

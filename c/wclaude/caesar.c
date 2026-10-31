#include <stdio.h>
#include <string.h>

#define WINDOW 257

void caesar(char s[], int k) {
  int len;
  len = strlen(s);
  for (int i = 0; i < len; i++) {
    if ((int)s[i] < 91 && (int)s[i] > 64) {
      s[i] = ((s[i] - 'A' + k % 26) + 26) % 26 + 'A';
    } else if (s[i] < 123 && (int)s[i] > 96) {
      s[i] = ((s[i] - 'a' + k % 26) + 26) % 26 + 'a';
    }
  }
}

int main(void) {
  int k;
  int c; // Always to prevent bug with missing EOF
  char s[WINDOW];
  int x;
  printf("Enter a number:\n");
  if ((x = scanf("%d", &k)) > 0) {
  } else {
    printf("Invalid number.\n");
    return 1;
  }
  while ((c = getchar()) != EOF && c != '\n') {
  }
  printf("Enter a phrase to encrypt:\n");
  if (fgets(s, WINDOW, stdin) == NULL) {
    return 1;
  } // Uses WINDOW -1 character

  caesar(s, k);
  printf("%s", s);
  return 0;
}

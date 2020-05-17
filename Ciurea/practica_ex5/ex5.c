#include <stdio.h>

int customStrLen(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

void citeste(int n) {
  int i, j;
  char word[50];

  for (i = 0; i < n; i++) {
      scanf("%s", word);
      if (customStrLen(word) % 2 == 0) {
        printf("%s ", word);
      }
    }
}

int main () {
  int n;

  printf("Numarul de cuvinte ce vor fi introduse: ");
  scanf("%i", &n);

  citeste(n);
  printf("\n");

  return 0;
}
#include <ctype.h>
#include <stdio.h>

int main() {
  int c, word_count = 0, in_word = 0;

  while ((c = getchar()) != EOF) {
    if (isspace(c)) {
      in_word = 0;
    } else if (!in_word) {
      in_word = 1;
      word_count++;
    }
  }
  printf("Word count: %d\n", word_count);
  return 0;
}

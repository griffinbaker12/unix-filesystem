#include <ctype.h>
#include <stdio.h>

int main() {
  int c;
  // gets single input character from stdin
  while ((c = getchar()) != EOF) {
    putchar(toupper(c));
  }
  return 0;
}

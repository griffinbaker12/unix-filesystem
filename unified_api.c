#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

int count_words(FILE *input) {
  char buffer[BUFFER_SIZE];
  int word_count = 0;
  int in_word = 0;

  // while there are chars to get, get the next character
  while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
    for (int i = 0; buffer[i] != '\0'; i++) {
      if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t') {
        in_word = 0;
      } else if (!in_word) {
        in_word = 1;
        word_count++;
      }
    }
  }

  return word_count;
}

int main(int argc, char *argv[]) {
  FILE *input;
  int word_count;

  if (argc > 1) {
    input = fopen(argv[1], "r");
    if (input == NULL) {
      perror("Error opening file");
      return 1;
    }
  } else {
    input = stdin;
  }

  word_count = count_words(input);

  printf("Word count %d\n", word_count);

  if (input != stdin) {
    fclose(input);
  }

  return 1;
}

#include <fcntl.h>
#include <stdio.h>

void print_buffer(char *b, int len) {
  for (int i = 0; i < len; i++) {
    fprintf(stdout, "%c", b[i]);
  }
  printf("\n");
}

void fill_buffer(FILE *f) {
  char c;
  int flag = fscanf(f, "%c", &c);
  printf("The flag is: %u\n", flag);
}

int main() {
  // have kernel open connection to file alphabet.txt
  int fd = open("alphabet.txt", O_RDONLY);

  // share the same fd, so share the same file offset

  // create two a C I/O buffered streams using the above connection
  FILE *fs1 = fdopen(fd, "r");
  char buff1[20];
  setvbuf(fs1, buff1, _IOFBF, 20);

  FILE *fs2 = fdopen(fd, "r");
  char buff2[20];
  setvbuf(fs2, buff2, _IOFBF, 20);

  // when fscanf is called, it triggers a buffer fill if the buffer is empty
  fill_buffer(fs1);
  print_buffer(buff1, 20);

  // this resets the offset
  // if reset, buff2 will be full [a,t]
  // else, will have [u,z]
  fseek(fs1, 0, SEEK_SET);

  printf("\n");

  fill_buffer(fs2);
  print_buffer(buff2, 20);
  fseek(fs2, 0, SEEK_SET);

  printf("\n");

  // read a char & write it alternatingly from fs1 and fs2
  int flag1 = 1, flag2 = 2;
  while (flag1 == 1 || flag2 == 1) {
    char c;
    flag1 = fscanf(fs1, "%c", &c);
    if (flag1 == 1) {
      fprintf(stdout, "%c", c);
    }
    flag2 = fscanf(fs2, "%c", &c);
    if (flag2 == 1) {
      fprintf(stdout, "%c", c);
    }
  }

  printf("\n");

  return 0;
}

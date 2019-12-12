#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *stream;

  stream = fopen("test.txt", "r+");
  if (!stream) {
    perror("fopen");
    exit(1);
  }

  printf("file opened\n");

  if (fclose(stream) != 0) {
    perror("fclose");
  }

  printf("file closed\n");
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: ./MergeFiles file1 file2");
    return 1;
  }

  // Reads all the lines from file1 then file2 to stdout
  char line[MAX_LINE];

  FILE *file1 = fopen(argv[1], "r");

  while (fgets(line, MAX_LINE, file1) != NULL) {
    printf("%s", line);
  }

  putchar('\n');
  fclose(file1);

  FILE *file2 = fopen(argv[2], "r");

  while (fgets(line, MAX_LINE, file2) != NULL) {
    printf("%s", line);
  }

  fclose(file2);
  putchar('\n');
}
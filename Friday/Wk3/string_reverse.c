#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void string_print_reverse(char *s) {
  if (s[0] == '\0') return;
  string_print_reverse(&s[1]);
  putchar(s[0]);
}

int main(int argc, char *argv[]) {
  printf("%s\n", argv[1]);
  string_print_reverse(argv[1]);
  putchar('\n');
}
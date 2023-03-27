#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void string_print_reverse(char *s) {
  // First char: *s or s[0]
  if (s[0] == '\0') return;
  string_print_reverse(&s[1]);
  putchar(s[0]);
}

int main(int argc, char *argv[]) {
  string_print_reverse(argv[1]);
  putchar('\n');
}
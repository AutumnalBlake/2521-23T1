#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool is_palindrome(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n/2; i++) {
        if (s[n - i - 1] != s[i]) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    printf("%d\n", is_palindrome(argv[1]));
}
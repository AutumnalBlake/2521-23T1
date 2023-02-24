#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n == 0) return 1;
    return factorial(n - 1) * n;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    printf("%d\n", factorial(n));
}
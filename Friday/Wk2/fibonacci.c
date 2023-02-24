#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    int *dp = malloc((n + 1) * sizeof (int));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    printf("%d\n", fib(n));
}
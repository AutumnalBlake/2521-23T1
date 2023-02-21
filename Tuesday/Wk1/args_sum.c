#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sum = 0;
    
    // int i = 1; // Setup
    // while (i < argc) { // Condition
    //     // printf("%s\n", argv[i]);

    //     int int_arg = atoi(argv[i]);
    //     sum += int_arg;

    //     i++; // Step
    // }

    // for (setup; condition; step) {}

    for (int i = 1; i < argc; i++) {
        int int_arg = atoi(argv[i]);
        sum += int_arg;
    }

    // Conditional expression
    // Condition ? Value if even : value if odd
    char *even_or_odd = sum % 2 == 0 ? "even" : "odd";

    printf("The sum is %s\n", even_or_odd);
    printf("%d\n", sum);

}
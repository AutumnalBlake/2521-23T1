#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sum = 0;

    for (int i = 1; i < argc; i++) {
        int arg_to_int = atoi(argv[i]);
        sum += arg_to_int;
    }

    printf("%d\n", sum);

    char * even_odd = sum % 2 == 0 ? "even" : "odd";
    printf("The sum is %s\n", even_odd);

}
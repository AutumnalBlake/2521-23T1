#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool is_ascending(int *arr, int n);

int main(int argc, char *argv[]) {
    int arr1[] = {};
    int arr2[] = {1, 2, 3, 4};
    int arr3[] = {1, 1, 2, 2};
    int arr4[] = {4, 3, 2, 1};
    int arr5[] = {1, 2, 3, 2, 1};

    assert(is_ascending(arr1, 0));
    assert(is_ascending(arr2, 4));
    assert(is_ascending(arr3, 4));
    assert(!is_ascending(arr4, 4));
    assert(!is_ascending(arr5, 5));

    printf("Tests passed\n");
}

bool is_ascending(int *arr, int n) {
    // TODO
}
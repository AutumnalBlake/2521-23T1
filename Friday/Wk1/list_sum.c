#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

int list_sum(ListNode l);

int main(int argc, char *argv[]) {
    int arr1[] = {};
    int arr2[] = {5};
    int arr3[] = {1, 2, 3, 4, 5};
    int arr4[] = {-5};
    int arr5[] = {1, -2, 3, -4, 5, -6, 7};

    assert(list_sum(list_from_array(arr1, 0)) == 0);
    assert(list_sum(list_from_array(arr2, 1)) == 5);
    assert(list_sum(list_from_array(arr3, 5)) == 15);
    assert(list_sum(list_from_array(arr4, 1)) == -5);
    assert(list_sum(list_from_array(arr5, 7)) == 4);
        
    printf("Tests passed\n");
}

int list_sum(ListNode l) {
    // TODO
}
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

ListNode list_delete(ListNode l, int val);

int main(int argc, char *argv[]) {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr1_del1[] = {2, 3, 4, 5};
    int arr1_del3[] = {1, 2, 4, 5};
    int arr1_del5[] = {1, 2, 3, 4};

    assert(list_eq(
        list_delete(list_from_array(arr1, 5), -1),
        list_from_array(arr1, 5)
    ));

    assert(list_eq(
        list_delete(list_from_array(arr1, 5), 1),
        list_from_array(arr1_del1, 4)
    ));
  
    assert(list_eq(
        list_delete(list_from_array(arr1, 5), 3),
        list_from_array(arr1_del3, 4)
    ));  

    assert(list_eq(
        list_delete(list_from_array(arr1, 5), 5),
        list_from_array(arr1_del5, 4)
    ));
  

    printf("Tests passed\n");
}

ListNode list_delete(ListNode l, int val) {
    if (l == NULL) return l;
    if (l->val == val) {
        ListNode new_head = l->next;
        free(l);
        return new_head;
    }

    ListNode curr = l->next;
    ListNode prev = l;
    while (curr != NULL) {
        printf("%d %d\n", curr->val, prev->val);
        if (curr->val == val) {
            prev->next = curr->next;
            free(curr);
            return l;
        }

        prev = curr;
        curr = curr->next;
    }

    return l;
}

#include <stdlib.h>
#include "list.h"

ListNode list_from_array(int *arr, int n) {
    ListNode head = NULL;
    for (int i = n - 1; i >= 0; i--) {
        ListNode new_head = malloc(sizeof (struct node));
        new_head->val = arr[i];
        new_head->next = head;
        head = new_head;
    }
    return head;
}

bool list_eq(ListNode a, ListNode b) {
    if (a == NULL && b == NULL) return true;
    if ((a == NULL) != (b == NULL)) return false;
    return a->val == b->val && list_eq(a->next, b->next);
}
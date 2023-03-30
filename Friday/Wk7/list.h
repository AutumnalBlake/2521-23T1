#include <stdbool.h>

struct node {
    int val;
    struct node *next;
};

typedef struct node *ListNode;

ListNode list_from_array(int *arr, int n);
bool list_eq(ListNode a, ListNode b);
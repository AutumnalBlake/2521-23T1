#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef Node *List;

List list_from_args(int argc, char *argv[]);
void list_print(List l);
List selection_sort(List l);
List list_min(List l);
List list_unlink(List l, List to_remove);

int main(int argc, char *argv[])
{
  List l = list_from_args(argc, argv);
  list_print(l);
  list_print(selection_sort(l));
}

// Sorts a linked list in-place using selection sort.
List selection_sort(List l) {
  List unsorted = l;
  List sorted_head = NULL;
  List sorted_tail = NULL;

  while (unsorted != NULL) {
    List min = list_min(unsorted);
    unsorted = list_unlink(unsorted, min);

    if (sorted_head == NULL) {
      sorted_head = min;
      sorted_tail = min;
    } else {
      sorted_tail->next = min;
      sorted_tail = min;
    }
  }

  assert(unsorted == NULL);
  return sorted_head;
}

List list_min(List l) {
  if (l->next == NULL) return l;
  List tail_min = list_min(l->next);
  return tail_min->data < l->data ? tail_min : l;
}

// Unlinks to_remove from l
// Returns the new head
List list_unlink(List l, List to_remove) {
  if (l == to_remove) {
    List return_val = l->next;
    l->next = NULL;
    return return_val;
  }

  l->next = list_unlink(l->next, to_remove);
  return l;
}

// Create linked list from args
List list_from_args(int argc, char *argv[])
{
  if (argc == 1)
    return NULL;

  List l = malloc(sizeof(struct node));
  l->data = atoi(argv[1]);
  List curr = l;
  for (int i = 2; i < argc; i++, curr = curr->next)
  {
    curr->next = malloc(sizeof(struct node));
    curr->next->data = atoi(argv[i]);
    curr->next->next = NULL;
  }
  return l;
}

// Print a linked list
void list_print(List l)
{
  for (List curr = l; curr != NULL; curr = curr->next)
  {
    printf("[%d] -> ", curr->data);
  }
  printf("X\n");
}
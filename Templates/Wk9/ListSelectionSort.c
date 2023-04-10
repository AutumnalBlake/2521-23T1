#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef Node *List;

List list_from_args(int argc, char *argv[]);
void list_print(List l);
List selection_sort(List l);

int main(int argc, char *argv[])
{
  List l = list_from_args(argc, argv);
  list_print(l);
  list_print(selection_sort(l));
}

// Sorts a linked list in-place using selection sort.
List selection_sort(List l) {
  return NULL;
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
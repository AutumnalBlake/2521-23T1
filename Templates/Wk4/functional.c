#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef Node *List;

// Helpers
List list_from_args(int argc, char *argv[]);
void list_print(List l);
List new_node(int data, List next);

// Functions
List list_filter(List l, bool (*pred)(int));
int list_reduce(List l, int (*reducer)(int, int), int initial);

// Predicates
bool even(int x) {  return x % 2 == 0; }
bool gt_5(int x) {  return x > 5; }
bool negative(int x) {  return x < 0; }

// Reducers
int sum(int acc, int x) { return acc + x; }
int prod(int acc, int x) { return acc * x; }
int max(int acc, int x) { return acc > x ? acc : x; }
int count_even(int acc, int x) {
    if (x % 2 == 0)
        return acc + 1;
    return acc;
}

int main(int argc, char *argv[]) {
    List l = list_from_args(argc, argv);
    printf("List: ");
    list_print(l);    
    printf("Filter by even: ");
    list_print(list_filter(l, even));    
    printf("Filter by > 5: ");
    list_print(list_filter(l, gt_5));    
    printf("Filter by negative: ");
    list_print(list_filter(l, negative));    
    printf("Reduce by sum: %d\n", list_reduce(l, sum, 0));
    printf("Reduce by prod: %d\n", list_reduce(l, prod, 1));
    printf("Reduce by max: %d\n", list_reduce(l, max, l->data));
    printf("Reduce by count even: %d\n", list_reduce(l, count_even, 0));
}

List list_filter(List l, bool (*pred)(int)) {
    // TODO
    return NULL;
}

int list_reduce(List l, int (*reducer)(int, int), int initial) {
    // TODO
    return initial;
}

// HELPERS
List new_node(int data, List next) {
    List l = malloc(sizeof(struct node));
    l->data = data;
    l->next = next;
    return l;
}

// Create linked list from args
List list_from_args(int argc, char *argv[]) {
	if (argc == 1) return NULL;
	
	
	List l = new_node(atoi(argv[1]), NULL);
	List curr = l;
	for (int i = 2; i < argc; i++, curr = curr->next) {
		curr->next = new_node(atoi(argv[i]), NULL);
	}
	return l;
}

// Print a linked list
void list_print(List l) {
    printf("[");
	for (List curr = l; curr != NULL; curr = curr->next) {
        printf("%d", curr->data);
        if (curr->next) printf(", ");
	}
	printf("]\n");
}



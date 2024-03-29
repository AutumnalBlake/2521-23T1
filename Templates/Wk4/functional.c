#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef Node *List;

// Predicates
bool is_even(int x) { return x % 2 == 0; }
bool gt_5(int x) { return x > 5; }

// Reducers
int sum(int acc, int x) { return acc + x; }
int max(int acc, int x) { return acc > x ? acc : x; }
int count_even(int acc, int x) { return is_even(x) ? acc + 1 : acc; }

List list_from_args(int argc, char *argv[]);
void list_print(List l);

int main(int argc, char *argv[]) {
	List l = list_from_args(argc, argv);
	list_print(l);
}

// HELPERS
// Create linked list from args
List list_from_args(int argc, char *argv[]) {
	if (argc == 1) return NULL;
	
	List l = malloc(sizeof (struct node));
	l->data = atoi(argv[1]);
	List curr = l;
	for (int i = 2; i < argc; i++, curr = curr->next) {
		curr->next = malloc(sizeof (struct node));
		curr->next->data = atoi(argv[i]);
		curr->next->next = NULL;
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



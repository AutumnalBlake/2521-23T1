#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef Node *List;

List list_from_args(int argc, char *argv[]);
void list_print(List l);

int list_length(List l) {
	if (l == NULL) return 0;
	return 1 + list_length(l->next);
}

int list_sum(List l) {
	if (l == NULL) {
		return 0;
	}
	return l->data + list_sum(l->next);
}

int list_count_odds(List l) {
	if (l == NULL) {
		return 0;
	}
	if (l->data % 2 == 1) {
		return 1 + list_count_odds(l->next);
	}
	return list_count_odds(l->next);
}

bool list_is_sorted(List l) {
	if (l == NULL || l->next == NULL) {
		return true;
	}
	if (!list_is_sorted(l->next)) {
		return false;
	}
	return l->data < l->next->data;
}

List list_delete(List l, int val) {
	if (l == NULL) {
		return l;
	}
	if (l->data == val) {
		List tail = l->next;
		free(l);
		return tail;
	} else {
		l->next = list_delete(l->next, val);
		return l;
	}
}

int main(int argc, char *argv[]) {
	List l = list_from_args(argc, argv);
	list_print(l);
	list_print(list_delete(l, 4));
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
	for (List curr = l; curr != NULL; curr = curr->next) {
		printf("[%d] -> ", curr->data);
	}
	printf("X\n");
}
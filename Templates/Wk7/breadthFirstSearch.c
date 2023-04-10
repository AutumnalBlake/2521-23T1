
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src, int dest) {
	Queue q = QueueNew();
	// pred[i] = the vertex we visited before i
	int *pred = malloc(GraphNumVertices(g) * sizeof(int));
	for (int i = 0; i < GraphNumVertices(g); i++) {
		pred[i] = -1;
	}
	pred[src] = src;

	QueueEnqueue(q, src);

	while (!QueueIsEmpty(q)) {
		int v = QueueDequeue(q);

		if (v == dest) break;

		for (int w = 0; w < GraphNumVertices(g); w++) {
			if (v != w && GraphIsAdjacent(g, v, w) && pred[w] == -1) {
				QueueEnqueue(q, w);
				pred[w] = v;
			}
		}
	}

	for (int i = 0; i < GraphNumVertices(g); i++) {
		printf("Pred[%d] = %d\n", i, pred[i]);
	}

	for (int curr = dest; curr != src; curr = pred[curr]) {
		printf("%d\n", curr);
	}
	printf("%d\n", src);

}

int main(int argc, char *argv[]) {
	Edge edges[12] = {
		{0, 1},
		{0, 2},
		{0, 5},
		{0, 6},
		{0, 7},
		{1, 7},
		{3, 4},
		{3, 5},
		{4, 5},
		{4, 6},
		{4, 7},
		{6, 7},
	};
	Graph g = GraphNewFromEdgeArray(8, 12, edges);
	breadthFirstSearch(g, atoi(argv[1]), atoi(argv[2]));
}


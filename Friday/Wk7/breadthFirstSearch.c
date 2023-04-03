
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src, int target) {
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	int n = GraphNumVertices(g);
	int *visited = calloc(n, sizeof(int));
	visited[src] = 1;

	int *pred = calloc(n, sizeof(int));
	pred[src] = src;

	while (!QueueIsEmpty(q)) {
		int v = QueueDequeue(q);

		printf("%d\n", v);

		if (v == target) break;

		for (int w = 0; w < n; w++) {
			// Skip if
			// - already visited
			// - no edge from v-w
			if (w == v || visited[w] || !GraphIsAdjacent(g, v, w)) {
				continue;
			}

			visited[w] = 1;
			QueueEnqueue(q, w);
			pred[w] = v;
		}
	}

	printf("Path:\n");
	for (int i = target; pred[i] != i; i = pred[i]) {
		printf("%d\n", i);
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


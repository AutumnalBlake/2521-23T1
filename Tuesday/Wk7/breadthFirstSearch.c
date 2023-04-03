
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src) {
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
	breadthFirstSearch(g, atoi(argv[1]));
}


#include "Graph.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int do_reachable(Graph g, int src, bool *visited) {
  visited[src] = true;
  printf("%d\n", src);
  for (int i = 0; i < GraphNumVertices(g); i++) {
    if (GraphIsAdjacent(g, src, i) && !visited[i]) {
      do_reachable(g, i, visited);
    }
  }
}

int reachable(Graph g, int src) {
  printf("From %d:\n", src);
  bool *visited = malloc(GraphNumVertices(g) * sizeof(bool));
  do_reachable(g, src, visited);
}


int main(int argc, char *argv[]) {
    Edge edges[] = {
      {0, 1}, {0, 2}, {0, 3}, {2, 1}, {2, 3}, {2, 4}, {2, 5}, {3, 0},
      {3, 4}, {4, 2}, {4, 5}, {4, 7}, {4, 8}, {5, 1}, {6, 5}, {6, 7},
      {6, 9}, {7, 4}, {7, 5}, {7, 8}, {8, 7}, {9, 7}, {9, 8},
    };

    Graph g = GraphNewFromEdgeArray(10, 23, edges);

    reachable(g, 0);

    reachable(g, 1);

    reachable(g, 5);

    reachable(g, 6);

}
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "Queue.h"


void bfs_adj_matrix(int **adj_matrix, int n, int start);
void bfs_adj_list(ListNode *adj_list, int n, int start);

int main(int argc, char *argv[]) {

    // Graph from BFS/DFS slides
    int n = 8;

    // Build adj matrix
    int **adj_matrix;
    {
        adj_matrix = calloc(n, sizeof(int *));
        for (int i = 0; i < n; i++)
            adj_matrix[i] = calloc(n, sizeof(int));

        int edges1[] = {0,0,0,0,0,1,1,2,3,3,4,4,4,4,5,5,5,6,6,6,7,7,7,7};
        int edges2[] = {1,2,5,6,7,0,7,0,4,5,3,5,6,7,0,3,4,0,4,7,0,1,4,6};

        for (int i = 0; i < 24; i++) {
            adj_matrix[edges1[i]][edges2[i]] = 1;
            adj_matrix[edges2[i]][edges1[i]] = 1;
        }
    }

    bfs_adj_matrix(adj_matrix, n, 0);

    // Build adj list
    ListNode *adj_list;
    {
        adj_list = calloc(n, sizeof(ListNode));
        int adj0[] = {1, 2, 5, 7};
        int adj1[] = {0, 7};
        int adj2[] = {0};
        int adj3[] = {4, 5};
        int adj4[] = {3, 5, 6, 7};
        int adj5[] = {0, 3, 4};
        int adj6[] = {0, 4, 7};
        int adj7[] = {0, 1, 4, 6};

        adj_list[0] = list_from_array(adj0, 4);
        adj_list[1] = list_from_array(adj1, 2);
        adj_list[2] = list_from_array(adj2, 1);
        adj_list[3] = list_from_array(adj3, 2);
        adj_list[4] = list_from_array(adj4, 4);
        adj_list[5] = list_from_array(adj5, 3);
        adj_list[6] = list_from_array(adj6, 3);
        adj_list[7] = list_from_array(adj7, 4);
    }

    bfs_adj_list(adj_list, n, 0);

}

void bfs_adj_matrix(int **adj_matrix, int n, int start) {

}

void bfs_adj_list(ListNode *adj_list, int n, int start) {

}

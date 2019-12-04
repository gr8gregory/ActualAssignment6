#include "graphs.h"
#include <stdlib.h>

static int VertexCounter;
static int** Graph;		// This is the adjacency matrix graph (100 x 100)

static Item* link;		// This is a list of items

void graph_init(int VertexCount) {

	int VertexCounter = 0;
	link = (Item*)calloc(VertexCount, sizeof(int*));	// Allocate space for 100 items

	Graph = (int**)calloc(VertexCount, sizeof(int*));	// Allocate space for 100 x 100 array
	for (int i = 0; i < VertexCount; i++){

		Graph[i] = (int*)calloc(VertexCount, sizeof(int));
	}
}

int graph_insert_vertex(Item Data) {
	
	link[VertexCounter++] = Data;
	return 0;
}

int graph_insert_edge(int v1, int v2) {

	Graph[v1][v2] = 1;
	return 0;
}

int graph_is_adjacent(int v1, int v2) {
	return Graph[v1][v2];
}

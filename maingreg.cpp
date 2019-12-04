#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//The main() for this assignment should look something like this pseudo - code:
int main() {
	int Nodes = 100;	// Number of nodes in the graph
	int Ran_max = 6;	// Max number of connections
	int Ran_min = 2;	// Min number of connections
	graph_init(Nodes);	// Initialize the graph with the 100 Nodes
	srand(time(NULL));	// Initialize the random

	/*** Insert an item into each node ***/
	for (int i = 0; i < Nodes; ++i) {
		Item data;
		data.Data = 1;
		graph_insert_vertex(data);
	}

	int vertex = 0;		// holds the node of the connection

	/********* Connects nodes to eachother ********/
	for (int i = 0; i < Nodes; i++) {

		int nEdges = Ran_min + (rand() % (Ran_max - Ran_min + 1));		// Get a random number of edges from 2 - 6

		for (int j = 0; j < nEdges; ) {

			vertex = (rand() % (Nodes - 1));							// Assign random connections	
			if ((i != vertex) && (graph_is_adjacent(i, vertex) == 0)) {	// If the vertex does not equal itself and 
				graph_insert_edge(i, vertex);
				++j;
			}
		}
	}
	
	/********** The Nodes and their Respective connections **********/
	for (int i = 0; i < Nodes; i++) {

		printf("Node %d Connections:", i);
		for (int j = 0; j < Nodes; j++) {
			
			if (graph_is_adjacent(i, j) > 0) {
				printf(" %d ", j);
			}
		}
		printf("\n");
	}

	return 0;
}

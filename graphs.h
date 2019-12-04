
typedef struct Item {

	int Data;
};

void graph_init(int VertexCount);
int graph_insert_vertex(Item Data);
int graph_insert_edge(int v1, int v2);
int graph_is_adjacent(int v1, int v2);
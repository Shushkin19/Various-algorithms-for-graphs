// I define a graph using an adjacency list

#include"graph.h"

int main() {
	graph g;
	g.initialize_graph("graph_in.txt");
	g.find_cut_point();



	return 0;
}
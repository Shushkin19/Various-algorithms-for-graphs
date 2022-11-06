/*This is a solution to the traveling salesman problem by brute-force search*/
#include"graph.h"
#include<iostream>

int main() {
	graph g;
	g.initialize_graph("graph_1.txt");
	g.hamilton(1);

	return 0;
}


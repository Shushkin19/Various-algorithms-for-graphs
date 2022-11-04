#include"graph.h"
#include<iostream>

int main() {
	graph g;
	g.initialize_graph("graph_1.txt");
	g.hamilton(1);
	//g.find_cycles();
	return 0;
}


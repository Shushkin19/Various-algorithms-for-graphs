#pragma once

struct edgenode {
	int weight;
	int vertex;
	bool vis;
	edgenode();
	edgenode(int _weight, int _vertex);
};

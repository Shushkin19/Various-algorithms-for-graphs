#include "graph.h"
#include<fstream>
#include<iostream>

int graph::ctoi(char c) {
	return c -= '0';
}

graph::graph() {
	this->timer = 0;
	this->n = 0;
}

void graph::initialize_graph(string name) {
	fstream file;
	file.open(name);
	if (file.is_open() == 0) {
		cout << "error";
	}
	n = ctoi(file.get());
	n++;
	g.resize(n);
	visited.resize(n);
	d.resize(n);
	l.resize(n);
	file.get();

	int ch;
	int vertex = 1;
	while (!file.eof()) {
		ch = file.get();
		if (ch == '\n') {
			vertex++;
		}
		else if (ch == ' ' || ch == EOF) {

		}
		else {
			g[vertex].push_back(ctoi(ch));
		}
	}


}

void graph::dfs(int v, int p) {
	visited[v] = true;
	d[v] = l[v] = timer++;
	int count = 0;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];

		if (to == p) {
			continue;
		}

		if (visited[to]) {
			l[v] = min(l[v], d[to]);
		}
		else {
			dfs(to, v);
			++count;
			l[v] = min(l[v], l[to]);
			if (l[to] >= d[v] && p != -1)
				printf(" cut point : % d \n ", v);
		}
	}
	if (p == -1 && count >= 2) { // for root
		printf(" cut point : % d \n ", v);
	}
}


void graph::find_cut_point() {
	for (int i = 0; i < n; ++i) {
		if (visited[i] == false) {
			dfs(i, -1);
		}
	}
}
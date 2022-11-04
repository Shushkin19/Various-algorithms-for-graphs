#include "graph.h"
#include<fstream>
#include<deque>
#include<iostream>

graph::graph() {
	n = 0;
}

int graph::ctoi(char c) {
	return c -= '0';
}

void graph::initialize_graph(const string &name) {
	fstream file;
	file.open(name);
	if (file.is_open() == 0) {
		cout << "error";
	}
	n = ctoi(file.get());
	n++;
	p.resize(n);
	g.resize(n);
	visited.resize(n);
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

void graph::add_ham_cycle(int cycle_end, int cycle_st) {

	vector<int> cyc;
	for (int v = cycle_end; v != cycle_st; v = p[v])
		cyc.push_back(v);
	cyc.push_back(cycle_st);

	reverse(cyc.begin(), cyc.end());
	if (cyc.size() == n - 1) {
		cycle.push_back(cyc);
	}


}

void graph::dfs(int v) {
	visited[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {

		int to = g[v][i];
		if (visited[to] == 0) {
			p[to] = v;
			dfs(to);
		}
		else if (visited[to] == 1) {
			add_ham_cycle(v, to);
		}
	}
	visited[v] = 0;
}

void graph::find_cycles() {
	for (int i = 0; i < n; i++)
		if (visited[i] == 0)
			dfs(i);
}

void graph::hamilton(int cur) {
	find_cycles();
	for (int i = 0; i < cycle.size(); i++) {
		if (cycle[i].size() == n-1) {
			for (int j = 0; j < n-1; j++) {
				cout << cycle[i][j] << " ";
			}
			cout << endl;
		}
	}
	
}
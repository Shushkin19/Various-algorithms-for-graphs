#include "graph.h"
#include<fstream>
#include<iostream>
#include<map>
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
	file >> n;
	n++;
	p.resize(n);
	g.resize(n);
	visited.resize(n);
	file.get();

	unsigned char tmp;
	string buff;
	string tmp_buff;
	int vert;
	int wght;
	int pos;
	int cnt = 1;
	while (!file.eof()) {
		file >> buff;

		pos = buff.find(":");

		tmp_buff = buff.substr(0, pos);
		vert = stoi(tmp_buff);

		tmp_buff = buff.substr(pos+1);
		wght = stoi(tmp_buff);
		g[cnt].push_back(edgenode(wght, vert));
		
		tmp = file.get();
		if (tmp == '\n') {
			cnt++;
		}
	}
	/*
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
			g[vertex].push_back(edgenode(ctoi(ch), 4));
		}
	}*/


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

		int to = g[v][i].vertex;
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

int graph::get_weight(int start_vrt , int end_vrt) {
	int i = 0;
	for (i = 0; i < g[start_vrt].size(); ++i) {
		if (g[start_vrt][i].vertex == end_vrt) {
			break;
		}
	}
	return g[start_vrt][i].weight;
}



void graph::write_to_file(vector<int> vc) {
	fstream fl;
	fl.open("out.dot", ios::out);
	if (fl.is_open() == 0) {
		cout << "error";
	}
	string tmp("digraph G {");
	fl << tmp;
	tmp.clear();
	for (int i = 1; i < g.size(); ++i) {
		for (int k = 0; k < g[i].size(); ++k) {
			tmp = to_string(i) + "->" + to_string(g[i][k].vertex)+ "[label=" + to_string(g[i][k].weight) + "]";
			fl << tmp;
		}
	}
	fl << "}";
}

void graph::hamilton(int cur) {
	find_cycles();
	int total_weight = 0;
	multimap<int,vector<int>> all_weight;
	for (int i = 0; i < cycle.size(); ++i) {
		if (cycle[i][0] != cur) {
			cycle[i].clear();
			continue;
		}
		for (int k = 1; k < cycle[i].size(); ++k) {
			total_weight += get_weight(cycle[i][k - 1], cycle[i][k]);
		}
		all_weight.insert(make_pair(total_weight, cycle[i]));
		total_weight = 0;
	}
	auto it = all_weight.begin();
	write_to_file(it->second);
	for (int i = 0; i < it->second.size(); i++) {
		cout << it->second[i] << ' ';
	}
	
}
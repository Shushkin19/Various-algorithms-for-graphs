#pragma once
#include"edgenode.h"
#include<vector>
#include<string>

using namespace std;

class graph {

	vector<vector<edgenode>> g;
	vector<bool> visited;
	vector<vector<int>> ham_cycles;
	vector<vector<int>> cycle;
	vector<int> p;
	int n;
	int ctoi(char c);

public:
	graph();
	void initialize_graph(const string& name);
	void hamilton(int cur);
	void add_ham_cycle(int cycle_end, int cycle_st);
	void dfs(int v);
	void find_cycles();
	int get_weight(int _vrt, int end_vrt);
	void write_to_file(vector<int> vc);
};


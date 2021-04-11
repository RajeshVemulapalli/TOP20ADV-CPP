#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <queue>
#include "graphutils.cpp"
#include "disjointset2.cpp"
using namespace std;

bool auxDfs(int u, int parent, vector<int> &visit, vector<vector<int>> &in) {
	visit[u] = 1;
	for (int v = 0; v < in.size(); ++v) {
		if (in[u][v] == 1) {
			if (visit[v] == 0) { //forward edge
				if (auxDfs(v, u, visit, in))
					return true;
			} else { //back edge
				if (v != parent)
					return true;
			}
		}
	}
	return false;
}
//TC:Theta(V^2)   SC:Theta(V)
bool detectCycle1(vector<vector<int>> &in) {
	int n = in.size();
	vector<int> visit(n);
	for (int u = 0; u < n; ++u)
		visit[u] = 0;
	for (int u = 0; u < n; ++u) {
		if (visit[u] == 0) {
			if (auxDfs(u, u, visit, in))
				return true;
		}
	}
	return false;
}
//--------------------------------------------------
bool auxBfs(int u, vector<int> &visit, vector<vector<int>> &in) {
	queue<int> q;
	q.push(u);
	visit[u] = 1;

	while (!q.empty()) {
		u = q.front();
		q.pop();
		visit[u] = 2;
		for (int v = 0; v < in.size(); ++v) {
			if (in[u][v] == 1) {
				if (visit[v] == 0) {
					q.push(v);
					visit[v] = 1;
				} else {
					if (visit[v] == 1)
						return true;
				}
			}
		}
	}
	return false;
}
//TC:Theta(V^2)   SC:Theta(V)
bool detectCycle2(vector<vector<int>> &in) {
	int n = in.size();
	vector<int> visit(n);
	for (int u = 0; u < n; ++u)
		visit[u] = 0;
	for (int u = 0; u < n; ++u) {
		if (visit[u] == 0) {
			if (auxBfs(u, visit, in))
				return true;
		}
	}
	return false;
}
//--------------------------------------------------
//TC:Theta(V^2)   SC:Theta(V)
bool detectCycle3(vector<vector<int>> &in) {
	int n = in.size();
	UnionbySizePathCompressionDisjointSet set(n);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (in[i][j] == 1) {
				if (set.find(i) == set.find(j))
					return true;
				set.union_by_size(i, j);
			}
		}
	}
	return false;
}
//----------------------------------------------------
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<vector<int>> in = GraphUtils::randomUndirectedGraph(n);
	GraphUtils::display(in);
	cout << detectCycle1(in) << endl;
	cout << detectCycle2(in) << endl;
	cout << detectCycle3(in) << endl;
}

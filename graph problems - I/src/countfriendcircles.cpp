#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <queue>
#include "graphutils.cpp"
#include "disjointset2.cpp"
using namespace std;

void auxDfs(int u, vector<int> &visit, vector<vector<int>> &in) {
	visit[u] = 1;
	for (int v = 0; v < in.size(); ++v) {
		if (in[u][v] == 1 && visit[v] == 0)
			auxDfs(v, visit, in);
	}
}
//TC:Theta(V^2)   SC:Theta(V)
int countCircles1(vector<vector<int>> &in) {
	int n = in.size();
	int ncircles = 0;
	vector<int> visit(n);
	for (int u = 0; u < n; ++u)
		visit[u] = 0;
	for (int u = 0; u < n; ++u) {
		if (visit[u] == 0) {
			auxDfs(u, visit, in);
			++ncircles;
		}
	}
	return ncircles;
}
//--------------------------------------------------
void auxBfs(int u, vector<int> &visit, vector<vector<int>> &in) {
	queue<int> q;
	q.push(u);
	visit[u] = 1;

	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int v = 0; v < in.size(); ++v) {
			if (in[u][v] == 1 && visit[v] == 0) {
				q.push(v);
				visit[v] = 1;
			}
		}
	}
}

//TC:Theta(V^2)   SC:Theta(V)
int countCircles2(vector<vector<int>> &in) {
	int n = in.size();
	int ncircles = 0;
	vector<int> visit(n);
	for (int u = 0; u < n; ++u)
		visit[u] = 0;
	for (int u = 0; u < n; ++u) {
		if (visit[u] == 0) {
			auxBfs(u, visit, in);
			++ncircles;
		}
	}
	return ncircles;
}
//----------------------------------------------------
//TC:Theta(V^2)   SC:Theta(V)
int countCircles3(vector<vector<int>> &in) {
	int n = in.size();
	UnionbySizePathCompressionDisjointSet set(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (in[i][j] == 1)
				set.union_by_size(i, j);
		}
	}
	return set.size();
}
//----------------------------------------------------
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<vector<int>> in = GraphUtils::randomUndirectedGraph(n);
	GraphUtils::display(in);
	cout << countCircles1(in) << endl;
	cout << countCircles2(in) << endl;
	cout << countCircles3(in) << endl;
}

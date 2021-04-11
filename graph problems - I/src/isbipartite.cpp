#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <queue>
#include "graphutils.cpp"
using namespace std;

void displayPartitions(vector<int> &visit) {
	cout << "Partition-1" << endl;
	for (int u = 0; u < visit.size(); ++u) {
		if (visit[u] == 1)
			cout << u << " ";
	}
	cout << endl;
	cout << "Partition-2" << endl;
	for (int u = 0; u < visit.size(); ++u) {
		if (visit[u] == 2)
			cout << u << " ";
	}
	cout << endl;
}

bool auxDfs(int u, int c, vector<int> &visit, vector<vector<int>> &in) {
	visit[u] = c;
	for (int v = 0; v < in.size(); ++v) {
		if (in[u][v] == 1) {
			if (visit[v] == 0) { //forward edge
				if (!auxDfs(v, visit[u] == 1 ? 2 : 1, visit, in))
					return false;
			} else { //back edge
				if (visit[u] == visit[v])
					return false;
			}
		}
	}
	return true;
}
//TC:Theta(V^2)   SC:Theta(V)
bool isBipartite1(vector<vector<int>> &in) {
	int n = in.size();
	vector<int> visit(n);
	for (int u = 0; u < n; ++u)
		visit[u] = 0;
	for (int u = 0; u < n; ++u) {
		if (visit[u] == 0) {
			if (!auxDfs(u, 1, visit, in))
				return false;
		}
	}
	displayPartitions(visit);
	return true;
}
//--------------------------------------------------
bool auxBfs(int u, vector<int> &visit, vector<vector<int>> &in) {
	queue<int> q;
	q.push(u);
	visit[u] = 1;

	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int v = 0; v < in.size(); ++v) {
			if (in[u][v] == 1) {
				if (visit[v] == 0) {
					q.push(v);
					visit[v] = (visit[u] == 1 ? 2 : 1);
				} else {
					if (visit[v] == visit[u])
						return false;
				}
			}
		}
	}
	return true;
}
//TC:Theta(V^2)   SC:Theta(V)
bool isBipartite2(vector<vector<int>> &in) {
	int n = in.size();
	vector<int> visit(n);
	for (int u = 0; u < n; ++u)
		visit[u] = 0;
	for (int u = 0; u < n; ++u) {
		if (visit[u] == 0) {
			if (!auxBfs(u, visit, in))
				return false;
		}
	}
	displayPartitions(visit);
	return true;
}
//--------------------------------------------------
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<vector<int>> in = GraphUtils::randomUndirectedGraph(n);
	GraphUtils::display(in);
	cout << isBipartite1(in) << endl;
	cout << isBipartite2(in) << endl;
}


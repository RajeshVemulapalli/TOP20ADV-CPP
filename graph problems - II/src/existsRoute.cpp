#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
#include "graphutils.cpp"
using namespace std;

bool auxDfs(int u, int t, vector<int> &visit, vector<vector<int>> &in) {
	if (u == t)
		return true;
	visit[u] = 1;
	for (int v = 0; v < in.size(); ++v) {
		if (in[u][v] == 1 && visit[v] == 0)
			if (auxDfs(v, t, visit, in))
				return true;
	}
	return false;
}
//TC:Theta(V^2)   SC:Theta(V)
bool existsRoute1(vector<vector<int>> &in, int s, int t) {
	int n = in.size();
	vector<int> visit(n);
	for (int u = 0; u < n; ++u)
		visit[u] = 0;
	return auxDfs(s, t, visit, in);
}
//--------------------------------------------------
bool auxBfs(int u, int t, vector<int> &visit, vector<vector<int>> &in) {
	if (u == t)
		return true;
	queue<int> q;
	q.push(u);
	visit[u] = 1;

	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int v = 0; v < in.size(); ++v) {
			if (in[u][v] == 1 && visit[v] == 0) {
				if (v == t)
					return true;
				q.push(v);
				visit[v] = 1;
			}
		}
	}
	return false;
}

//TC:Theta(V^2)   SC:Theta(V)
bool existsRoute2(vector<vector<int>> &in, int s, int t) {
	int n = in.size();
	vector<int> visit(n);
	for (int u = 0; u < n; ++u)
		visit[u] = 0;
	return auxBfs(s, t, visit, in);
}
//----------------------------------------------------
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<vector<int>> in = GraphUtils::randomUndirectedGraph(n);
	GraphUtils::display(in);
	srand(time(0));
	int s = rand() % n;
	int t = rand() % n;
	cout << s << "," << t << endl;
	cout << existsRoute1(in, s, t) << endl;
	cout << existsRoute2(in, s, t) << endl;

}

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
#include "graphutils.cpp"
using namespace std;

void auxDfs(int u, int t, vector<int> &visit, vector<vector<int>> &in,
		string path) {
	if (u == t) {
		cout << path << endl;
		return;
	}
	visit[u] = 1;
	for (int v = 0; v < in.size(); ++v) {
		if (in[u][v] == 1 && visit[v] == 0)
			auxDfs(v, t, visit, in, path + to_string(v) + "->");
	}
	visit[u] = 0;
}
//TC:Theta(V^V)   SC:Theta(V)
void allRoutes(vector<vector<int>> &in, int s, int t) {
	int n = in.size();
	vector<int> visit(n);
	for (int u = 0; u < n; ++u)
		visit[u] = 0;
	auxDfs(s, t, visit, in, to_string(s) + "->");
}

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<vector<int>> in = GraphUtils::completeGraph(n);
	GraphUtils::display(in);
	srand(time(0));
	int s = rand() % n;
	int t = rand() % n;
	cout << s << "," << t << endl;
	allRoutes(in, s, t);
}

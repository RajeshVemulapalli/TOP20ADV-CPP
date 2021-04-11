#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <queue>
#include "graphutils.cpp"
#include "disjointset2.cpp"
using namespace std;

void auxDfs(int u, int v, vector<vector<int>> &visit, vector<vector<int>> &in) {
	if (u < 0 || u >= in.size() || v < 0 || v >= in[0].size() || in[u][v] == 0
			|| visit[u][v] == 1)
		return;
	visit[u][v] = 1;
	auxDfs(u - 1, v, visit, in);
	auxDfs(u + 1, v, visit, in);
	auxDfs(u, v - 1, visit, in);
	auxDfs(u, v + 1, visit, in);
}
//TC:Theta(mn)   SC:Theta(mn)
int countIslands1(vector<vector<int>> &in) {
	int m = in.size();
	int n = in[0].size();
	int nislands = 0;

	vector<vector<int>> visit(m);
	for (int u = 0; u < m; ++u)
		visit[u] = vector<int>(n);

	for (int u = 0; u < m; ++u) {
		for (int v = 0; v < n; ++v) {
			if (in[u][v] == 1 && visit[u][v] == 0) {
				auxDfs(u, v, visit, in);
				++nislands;
			}
		}
	}
	return nislands;
}
//--------------------------------------------------

bool isValid(int r, int c, vector<vector<int>> &visit,
		vector<vector<int>> &in) {
	if (r < 0 || r >= in.size() || c < 0 || c >= in[0].size() || in[r][c] == 0
			|| visit[r][c] == 1)
		return false;
	return true;
}
void auxBfs(int u, int v, vector<vector<int>> &visit, vector<vector<int>> &in) {
	queue<pair<int, int>> q;
	q.push(make_pair(u, v));
	visit[u][v] = 1;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		if (isValid(p.first - 1, p.second, visit, in)) {
			visit[p.first - 1][p.second] = 1;
			q.push(make_pair(p.first - 1, p.second));
		}
		if (isValid(p.first + 1, p.second, visit, in)) {
			visit[p.first + 1][p.second] = 1;
			q.push(make_pair(p.first + 1, p.second));
		}
		if (isValid(p.first, p.second - 1, visit, in)) {
			visit[p.first][p.second - 1] = 1;
			q.push(make_pair(p.first, p.second - 1));
		}
		if (isValid(p.first, p.second + 1, visit, in)) {
			visit[p.first][p.second + 1] = 1;
			q.push(make_pair(p.first, p.second + 1));
		}

	}
}
//TC:Theta(mn)   SC:Theta(mn)
int countIslands2(vector<vector<int>> &in) {
	int m = in.size();
	int n = in[0].size();
	int nislands = 0;

	vector<vector<int>> visit(m);
	for (int u = 0; u < m; ++u)
		visit[u] = vector<int>(n);

	for (int u = 0; u < m; ++u) {
		for (int v = 0; v < n; ++v) {
			if (in[u][v] == 1 && visit[u][v] == 0) {
				auxBfs(u, v, visit, in);
				++nislands;
			}
		}
	}
	return nislands;
}
//--------------------------------------------------
void auxUnion(int i, int j, int x, int y, vector<vector<int>> &in,
		UnionbySizePathCompressionDisjointSet &set) {
	if (x < 0 || x >= in.size() || y < 0 || y >= in[0].size() || in[x][y] == 0)
		return;
	int n = in[0].size();
	set.union_by_size(i * n + j, x * n + y);
}
//TC:Theta(mn)   SC:Theta(mn)
int countIslands3(vector<vector<int>> &in) {
	int m = in.size();
	int n = in[0].size();
	UnionbySizePathCompressionDisjointSet set(m * n);
	int nzeros = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (in[i][j] == 1) {
				auxUnion(i, j, i - 1, j, in, set);
				auxUnion(i, j, i, j - 1, in, set);
			} else
				++nzeros;
		}
	}
	return set.size() - nzeros;
}
//-----------------------------------------------------
int main(int argc, char *argv[]) {
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	vector<vector<int>> in = GraphUtils::randomGrid(m, n, m + n);
	GraphUtils::display(in);
	cout << countIslands1(in) << endl;
	cout << countIslands2(in) << endl;
	cout << countIslands3(in) << endl;
}

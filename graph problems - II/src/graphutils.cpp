#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

class GraphUtils {
public:
	static vector<vector<int>> randomUndirectedGraph(int n) {
		vector<vector<int>> in(n);
		for (int i = 0; i < n; ++i)
			in[i] = vector<int>(n);
		srand(time(0));
		for (int i = 0; i < n; ++i) {
			int u = rand() % n;
			int v = rand() % n;
			if (u != v) {
				in[u][v] = 1;
				in[v][u] = 1;
			}
		}
		return in;
	}

	static vector<vector<int>> randomGrid(int m, int n, int nedges) {
		vector<vector<int>> in(m);
		for (int i = 0; i < m; ++i)
			in[i] = vector<int>(n);
		srand(time(0));
		for (int i = 0; i < nedges; ++i) {
			int u = rand() % m;
			int v = rand() % n;
			in[u][v] = 1;
		}
		return in;
	}

	static vector<vector<int>> completeGraph(int n) {
		vector<vector<int>> in(n);
		for (int i = 0; i < n; ++i)
			in[i] = vector<int>(n);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				in[i][j] = 1;
				in[j][i] = 1;
			}
		}
		return in;
	}

	static void display(vector<vector<int>> &in) {
		for (auto v : in) {
			for (auto e : v) {
				cout << e << " ";
			}
			cout << endl;
		}
	}
};

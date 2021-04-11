#include <cstdlib>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

void traceOptimalRoute(vector<int> &in, vector<vector<int>> &mem) {
	int i = mem.size() - 1;
	int j = 0;
	while (i > 0 && j < in.size()) {
		if (in[j] > i)
			j = j + 1;
		else {
			int inclusive =
					mem[i - in[j]][j] == INT_MAX ?
							mem[i - in[j]][j] : mem[i - in[j]][j] + 1;
			int exclusive = mem[i][j + 1];
			if (inclusive < exclusive) {
				cout << in[j] << "+";
				i = i - in[j];
			} else
				j = j + 1;
		}
	}
	cout << endl;
}
//TC:Theta(nS)  SC:Theta(nS)
int minCoinChange(vector<int> &in, int s) {
	int n = in.size();
	vector<vector<int>> mem(s + 1);
	for (int i = 0; i <= s; ++i)
		mem[i] = vector<int>(n + 1);

	for (int j = 0; j <= n; ++j)
		mem[0][j] = 0;
	for (int i = 1; i <= s; ++i)
		mem[i][n] = INT_MAX;

	for (int i = 1; i <= s; ++i) {
		for (int j = n - 1; j >= 0; --j) {
			if (in[j] > i)
				mem[i][j] = mem[i][j + 1];
			else {
				int inclusive =
						mem[i - in[j]][j] == INT_MAX ?
								mem[i - in[j]][j] : mem[i - in[j]][j] + 1;
				int exclusive = mem[i][j + 1];
				mem[i][j] = min(inclusive, exclusive);
			}
		}
	}
	for (auto v : mem) {
		for (auto e : v)
			cout << e << " ";
		cout << endl;
	}
	traceOptimalRoute(in, mem);
	return mem[s][0];
}
int main(int argc, char *argv[]) {
	vector<int> in = { 1, 3, 4 };
	int s = 15;
	for (auto e : in)
		cout << e << " ";
	cout << endl;
	cout << s << endl;
	cout << minCoinChange(in, s) << endl;
}

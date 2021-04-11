#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

void auxKnapsack1(int start, int m, int csum, vector<int> &in, int &gmax) {
	if (m < 0)
		return;
	gmax = max(gmax, csum);
	for (int i = start; i < in.size(); ++i) {
		if (in[i] <= m) {
			auxKnapsack1(i + 1, m - in[i], csum + in[i], in, gmax);
		}
	}
}
//TC:O(2^n)   SC:O(n)
int knapsack1(vector<int> &in, int m) {
	int gmax = 0;
	auxKnapsack1(0, m, 0, in, gmax);
	return gmax;
}
//---------------------------------------
void traceOptimalRoute(vector<int> &in, vector<vector<int>> &mem) {
	int i = mem.size() - 1;
	int j = 0;
	while (i > 0 && j < in.size()) {
		if (in[j] > i)
			j = j + 1;
		else {
			int inclusive = mem[i - in[j]][j + 1] + in[j];
			int exclusive = mem[i][j + 1];
			if (inclusive > exclusive) {
				cout << in[j] << "+";
				i = i - in[j];
				j = j + 1;
			} else
				j = j + 1;
		}
	}
	cout << endl;
}
//TC:Theta(nm)  SC:Theta(nm)
int knapsack3(vector<int> &in, int m) {
	int n = in.size();
	vector<vector<int>> mem(m + 1);
	for (int i = 0; i <= m; ++i)
		mem[i] = vector<int>(n + 1);

	for (int j = 0; j <= n; ++j)
		mem[0][j] = 0;
	for (int i = 1; i <= m; ++i)
		mem[i][n] = 0;

	for (int i = 1; i <= m; ++i) {
		for (int j = n - 1; j >= 0; --j) {
			if (in[j] > i)
				mem[i][j] = mem[i][j + 1];
			else {
				int inclusive = mem[i - in[j]][j + 1] + in[j];
				int exclusive = mem[i][j + 1];
				mem[i][j] = max(inclusive, exclusive);
			}
		}
	}
	for (auto v : mem) {
		for (auto e : v)
			cout << e << " ";
		cout << endl;
	}
	traceOptimalRoute(in, mem);
	return mem[m][0];
}
//-------------------------------------------
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	vector<int> in(n);

	srand(time(0));
	for (int i = 0; i < n; ++i)
		in[i] = rand() % (2 * n) + 1;

	for (auto e : in)
		cout << e << " ";
	cout << endl;
	cout << m << endl;
	cout << knapsack1(in, m) << endl;
	cout << knapsack3(in, m) << endl;
}

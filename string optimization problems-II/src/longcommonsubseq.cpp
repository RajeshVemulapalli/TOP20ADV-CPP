#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

void traceOptimalRoute(string s1, string s2, vector<vector<int>> &mem) {
	int i = 0, j = 0;
	while (i < s1.length() && j < s2.length()) {
		if (s1[i] == s2[j]) {
			cout << s1[i];
			++i;
			++j;
		} else if (mem[i][j + 1] > mem[i + 1][j])
			++j;
		else
			++i;
	}
	cout << endl;
}
//TC:Theta(mn)  SC:Theta(mn)
int longComSubseq(string s1, string s2) {
	int n = s1.length();
	int m = s2.length();
	vector<vector<int>> mem(n + 1);
	for (int i = 0; i <= n; ++i)
		mem[i] = vector<int>(m + 1);

	for (int i = 0; i <= n; ++i)
		mem[i][m] = 0;
	for (int j = 0; j <= m; ++j)
		mem[n][j] = 0;

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (s1[i] == s2[j])
				mem[i][j] = 1 + mem[i + 1][j + 1];
			else
				mem[i][j] = max(mem[i][j + 1], mem[i + 1][j]);
		}
	}
	for (auto v : mem) {
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;
	}
	traceOptimalRoute(s1, s2, mem);
	return mem[0][0];
}

int main(int argc, char *argv[]) {
	cout << argv[1] << endl;
	cout << argv[2] << endl;
	cout << longComSubseq(argv[1], argv[2]);
}

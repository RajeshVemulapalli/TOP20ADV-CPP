#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

void traceOptimalRoute(string s1, string s2, vector<vector<int>> &mem) {
	int n = s1.length();
	int m = s2.length();
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (s1[i] == s2[j]) {
			++i;
			++j;
		} else {
			int ic = mem[i][j + 1];
			int dc = mem[i + 1][j];
			int rc = mem[i + 1][j + 1];
			if (ic < dc) {
				if (ic < rc) {
					cout << "Insert Character " << s2[j] << endl;
					++j;
				} else {
					cout << "Replace "  << s1[i] << " with " << s2[j] << endl;
					++i;
					++j;
				}
			} else {
				if (dc < rc) {
					cout << "Delete Character " << s1[i] << endl;
					++i;
				} else {
					cout << "Replace "  << s1[i] << " with " << s2[j] << endl;
					++i;
					++j;
				}
			}
		}
	}
	if (i < n) {
		cout << "Delete characters " + s1.substr(i) << endl;
	}
	if (j < m) {
		cout << "Insert characters " + s2.substr(j) << endl;
	}
}
//TC:Theta(mn)   SC:Theta(mn)
int editDistance(string s1, string s2) {
	int n = s1.length();
	int m = s2.length();
	vector<vector<int>> mem(n + 1);
	for (int i = 0; i <= n; ++i)
		mem[i] = vector<int>(m + 1);

	for (int j = 0; j <= m; ++j)
		mem[n][j] = m - j;
	for (int i = 0; i <= n; ++i)
		mem[i][m] = n - i;

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (s1[i] == s2[j])
				mem[i][j] = mem[i + 1][j + 1];
			else
				mem[i][j] = min(mem[i][j + 1],
						min(mem[i + 1][j], mem[i + 1][j + 1])) + 1;
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
	cout << editDistance(argv[1], argv[2]);
}

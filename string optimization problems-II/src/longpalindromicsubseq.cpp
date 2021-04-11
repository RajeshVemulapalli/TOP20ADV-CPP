#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

string rev(string s) {
	string tmp = "";
	for (int i = s.length() - 1; i >= 0; --i)
		tmp += s[i];
	return tmp;

}
void traceOptimalRoute(string s, vector<vector<int>> &mem) {
	int i = 0, j = s.length() - 1;
	string res = "";
	while (i < j) {
		if (s[i] == s[j]) {
			res += s[i];
			i += 1;
			j -= 1;
		} else if (mem[i + 1][j] > mem[i][j - 1]) {
			i += 1;
		} else {
			j -= 1;
		}
	}
	if (i == j)
		cout << res << s[i] << rev(res) << endl;
	else
		cout << res << rev(res) << endl;
}
//TC:Theta(n^2)  SC:Theta(n^2)
int longPalSubseq(string s) {
	int n = s.length();
	vector<vector<int>> mem(n);
	for (int i = 0; i < n; ++i)
		mem[i] = vector<int>(n, 0);

	for (int i = 0; i < n; ++i)
		mem[i][i] = 1;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			if (s[i] == s[j])
				mem[i][j] = 2 + mem[i + 1][j - 1];
			else
				mem[i][j] = max(mem[i + 1][j], mem[i][j - 1]);
		}
	}
	for (auto v : mem) {
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;
	}
	traceOptimalRoute(s, mem);
	return mem[0][n - 1];
}

int main(int argc, char *argv[]) {
	cout << argv[1] << endl;
	cout << longPalSubseq(argv[1]);
}

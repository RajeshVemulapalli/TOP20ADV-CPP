#include <cstdlib>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

void traceOptimalRoute(vector<int> &in, vector<int> &mem) {
	int i = mem.size() - 1;
	while (i > 0) {
		for (int j = 0; j < in.size(); ++j) {
			if (in[j] <= i) {
				if (mem[i - in[j]] + 1 == mem[i]) {
					cout << in[j] << "+";
					i = i - in[j];
					break;
				}
			}
		}
	}
	cout << endl;
}
//TC:Theta(nS)  SC:Theta(S)
int minCoinChange(vector<int> &in, int s) {
	vector<int> mem(s + 1);
	mem[0] = 0;
	for (int i = 1; i <= s; ++i) {
		int mn = INT_MAX;
		for (int j = 0; j < in.size(); ++j) {
			if (in[j] <= i)
				mn = min(mn, mem[i - in[j]] + 1);
		}
		mem[i] = mn;
	}
	for (auto e : mem)
		cout << e << " ";
	cout << endl;
	traceOptimalRoute(in, mem);
	return mem[s];
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

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void traceOptimalRoute(vector<int> mem, vector<int> in) {
	int i = 0;
	while(i < in.size()) {
		cout << in[i] << " ";
		if(mem[i] == mem[i+1] + in[i])
			i = i + 1;
		else
			i = i + 2;
	}
	cout << endl;
}
int minCostJump(vector<int> in) {
	vector<int> mem(in.size() + 1);
	mem[mem.size() - 1] = 0;
	mem[mem.size() - 2] = in[in.size() - 1];
	for (int i = mem.size() - 3; i >= 0; --i)
		mem[i] = min(mem[i + 1], mem[i + 2]) + in[i];
	traceOptimalRoute(mem, in);
	return mem[0];
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<int> in(n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
		in[i] = rand() % n + 1;
	for (auto it = in.begin(); it != in.end(); ++it)
		cout << *it << " ";
	cout << endl;
	cout << minCostJump(in) << endl;
}

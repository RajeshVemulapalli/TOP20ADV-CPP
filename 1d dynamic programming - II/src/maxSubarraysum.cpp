#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//TC:Theta(n)   SC:Theta(n)
int maxSubarraySum(vector<int> &in) {
	vector<int> mem(in.size() + 1);
	mem[mem.size() - 1] = 0;
	int gmax = INT_MIN;
	int pos = in.size();
	for (int i = mem.size() - 2; i >= 0; --i) {
		mem[i] = max(in[i], in[i] + mem[i + 1]);
		//gmax = max(gmax, mem[i]);
		if (mem[i] > gmax) {
			gmax = mem[i];
			pos = i;
		}
	}
	cout << pos << endl;
	return gmax;
}

//TC:Theta(n)   SC:O(1)
int maxSubarraySumOpt(vector<int> &in) {
	int res = 0;
	int gmax = INT_MIN;
	int pos = in.size();
	for (int i = in.size() - 1; i >= 0; --i) {
		res = max(in[i], in[i] + res);
		if (res > gmax) {
			gmax = res;
			pos = i;
		}
	}
	cout << pos << endl;
	return gmax;
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<int> in(n);
	srand(time(0));
	for (int i = 0; i < n; ++i) {
		in[i] = rand() % n + 1;
		if (rand() % 2 == 0)
			in[i] *= -1;
	}
	for (auto it = in.begin(); it != in.end(); ++it)
		cout << *it << " ";
	cout << endl;
	cout << maxSubarraySum(in) << endl;
	cout << maxSubarraySumOpt(in) << endl;
}

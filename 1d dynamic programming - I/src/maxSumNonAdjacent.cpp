#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void auxMaxSum1(int i, int psum, int &gmax, vector<int> &in) {
	if (i >= in.size()) {
		gmax = max(gmax, psum);
		return;
	}
	auxMaxSum1(i + 2, psum + in[i], gmax, in);
	auxMaxSum1(i + 1, psum, gmax, in);
}
//TC:Theta(2^n)   SC:Theta(n)
int maxSum1(vector<int> &in) {
	int gmax = INT_MIN;
	auxMaxSum1(0, 0, gmax, in);
	return gmax;
}

int auxMaxSum2(int i, vector<int> &in) {
	if (i >= in.size())
		return 0;
	int inclusive = auxMaxSum2(i + 2, in) + in[i];
	int exclusive = auxMaxSum2(i + 1, in);
	return max(inclusive, exclusive);
}
//TC:Theta(2^n)   SC:Theta(n)
int maxSum2(vector<int> &in) {
	return auxMaxSum2(0, in);
}

int auxMaxSum3(int i, vector<int> &mem, vector<int> &in) {
	if (i >= in.size())
		return 0;
	if (mem[i] != 0)
		return mem[i];
	int inclusive = auxMaxSum3(i + 2, mem, in) + in[i];
	int exclusive = auxMaxSum3(i + 1, mem, in);
	mem[i] = max(inclusive, exclusive);
	return mem[i];
}
//TC:Theta(n)   SC:Theta(n)
int maxSum3(vector<int> &in) {
	vector<int> mem(in.size());
	return auxMaxSum3(0, mem, in);
}

void traceOptimalRoute(vector<int> &mem, vector<int> &in) {
	for(auto it = mem.begin(); it!= mem.end(); ++it)
		cout << *it << " ";
	cout << endl;
	int i = 0;
	while (i < in.size()) {
		if (mem[i] == mem[i + 1])
			i = i + 1;
		else {
			cout << in[i] << " ";
			i = i + 2;
		}
	}
	cout << endl;
}

//TC:Theta(n)   SC:Theta(n)
int maxSum4(vector<int> &in) {
	vector<int> mem(in.size() + 2);
	mem[in.size()] = mem[in.size() + 1] = 0;
	for (int i = in.size() - 1; i >= 0; --i) {
		int inclusive = mem[i + 2] + in[i];
		int exclusive = mem[i + 1];
		mem[i] = max(inclusive, exclusive);
	}
	traceOptimalRoute(mem, in);
	return mem[0];
}


int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<int> in(n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
		in[i] = rand() % n;
	for(auto it = in.begin(); it!= in.end(); ++it)
		cout << *it << " ";
	cout << endl;
	//cout << maxSum1(in) << endl;
	//cout << maxSum2(in) << endl;
	//cout << maxSum3(in) << endl;
	cout << maxSum4(in) << endl;
}

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void auxMaxSum1(int i, int psum, int &gmax, vector<int> &in) {
	if (i < 0) {
		gmax = max(gmax, psum);
		return;
	}
	auxMaxSum1(i - 2, psum + in[i], gmax, in);
	auxMaxSum1(i - 1, psum, gmax, in);
}
//TC:Theta(2^n)   SC:Theta(n)
int maxSum1(vector<int> &in) {
	int gmax = INT_MIN;
	auxMaxSum1(in.size()-1, 0, gmax, in);
	return gmax;
}

int auxMaxSum2(int i, vector<int> &in) {
	if (i < 0)
		return 0;
	int inclusive = auxMaxSum2(i - 2, in) + in[i];
	int exclusive = auxMaxSum2(i - 1, in);
	return max(inclusive, exclusive);
}
//TC:Theta(2^n)   SC:Theta(n)
int maxSum2(vector<int> &in) {
	return auxMaxSum2(in.size()-1, in);
}

int auxMaxSum3(int i, vector<int> &mem, vector<int> &in) {
	if (i < 0)
		return 0;
	if (mem[i] != 0)
		return mem[i];
	int inclusive = auxMaxSum3(i - 2, mem, in) + in[i];
	int exclusive = auxMaxSum3(i - 1, mem, in);
	mem[i] = max(inclusive, exclusive);
	return mem[i];
}
//TC:Theta(n)   SC:Theta(n)
int maxSum3(vector<int> &in) {
	vector<int> mem(in.size());
	return auxMaxSum3(in.size()-1, mem, in);
}

void traceOptimalRoute(int i, vector<int> &mem, vector<int> &in) {
	if(i <= 1) return;
	if (mem[i] == mem[i - 1])
		traceOptimalRoute(i-1, mem, in);
	else {
		traceOptimalRoute(i-2, mem, in);
		cout << in[i-2] << " ";
	}
}

//TC:Theta(n)   SC:Theta(n)
int maxSum4(vector<int> &in) {
	vector<int> mem(in.size() + 2);
	mem[0] = mem[1] = 0;
	for (int i = 2; i < mem.size(); ++i) {
		int inclusive = mem[i - 2] + in[i-2];
		int exclusive = mem[i - 1];
		mem[i] = max(inclusive, exclusive);
	}
	traceOptimalRoute(mem.size()-1, mem, in);
	cout << endl;
	return mem[mem.size()-1];
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

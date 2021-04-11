#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void auxMaxCoins1(int i, int j, int psum, int &gmax, vector<vector<int>> &in) {
	if (i >= in.size() || j >= in.size())
		return;
	if (i == in.size() - 1 && j == in.size() - 1) {
		gmax = max(gmax, psum + in[i][j]);
		return;
	}
	auxMaxCoins1(i + 1, j, psum + in[i][j], gmax, in);
	auxMaxCoins1(i, j + 1, psum + in[i][j], gmax, in);
}
//TC:Theta(2^2n)  SC:Theta(n)
int maxCoins1(vector<vector<int>> &in) {
	int gmax = 0;
	auxMaxCoins1(0, 0, 0, gmax, in);
	return gmax;
}
//------------------------------------------------------
int auxMaxCoins2(int i, int j, vector<vector<int>> &in) {
	if (i >= in.size() || j >= in.size())
		return 0;
	int bsum = auxMaxCoins2(i + 1, j, in);
	int rsum = auxMaxCoins2(i, j + 1, in);
	return max(bsum, rsum) + in[i][j];
}
//TC:Theta(2^2n)  SC:Theta(n)
int maxCoins2(vector<vector<int>> &in) {
	return auxMaxCoins2(0, 0, in);
}
//------------------------------------------------------
int auxMaxCoins3(int i, int j, vector<vector<int>> &mem,
		vector<vector<int>> &in) {
	if (i >= in.size() || j >= in.size())
		return 0;
	if (mem[i][j] != 0)
		return mem[i][j];
	int bsum = auxMaxCoins3(i + 1, j, mem, in);
	int rsum = auxMaxCoins3(i, j + 1, mem, in);
	mem[i][j] = max(bsum, rsum) + in[i][j];
	return mem[i][j];
}
//TC:Theta(n^2)  SC:Theta(n^2)
int maxCoins3(vector<vector<int>> &in) {
	int n = in.size();
	vector<vector<int>> mem(n);
	for (int i = 0; i < n; ++i)
		mem[i] = vector<int>(n);
	return auxMaxCoins3(0, 0, mem, in);
}
//------------------------------------------------------
void traceOptimalRoute(vector<vector<int>> &mem, vector<vector<int>> &in) {
	int i = 0, j = 0;
	while (i < in.size() && j < in.size()) {
		cout << in[i][j] << " ";
		if (mem[i + 1][j] > mem[i][j + 1])
			i = i + 1;
		else
			j = j + 1;
	}
	cout << endl;
}

//TC:Theta(n^2)  SC:Theta(n^2)
int maxCoins4(vector<vector<int>> &in) {
	int n = in.size();
	vector<vector<int>> mem(n + 1);
	for (int i = 0; i <= n; ++i)
		mem[i] = vector<int>(n + 1);
	for (int i = 0; i < n; ++i) {
		mem[n][i] = 0;
		mem[i][n] = 0;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			int bsum = mem[i + 1][j];
			int rsum = mem[i][j + 1];
			mem[i][j] = max(bsum, rsum) + in[i][j];
		}
	}
	traceOptimalRoute(mem, in);
	return mem[0][0];
}
//------------------------------------------------------
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	srand(time(0));
	vector<vector<int>> in(n);
	for (int i = 0; i < n; ++i) {
		in[i] = vector<int>(n);
		for (int j = 0; j < n; ++j) {
			in[i][j] = rand() % n + 1;
			cout << in[i][j] << " ";
		}
		cout << endl;
	}
	//cout << maxCoins1(in) << endl;
	//cout << maxCoins2(in) << endl;
	//cout << maxCoins3(in) << endl;
	cout << maxCoins4(in) << endl;
}

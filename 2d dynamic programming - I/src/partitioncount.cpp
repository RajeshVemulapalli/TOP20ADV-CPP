#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

//TC:Theta(n^3)  SC:Theta(n^2)
int partitionCount31(int n) {
	vector<vector<int>> mem(n + 1);
	for (int i = 0; i <= n; ++i)
		mem[i] = vector<int>(n + 1);
	for (int j = 1; j <= n; ++j)
		mem[0][j] = mem[1][j] = mem[j][1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= n; ++j) {
			if (j > i)
				mem[i][j] = mem[i][i];
			else {
				int sum = 0;
				for (int k = j; k >= 1; --k)
					sum += mem[i - k][k];
				mem[i][j] = sum;
			}
		}
	}
	for(auto v:mem) {
		for(auto e:v) {
			cout << e << " ";
		}
		cout << endl;
	}
	return mem[n][n];
}

//TC:Theta(n^2)  SC:Theta(n^2)
int partitionCount32(int n) {
	vector<vector<int>> mem(n + 1);
	for (int i = 0; i <= n; ++i)
		mem[i] = vector<int>(n + 1);
	for (int j = 1; j <= n; ++j)
		mem[0][j] = mem[1][j] = mem[j][1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= n; ++j) {
			if (j > i)
				mem[i][j] = mem[i][i];
			else
				mem[i][j] = mem[i][j-1] + mem[i-j][j];
		}
	}
	for(auto v:mem) {
		for(auto e:v) {
			cout << e << " ";
		}
		cout << endl;
	}
	return mem[n][n];
}

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	cout << n<< endl;
	cout << partitionCount31(n) << endl;
	cout << partitionCount32(n) << endl;
}

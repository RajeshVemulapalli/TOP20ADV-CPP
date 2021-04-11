#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

bool isValid1(int out[], int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (out[i] == out[j] || abs(i - j) == abs(out[i] - out[j]))
				return false;
		}
	}
	return true;
}
void auxNqueens1(int q, int n, int out[]) {
	if (q == n) {
		if (isValid1(out, n)) {
			for (int i = 0; i < n; ++i)
				cout << out[i] << " ";
			cout << endl;
		}
		return;
	}
	for (int c = 0; c < n; ++c) {
		out[q] = c;
		auxNqueens1(q + 1, n, out);
	}
}
void nqueens1(int n) {
	int out[n];
	auxNqueens1(0, n, out);
}
//------------------------------------------------
bool isValid2(int q, int c, int out[]) {
	for (int i = 0; i < q; ++i) {
		if (out[i] == c || abs(i - q) == abs(out[i] - c))
			return false;
	}
	return true;
}
void auxNqueens2(int q, int n, int out[]) {
	if (q == n) {
		for (int i = 0; i < n; ++i)
			cout << out[i] << " ";
		cout << endl;
		return;
	}
	for (int c = 0; c < n; ++c) {
		if (isValid2(q, c, out)) {
			out[q] = c;
			auxNqueens2(q + 1, n, out);
		}
	}
}
void nqueens2(int n) {
	int out[n];
	auxNqueens2(0, n, out);
}
//------------------------------------------------
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	nqueens2(n);
}

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;

//TC:Theta(n log n)  SC:O(1)
int minCoins11(int n, int b, int s) {
	int ncoins = 0;
	for (int i = n - 1; i >= 0 && s > 0; --i) {
		int denom = pow(b, i);
		if (denom <= s) {
			ncoins += (s / denom);
			s = s % denom;
		}
	}
	return ncoins;
}

//TC:Theta(n)  SC:O(1)
int minCoins12(int n, int b, int s) {
	int ncoins = 0;
	int denom = pow(b, n-1);
	while(s > 0) {
		if (denom <= s) {
			ncoins += (s / denom);
			s = s % denom;
		}
		denom /= b;
	}
	return ncoins;
}

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	int b = atoi(argv[2]);
	int s = atoi(argv[3]);
	cout << n << " " << b << " " << s << endl;
	cout << minCoins11(n, b, s) << endl;
	cout << minCoins12(n, b, s) << endl;
}

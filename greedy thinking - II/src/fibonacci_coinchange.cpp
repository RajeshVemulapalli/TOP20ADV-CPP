#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//TC:Theta(log S)   SC:O(1)
int minCoins(int s) {
	int f1 = 0;
	int f2 = 1;
	while (f2 <= s) {
		cout << f2 << " ";
		int tmp = f1 + f2;
		f1 = f2;
		f2 = tmp;
	}
	cout << endl;
	int ncoins = 0;
	while (s > 0) {
		if (f1 <= s) {
			ncoins += (s / f1);
			s %= f1;
		}
		int tmp = f2 - f1;
		f2 = f1;
		f1 = tmp;
	}
	return ncoins;
}

int main(int argc, char *argv[]) {
	int s = atoi(argv[1]);
	cout << s << endl;
	cout << minCoins(s) << endl;
}

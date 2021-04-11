#include <cstdlib>
#include <ctime>
#include <iostream>
#include "bitwiseutils.cpp"
using namespace std;

int countOnes1(int n) {
	int size = sizeof(int) * 8;
	unsigned mask = 1 << (size - 1);
	int n_ones = 0;
	for (int i = 1; i <= size; ++i) {
		if ((n & mask) != 0)
			++n_ones;
		mask = mask >> 1;
	}
	return n_ones;
}

int countOnes2(int n) {
	int n_ones = 0;
	while (n > 0) {
		n = n & (n - 1);
		++n_ones;
	}
	return n_ones;
}

int countOnes3(int n) {
	int n_ones = 0;
	int ones[] = { 0, 1, 1, 2 };
	while(n > 0) {
		n_ones += ones[n & 3];
		n = n >> 2;
	}
	return n_ones;
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	BitwiseUtils::showBits(n);
	cout << countOnes1(n) << endl;
	cout << countOnes2(n) << endl;
	cout << countOnes3(n) << endl;
}

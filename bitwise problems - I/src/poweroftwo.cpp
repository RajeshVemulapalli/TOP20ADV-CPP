#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

bool powerOfTwo1(int n) {
	int size = sizeof(int) * 8;
	unsigned mask = 1 << (size - 1);
	int n_ones = 0;
	for (int i = 1; i <= size; ++i) {
		if ((n & mask) != 0)
			++n_ones;
		mask = mask >> 1;
	}
	if (n_ones == 1)
		return true;
	return false;
}

bool powerOfTwo2(int n) {
	if (n == 0)
		return false;
	return (n & (n - 1)) == 0;
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	cout << powerOfTwo1(n) << endl;
	cout << powerOfTwo2(n) << endl;
}

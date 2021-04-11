#include <cstdlib>
#include <ctime>
#include <iostream>
#include "bitwiseutils.cpp"
using namespace std;

int highest11(int n) {
	return (n + 7) & ~7;
}
int highest12(int n) {
	return (n + 7) & -8;
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	cout << n << endl;
	BitwiseUtils::showBits(n);
	cout << highest11(n) << endl;
	cout << highest12(n) << endl;
}

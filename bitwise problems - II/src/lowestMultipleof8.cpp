#include <cstdlib>
#include <ctime>
#include <iostream>
#include "bitwiseutils.cpp"
using namespace std;

int lowest11(int n) {
	return n & ~7;
}
int lowest12(int n) {
	return n & -8;
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	cout << n << endl;
	BitwiseUtils::showBits(n);
	cout << lowest11(n) << endl;
	cout << lowest12(n) << endl;
}

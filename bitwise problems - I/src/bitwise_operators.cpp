#include <cstdlib>
#include <ctime>
#include <iostream>
#include "bitwiseutils.cpp"
using namespace std;

int main(int argc, char*argv[]) {
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	BitwiseUtils::showBits(n);
	BitwiseUtils::showBits(m);
	BitwiseUtils::showBits(n & m);
	BitwiseUtils::showBits(n | m);
	BitwiseUtils::showBits(n ^ m);
	BitwiseUtils::showBits(n << 2);
	BitwiseUtils::showBits(n >> 2);
	BitwiseUtils::showBits(~n);
}

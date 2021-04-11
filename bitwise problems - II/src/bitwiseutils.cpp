#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class BitwiseUtils {
public:
	static void showBits(int n) {
		int size = sizeof(int) * 8;
		unsigned mask = 1 << (size - 1);
		for (int i = 1; i <= size; ++i) {
			if ((n & mask) != 0)
				cout << 1;
			else
				cout << 0;
			mask = mask >> 1;
		}
		cout << endl;
	}
};
/*int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	BitwiseUtils::showBits(n);
	BitwiseUtils::showBits(-n);
}*/

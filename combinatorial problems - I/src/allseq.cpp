#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void auxAllSeq(int n, string in, string out) {
	if (n == 0) {
		cout << out << endl;
		return;
	}
	for (int i = 0; i < in.length(); ++i) {
		auxAllSeq(n - 1, in, out + in.at(i));
	}

}
//TC:Theta(n^n)   SC:Theta(n)
void allSeq(string in) {
	auxAllSeq(in.length(), in, "");
}

int main(int argc, char *argv[]) {
	allSeq(argv[1]);
}

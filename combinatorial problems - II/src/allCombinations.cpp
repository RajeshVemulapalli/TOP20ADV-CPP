#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void auxCombinations1(string in, string out) {
	if (in.length() == 0) {
		cout << out << endl;
		return;
	}
	cout << out << endl;
	for (int i = 0; i < in.length(); ++i) {
		auxCombinations1(in.substr(i + 1), out + in.at(i));
	}
}
//TC:Theta(2^n)   SC:Theta(n)
void combinations1(string in) {
	auxCombinations1(in, "");
}
//----------------------------------------------------------
void auxCombinations2(string in, string out) {
	if (in.length() == 0) {
		cout << out << endl;
		return;
	}
	auxCombinations2(in.substr(1), out);
	auxCombinations2(in.substr(1), out + in.at(0));
}
//TC:Theta(2^n+1)   SC:Theta(n)
void combinations2(string in) {
	auxCombinations2(in, "");
}
//----------------------------------------------------------
//TC:Theta(n*2^n)   SC:O(1)
void combinations3(string in) {
	int n = in.length();
	for (int i = 0; i < 1 << n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i & (1 << j)) != 0)
				cout << in.at(j);
		}
		cout << endl;
	}
}
//----------------------------------------------------------
int main(int argc, char *argv[]) {
	combinations3(argv[1]);
}

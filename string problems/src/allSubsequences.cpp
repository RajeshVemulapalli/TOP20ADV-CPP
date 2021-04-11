#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void auxSubsequences1(string in, string out) {
	if (in.length() == 0) {
		cout << out << endl;
		return;
	}
	cout << out << endl;
	for (int i = 0; i < in.length(); ++i) {
		auxSubsequences1(in.substr(i + 1), out + in.at(i));
	}
}
//TC:Theta(2^n)   SC:Theta(n)
void subsequences1(string in) {
	auxSubsequences1(in, "");
}
//----------------------------------------------------------
void auxSubsequences2(string in, string out) {
	if (in.length() == 0) {
		cout << out << endl;
		return;
	}
	auxSubsequences2(in.substr(1), out);
	auxSubsequences2(in.substr(1), out + in.at(0));
}
//TC:Theta(2^n+1)   SC:Theta(n)
void subsequences2(string in) {
	auxSubsequences2(in, "");
}
//----------------------------------------------------------
//TC:Theta(n*2^n)   SC:O(1)
void subsequences3(string in) {
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
	subsequences3(argv[1]);
}

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

bool isValid1(string out) {
	for (int i = 1; i < out.length(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (out.at(i) == out.at(j))
				return false;
		}
	}
	return true;
}
void auxPermutations1(int n, string in, string out) {
	if (n == 0) {
		if (isValid1(out))
			cout << out << endl;
		return;
	}
	for (int i = 0; i < in.length(); ++i) {
		auxPermutations1(n - 1, in, out + in.at(i));
	}

}
//TC:Theta(n^n+1)   SC:Theta(n)
void permutations1(string in) {
	auxPermutations1(in.length(), in, "");
}
//-----------------------------------------------------
bool isValid2(char c, string out) {
	for (int i = 0; i < out.length(); ++i) {
		if (out.at(i) == c)
			return false;
	}
	return true;
}
void auxPermutations2(int n, string in, string out) {
	if (n == 0) {
		cout << out << endl;
		return;
	}
	for (int i = 0; i < in.length(); ++i) {
		if (isValid2(in.at(i), out))
			auxPermutations2(n - 1, in, out + in.at(i));
	}

}
//TC:Theta(n^n)   SC:Theta(n)
void permutations2(string in) {
	auxPermutations2(in.length(), in, "");
}
//-----------------------------------------------------
void auxPermutations3(string in, string out) {
	if (in.length() == 0) {
		cout << out << endl;
		return;
	}
	for (int i = 0; i < in.length(); ++i) {
		auxPermutations3(in.substr(0, i) + in.substr(i + 1), out + in.at(i));
	}

}
//TC:Theta(n^n)   SC:Theta(n)
void permutations3(string in) {
	auxPermutations3(in, "");
}
//-----------------------------------------------------

int main(int argc, char *argv[]) {
	permutations3(argv[1]);
}

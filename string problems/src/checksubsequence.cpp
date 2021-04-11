#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//TC:Theta(n)   SC:O(1)
bool isSubseq(string s1, string s2) {
	int i = 0;
	int j = 0;
	while (i < s1.length() && j < s2.length()) {
		if (s1[i] == s2[j])
			++i;
		++j;
	}
	if (i < s1.length())
		return false;
	return true;
}

int main(int argc, char *argv[]) {
	cout << argv[1] << endl;
	cout << argv[2] << endl;
	cout << isSubseq(argv[1], argv[2]);
}

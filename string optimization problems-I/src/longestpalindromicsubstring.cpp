#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

bool isPal(string s, int start, int end) {
	while (start < end) {
		if (s[start] == s[end]) {
			++start;
			--end;
		} else
			return false;
	}
	return true;
}
//TC:O(n^3)   SC:O(1)
string longPalSubstr1(string s) {
	int n = s.length();
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < n - i + 1; ++j) {
			if (isPal(s, j, j + i))
				return s.substr(j, i + 1);
		}
	}
	return {};
}
//-----------------------------------------------
//TC:Theta(n^2)   SC:Theta(n^2)
string longPalSubstr2(string s) {
	int n = s.length();
	vector<vector<bool>> mem(n);
	for (int i = 0; i < n; ++i)
		mem[i] = vector<bool>(n, true);

	int maxlen = 0;
	int pos = 0;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			if (s[i] == s[j]) {
				mem[i][j] = mem[i + 1][j - 1];
				if (mem[i][j] == true) {
					if (j - i + 1 > maxlen) {
						maxlen = j - i + 1;
						pos = i;
					}
				}
			} else
				mem[i][j] = false;
		}
	}
	return s.substr(pos, maxlen);
}
//-----------------------------------------------
int expandPal(string s, int left, int right) {
	int len = 0;
	while (left >= 0 && right < s.length()) {
		if (s[left] == s[right]) {
			--left;
			++right;
			len += 2;
		} else
			break;
	}
	return len;
}
//TC:Theta(n^2)   SC:O(1)
int longPalSubstr3(string s) {
	int maxlen = 0;
	for (int i = 0; i < s.length(); ++i) {
		int odd = expandPal(s, i - 1, i + 1) + 1;
		int even = expandPal(s, i, i + 1);
		maxlen = max(maxlen, max(odd, even));
	}
	return maxlen;
}
//------------------------------------------------
int main(int argc, char *argv[]) {
	cout << argv[1] << endl;
	cout << longPalSubstr1(argv[1]) << endl;
	cout << longPalSubstr2(argv[1]) << endl;
	cout << longPalSubstr3(argv[1]) << endl;
}

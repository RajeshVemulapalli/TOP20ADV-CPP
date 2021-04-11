#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include "radixtrie.cpp"
using namespace std;

int commonPrefixLen(string s1, string s2, int i, int j) {
	int clen = 0;
	while (i < s1.length() && j < s2.length()) {
		if (s1[i] == s2[j]) {
			++i;
			++j;
			++clen;
		} else
			break;
	}
	return clen;
}
//TC:O(n^3)  SC:O(1)
int longCommSubstr2(string s1, string s2) {
	int maxlen = 0;
	for (int i = 0; i < s1.length(); ++i) {
		for (int j = 0; j < s2.length(); ++j) {
			int clen = commonPrefixLen(s1, s2, i, j);
			maxlen = max(maxlen, clen);
		}
	}
	return maxlen;
}
//--------------------------------------------------
//TC:O(n^2 log n)  SC:Theta(n^2)
int longCommSubstr3(string s1, string s2) {
	vector<string> suffix_array;
	for (int i = 0; i < s1.length(); ++i)
		suffix_array.push_back(s1.substr(i) + "#");
	for (int i = 0; i < s2.length(); ++i)
		suffix_array.push_back(s2.substr(i) + "$");

	sort(suffix_array.begin(), suffix_array.end());
	for (auto s : suffix_array)
		cout << s << endl;

	int maxlen = 0;
	for (int i = 1; i < suffix_array.size(); ++i) {
		string first = suffix_array[i - 1];
		string second = suffix_array[i];
		if ((first[first.length() - 1] == '#'
				&& second[second.length() - 1] == '$')
				|| (first[first.length() - 1] == '$'
						&& second[second.length() - 1] == '#')) {
			int clen = commonPrefixLen(suffix_array[i - 1], suffix_array[i], 0,
					0);
			maxlen = max(maxlen, clen);
		}
	}
	return maxlen;

}
//-------------------------------------------------
//TC:O(n^2)  SC:Theta(n^2)
int longCommSubstr4(string s1, string s2) {
	RadixTrie trie;
	for (int i = 0; i < s1.length(); ++i)
		trie.add(s1.substr(i));
	int maxlen = 0;
	for (int i = 0; i < s2.length(); ++i) {
		int res = trie.lcp(s2.substr(i)).length();
		maxlen = max(maxlen, res);
	}
	return maxlen;
}
//-----------------------------------------------------
//TC:O(n^2)  SC:Theta(n^2)
int longCommSubstr5(string s1, string s2) {
	vector<vector<int>> mem(s1.length() + 1);
	for (int i = 0; i <= s1.length(); ++i)
		mem[i] = vector<int>(s2.length() + 1);

	for (int j = 0; j <= s2.length(); ++j)
		mem[s1.length()][j] = 0;
	for (int i = 0; i <= s1.length(); ++i)
		mem[i][s2.length()] = 0;

	int maxlen = 0;
	for (int i = s1.length() - 1; i >= 0; --i) {
		for (int j = 0; j < s2.length(); ++j) {
			if (s1[i] == s2[j]) {
				mem[i][j] = 1 + mem[i + 1][j + 1];
				maxlen = max(maxlen, mem[i][j]);
			} else
				mem[i][j] = 0;
		}
	}
	return maxlen;
}
//------------------------------------------------------
int main(int argc, char *argv[]) {
	cout << argv[1] << endl;
	cout << argv[2] << endl;
	cout << longCommSubstr5(argv[1], argv[2]);
}

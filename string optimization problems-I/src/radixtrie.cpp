#include <cstdlib>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class RadixNode {
public:
	bool isword;
	unordered_map<char,RadixNode *> children;
	vector<string> words;
	RadixNode() {
		isword = false;
	}
};
class RadixTrie {
	RadixNode *root;

	RadixNode* findLastNode(string word) {
		RadixNode *current = root;
		for (int i = 0; i < word.length(); ++i) {
			int ind = word[i];
			if (current->children[ind] == NULL)
				return NULL;
			current = current->children[ind];
		}
		return current;
	}
public:
	RadixTrie() {
		root = new RadixNode();
	}
	void add(string word) {
		RadixNode *current = root;
		for (int i = 0; i < word.length(); ++i) {
			int ind = word[i];
			if (current->children[ind] == NULL)
				current->children[ind] = new RadixNode();
			current->words.push_back(word);
			current = current->children[ind];
		}
		current->isword = true;
		current->words.push_back(word);
	}
	bool contains(string word) {
		RadixNode *res = findLastNode(word);
		if (res == NULL)
			return false;
		return res->isword;
	}

	vector<string> startswith(string prefix) {
		RadixNode *res = findLastNode(prefix);
		if (res == NULL)
			return {};
		return res->words;

	}
	string lcp(string word) {
		RadixNode *current = root;
		int i;
		for (i = 0; i < word.length(); ++i) {
			int ind = word[i];
			if (current->children[ind] == NULL)
				break;
			current = current->children[ind];
		}
		return word.substr(0, i);
	}

};

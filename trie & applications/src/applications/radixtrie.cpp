#include <cstdlib>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class RadixNode {
public:
	bool isword;
	unordered_map<char, RadixNode*> children;
	unordered_set<string> words;
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
	void add(string word, string val) {
		RadixNode *current = root;
		for (int i = 0; i < word.length(); ++i) {
			int ind = word[i];
			if (current->children[ind] == NULL)
				current->children[ind] = new RadixNode();
			current->words.insert(val);
			current = current->children[ind];
		}
		current->isword = true;
		current->words.insert(val);
	}
	bool contains(string word) {
		RadixNode *res = findLastNode(word);
		if (res == NULL)
			return false;
		return res->isword;
	}

	vector<string> startswith(string prefix) {
		RadixNode *node = findLastNode(prefix);
		if (node == NULL)
			return {};

		vector<string> res;
		for (auto w : node->words)
			res.push_back(w);
		return res;
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


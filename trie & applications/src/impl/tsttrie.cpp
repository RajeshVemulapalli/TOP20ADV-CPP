#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

class TSTNode {
public:
	bool isword;
	TSTNode *left, *middle, *right;
	vector<string> words;
	char data;
	TSTNode() {
		isword = false;
		left = middle = right = NULL;
		this->data = ' ';
	}
	TSTNode(char data) {
		isword = false;
		left = middle = right = NULL;
		this->data = data;
	}
};
class TSTTrie {
	TSTNode *root;

	TSTNode* findLastNode(string word) {
		TSTNode *current = root->middle;
		for (int i = 0; i < word.length();) {
			if (current == NULL)
				return NULL;
			if (word[i] == current->data) {
				if (i < word.length() - 1)
					current = current->middle;
				++i;
			} else if (word[i] < current->data) {
				current = current->left;
			} else {
				current = current->right;
			}
		}
		return current;
	}
	TSTNode* auxAdd(int i, string word, TSTNode *current) {
		if (current == NULL) {
			current = new TSTNode(word[i]);
		}
		if (word[i] == current->data) {
			if (i < word.length() - 1)
				current->middle = auxAdd(i + 1, word, current->middle);
			if (i == word.length() - 1)
				current->isword = true;
			current->words.push_back(word);
		} else if (word[i] < current->data) {
			current->left = auxAdd(i, word, current->left);
		} else {
			current->right = auxAdd(i, word, current->right);
		}
		return current;
	}
public:
	TSTTrie() {
		root = new TSTNode();
	}

	void add(string word) {
		root->words.push_back(word);
		TSTNode *res = auxAdd(0, word, root->middle);
		if (root->middle == NULL)
			root->middle = res;
	}
	bool contains(string word) {
		TSTNode *res = findLastNode(word);
		if (res == NULL)
			return false;
		return res->isword;
	}

	vector<string> startswith(string prefix) {
		if(prefix.length() == 0)
			return root->words;
		TSTNode *res = findLastNode(prefix);
		if (res == NULL)
			return {};
		return res->words;

	}
	string lcp(string word) {
		TSTNode *current = root->middle;
		int i;
		for (i = 0; i < word.length();) {
			if (current == NULL)
				break;
			if (word[i] == current->data) {
				current = current->middle;
				++i;
			} else if (word[i] < current->data) {
				current = current->left;
			} else {
				current = current->right;
			}
		}
		return word.substr(0, i);
	}

	void auxDisplay(TSTNode *root, int nspaces, string annotation) {
		if (root == NULL)
			return;
		for (int i = 0; i < nspaces; ++i)
			cout << " ";
		string tmp = "";
		for(auto word:root->words)
			tmp += word + ",";
		cout << root->data << "(" << annotation << ")" << tmp <<endl;
		auxDisplay(root->left, nspaces + 4, "L");
		auxDisplay(root->middle, nspaces + 4, "M");
		auxDisplay(root->right, nspaces + 4, "R");
	}

	void display() {
		auxDisplay(root->middle, 0, "root");
	}

};
int main(int argc, char *argv[]) {
	string words[8] = { "abc", "ade", "ab", "abcd", "bat", "cde", "cat", "xyz" };
	TSTTrie trie;
	for (string word : words)
		trie.add(word);
	trie.display();

	vector<string> res = trie.startswith("abc");
	for (string w : res)
		cout << w << ",";
	cout << endl;
	cout << trie.lcp("abdxy") << endl;
	cout << trie.lcp("xyz") << endl;

	cout << trie.contains("abdxy") << endl;
	cout << trie.contains("xyz") << endl;
	cout << trie.contains("ab");
}

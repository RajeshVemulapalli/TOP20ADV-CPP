/*
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iostream>
#include <queue>
#include "../binarytree_utils.h"
using namespace std;

class Codec3 {
	vector<string> split(string s, char sep) {
		vector<string> tokens;
		stringstream stream(s);
		string token;
		while (getline(stream, token, sep))
			tokens.push_back(token);
		return tokens;
	}
	void auxIn(TreeNode *root, string &res) {
		if (root == NULL)
			return;
		auxIn(root->left, res);
		res.append(to_string(root->data) + ",");
		auxIn(root->right, res);
	}
	void auxPre(TreeNode *root, string &res) {
		if (root == NULL)
			return;
		res.append(to_string(root->data) + ",");
		auxPre(root->left, res);
		auxPre(root->right, res);
	}
	int findPosition(vector<string> &in, string tmp) {
		int p = 0;
		for (auto e : in) {
			if (e == tmp)
				return p;
			++p;
		}
		return -1;
	}
	TreeNode* auxDeser(vector<string> &pre, vector<string> &in, int l, int r) {
		if (l > r)
			return NULL;
		string tmp = pre.front();
		pre.erase(pre.begin());
		int p = findPosition(in, tmp);
		TreeNode *root = new TreeNode(stoi(tmp));
		root->left = auxDeser(pre, in, l, p - 1);
		root->right = auxDeser(pre, in, p + 1, r);
		return root;
	}
public:
	//TC:Theta(n)   SC:Theta(n)
	string ser(TreeNode *root) {
		string res = "";
		auxIn(root, res);
		res.append("#");
		auxPre(root, res);
		return res;
	}

	//TC:Theta(n)   SC:Theta(n)
	TreeNode* deser(string s) {
		vector<string> tokens = split(s, '#');
		vector<string> in = split(tokens[0], ',');
		vector<string> pre = split(tokens[1], ',');

		return auxDeser(pre, in, 0, in.size() - 1);
	}
};

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	TreeNode *root = randomBinaryTree(n);
	display(root);
	Codec3 c;
	string res = c.ser(root);
	cout << res << endl;
	root = c.deser(res);
	display(root);

}
*/

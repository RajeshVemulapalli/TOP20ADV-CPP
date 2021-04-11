/*
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iostream>
#include "../binarytree_utils.h"
using namespace std;

class Codec1 {
	void auxSer(TreeNode *root, string &res) {
		if (root == NULL) {
			res.append("#,");
			return;
		}
		res.append(to_string(root->data) + ",");
		auxSer(root->left, res);
		auxSer(root->right, res);
	}
	TreeNode* auxDeser(vector<string> &data) {
		string tmp = data.front();
		data.erase(data.begin());
		if (tmp == "#")
			return NULL;
		TreeNode *root = new TreeNode(stoi(tmp));
		root->left = auxDeser(data);
		root->right = auxDeser(data);
		return root;
	}
	vector<string> split(string s) {
		vector<string> tokens;
		stringstream stream(s);
		string token;
		while (getline(stream, token, ','))
			tokens.push_back(token);
		return tokens;
	}
public:
	//TC:Theta(n)   SC:Theta(n)
	string ser(TreeNode *root) {
		string res = "";
		auxSer(root, res);
		return res;
	}

	//TC:Theta(n)   SC:Theta(n)
	TreeNode* deser(string s) {
		vector<string> tokens = split(s);
		return auxDeser(tokens);
	}
};

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	TreeNode *root = randomBinaryTree(n);
	display(root);
	Codec1 c;
	string res = c.ser(root);
	cout << res << endl;
	root = c.deser(res);
	display(root);

}
*/

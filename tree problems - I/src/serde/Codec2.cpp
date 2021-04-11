/*
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iostream>
#include <queue>
#include "../binarytree_utils.h"
using namespace std;

class Codec2 {
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
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			root = q.front();
			q.pop();
			if (root == NULL)
				res.append("#,");
			else {
				res.append(to_string(root->data) + ",");
				q.push(root->left);
				q.push(root->right);
			}
		}
		return res;
	}

	//TC:Theta(n)   SC:Theta(n)
	TreeNode* deser(string s) {
		vector<string> tokens = split(s);
		queue<TreeNode*> q;

		int i = 0;
		string tmp = tokens[i++];
		TreeNode *root = new TreeNode(stoi(tmp));
		q.push(root);
		TreeNode *current;

		while (!q.empty()) {
			string left_data = tokens[i++];
			string right_data = tokens[i++];
			current = q.front();
			q.pop();

			if (left_data == "#")
				current->left = NULL;
			else {
				current->left = new TreeNode(stoi(left_data));
				q.push(current->left);
			}

			if (right_data == "#")
				current->right = NULL;
			else {
				current->right = new TreeNode(stoi(right_data));
				q.push(current->right);
			}
		}
		return root;
	}
};

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	TreeNode *root = randomBinaryTree(n);
	display(root);
	Codec2 c;
	string res = c.ser(root);
	cout << res << endl;
	root = c.deser(res);
	display(root);

}
*/

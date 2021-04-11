#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include "../binarytree_utils.h"
using namespace std;

//TC:Theta(n)   SC:Theta(n)
void preOrderR(TreeNode *root) {
	if (root == NULL)
		return;
	cout << root->data << endl;
	preOrderR(root->left);
	preOrderR(root->right);
}

//TC:Theta(n)   SC:Theta(n)
void preOrderNR(TreeNode *root) {
	stack<TreeNode*> s;
	while (true) {
		while (root != NULL) {
			s.push(root);
			cout << root->data << endl;
			root = root->left;
		}
		if (s.empty())
			break;
		root = s.top()->right;
		s.pop();
	}
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	TreeNode *root = oneSidedBinaryTree(n);
	//display(root);
	//preOrderR(root);
	preOrderNR(root);
}

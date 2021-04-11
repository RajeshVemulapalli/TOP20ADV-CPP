#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include "../binarytree_utils.h"
using namespace std;

//TC:Theta(n)   SC:Theta(n)
void inOrderR(TreeNode *root) {
	if (root == NULL)
		return;
	inOrderR(root->left);
	cout << root->data << endl;
	inOrderR(root->right);
}

//TC:Theta(n)   SC:Theta(n)
void inOrderNR(TreeNode *root) {
	stack<TreeNode*> s;
	while (true) {
		while (root != NULL) {
			s.push(root);
			root = root->left;
		}
		if (s.empty())
			break;
		root = s.top();
		cout << root->data << endl;
		root = root->right;
		s.pop();
	}
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	TreeNode *root = oneSidedBinaryTree(n);
	//display(root);
	inOrderR(root);
	inOrderNR(root);
}

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "binarytree_utils.h"
using namespace std;

TreeNode* add(TreeNode *root, int x) {
	if (root == NULL)
		return new TreeNode(x);

	TreeNode *root_copy = root;
	while (true) {
		if (rand() % 2 == 0) {
			if (root->left == NULL) {
				root->left = new TreeNode(x);
				break;
			}
			root = root->left;
		} else {
			if (root->right == NULL) {
				root->right = new TreeNode(x);
				break;
			}
			root = root->right;
		}
	}
	return root_copy;
}

TreeNode* randomBinaryTree(int n) {
	TreeNode *root = NULL;
	srand(time(0));
	for (int i = 0; i < n; ++i) {
		root = add(root, i + 1);
	}
	return root;
}

TreeNode* oneSidedBinaryTree(int n) {
	srand(time(0));
	TreeNode *root = new TreeNode(rand() % (2 * n) + 1);
	TreeNode *current = root;
	for (int i = 1; i < n; ++i) {
		current->right = new TreeNode(rand() % (2 * n) + 1);
		current = current->right;
	}
	return root;
}
void auxDisplay(TreeNode *root, int nspaces, string annotation) {
	if (root == NULL)
		return;
	for (int i = 0; i < nspaces; ++i)
		cout << " ";
	cout << root->data << "(" << annotation << ")" << endl;
	auxDisplay(root->left, nspaces + 4, "L");
	auxDisplay(root->right, nspaces + 4, "R");
}

void display(TreeNode *root) {
	auxDisplay(root, 0, "root");
}

//int main(int argc, char *argv[]) {
//	int n = atoi(argv[1]);
//	TreeNode* root = randomBinaryTree(n);
//	display(root);
//}

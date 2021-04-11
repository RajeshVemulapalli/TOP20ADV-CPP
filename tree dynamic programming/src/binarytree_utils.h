#ifndef BINARYTREE_UTILS_H_
#define BINARYTREE_UTILS_H_

#include <iostream>

class TreeNode {
public:
	TreeNode* left;
	TreeNode* right;
	int data;
	TreeNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* randomBinaryTree(int n);
TreeNode* oneSidedBinaryTree(int n);
void display(TreeNode* root);

#endif /* BINARYTREE_UTILS_H_ */

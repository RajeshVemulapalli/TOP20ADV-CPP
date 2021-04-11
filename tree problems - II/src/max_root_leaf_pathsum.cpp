#include <cstdlib>
#include <ctime>
#include <iostream>
#include "binarytree_utils.h"
using namespace std;

void auxMaxSum1(TreeNode *root, int csum, int &gmax) {
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL) {
		gmax = max(gmax, csum + root->data);
		return;
	}
	auxMaxSum1(root->left, csum + root->data, gmax);
	auxMaxSum1(root->right, csum + root->data, gmax);
}
//TC:Theta(n)   SC:Theta(n)
int maxSum1(TreeNode *root) {
	int gmax = 0;
	auxMaxSum1(root, 0, gmax);
	return gmax;
}

//TC:Theta(n)   SC:Theta(n)
int maxSum2(TreeNode *root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	int left = maxSum2(root->left);
	int right = maxSum2(root->right);
	return max(left, right) + root->data;
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	TreeNode *root = randomBinaryTree(n);
	display(root);
	cout << maxSum1(root) << endl;
	cout << maxSum2(root) << endl;
}

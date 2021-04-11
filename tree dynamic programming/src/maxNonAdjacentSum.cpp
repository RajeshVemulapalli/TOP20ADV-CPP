#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <utility>
#include "binarytree_utils.h"
using namespace std;

//TC:Theta(n^2)   SC:Theta(n)
int maxNonAdjSum1(TreeNode *root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return max(0, root->data);
	int incl_sum = root->data;
	if (root->left != NULL) {
		if (root->left->left != NULL)
			incl_sum += maxNonAdjSum1(root->left->left);
		if (root->left->right != NULL)
			incl_sum += maxNonAdjSum1(root->left->right);
	}
	if (root->right != NULL) {
		if (root->right->left != NULL)
			incl_sum += maxNonAdjSum1(root->right->left);
		if (root->right->right != NULL)
			incl_sum += maxNonAdjSum1(root->right->right);
	}

	int excl_sum = 0;
	if (root->left != NULL)
		excl_sum += maxNonAdjSum1(root->left);
	if (root->right != NULL)
		excl_sum += maxNonAdjSum1(root->right);
	return max(incl_sum, excl_sum);

}
//----------------------------------------------------
int auxNonAdjSum2(TreeNode *root, unordered_map<TreeNode*, int> &mem) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return max(0, root->data);
	if (mem.find(root) != mem.end())
		return mem[root];
	int incl_sum = root->data;
	if (root->left != NULL) {
		if (root->left->left != NULL)
			incl_sum += auxNonAdjSum2(root->left->left, mem);
		if (root->left->right != NULL)
			incl_sum += auxNonAdjSum2(root->left->right, mem);
	}
	if (root->right != NULL) {
		if (root->right->left != NULL)
			incl_sum += auxNonAdjSum2(root->right->left, mem);
		if (root->right->right != NULL)
			incl_sum += auxNonAdjSum2(root->right->right, mem);
	}

	int excl_sum = 0;
	if (root->left != NULL)
		excl_sum += auxNonAdjSum2(root->left, mem);
	if (root->right != NULL)
		excl_sum += auxNonAdjSum2(root->right, mem);
	int res = max(incl_sum, excl_sum);
	mem[root] = res;
	return res;

}
//TC:Theta(n)   SC:Theta(n)
int maxNonAdjSum2(TreeNode *root) {
	unordered_map<TreeNode*, int> mem;
	auxNonAdjSum2(root, mem);
	return mem[root];
}
//-----------------------------------------------------------------
pair<int, int> auxNonAdjSum3(TreeNode *root) {
	if (root == NULL)
		return {0, 0};
	if (root->left == NULL && root->right == NULL)
		return {max(0, root->data), 0};
	pair<int, int> left = auxNonAdjSum3(root->left);
	pair<int, int> right = auxNonAdjSum3(root->right);

	int incl_sum = root->data + left.second + right.second;
	int excl_sum = left.first + right.first;
	return {max(incl_sum, excl_sum), left.first + right.first};
}
//TC:Theta(n)   SC:Theta(n)
int maxNonAdjSum3(TreeNode *root) {
	pair<int, int> res = auxNonAdjSum3(root);
	return res.first;
}
//--------------------------------------------------------------
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	TreeNode *root = randomBinaryTree(n);
	//display(root);
	//cout << maxNonAdjSum1(root)<< endl;
	cout << maxNonAdjSum2(root) << endl;
	cout << maxNonAdjSum3(root) << endl;
}

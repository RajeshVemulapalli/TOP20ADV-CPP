#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class TreeNode {
public:
	TreeNode *left;
	TreeNode *right;
	char character;
	int freq;
	TreeNode(char character, int freq, TreeNode *left, TreeNode *right) {
		this->character = character;
		this->freq = freq;
		this->left = left;
		this->right = right;
	}

};
struct Comparator {
	bool operator()(TreeNode *e1, TreeNode *e2) {
		return e1->freq > e2->freq;
	}
};
class EncoderDecoder {
	TreeNode *root;

	void auxDisplay(TreeNode *root, int nspaces, string annotation) {
		if (root == NULL)
			return;
		for (int i = 0; i < nspaces; ++i)
			cout << " ";
		cout << root->character << "(" << root->freq << "," << annotation << ")"
				<< endl;
		auxDisplay(root->left, nspaces + 4, "L");
		auxDisplay(root->right, nspaces + 4, "R");
	}

	void display(TreeNode *root) {
		auxDisplay(root, 0, "root");
	}
	void auxEncode(TreeNode *root, string code,
			unordered_map<char, string> &enc) {
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL) {
			enc[root->character] = code;
			return;
		}
		auxEncode(root->left, code + "0", enc);
		auxEncode(root->right, code + "1", enc);
	}
	bool isLeaf(TreeNode *root) {
		return root->left == NULL && root->right == NULL;
	}
public:
	void buildTree(string in) {
		//get the frequencies of characters
		unordered_map<char, int> freq;
		for (int i = 0; i < in.size(); ++i) {
			if (freq.find(in[i]) == freq.end())
				freq[in[i]] = 1;
			else
				freq[in[i]] += 1;
		}
		for (auto e : freq)
			cout << e.first << "," << e.second << " ";
		cout << endl;

		//build huffman tree
		priority_queue<TreeNode*, vector<TreeNode*>, Comparator> pq;
		for (auto e : freq)
			pq.push(new TreeNode(e.first, e.second, NULL, NULL));

		while (pq.size() > 1) {
			TreeNode *smallest1 = pq.top();
			pq.pop();
			TreeNode *smallest2 = pq.top();
			pq.pop();
			pq.push(
					new TreeNode('#', smallest1->freq + smallest2->freq,
							smallest1, smallest2));
		}
		root = pq.top();
		pq.pop();
		display(root);
	}

	string encode(string in) {
		//get the encodings
		unordered_map<char, string> enc;
		auxEncode(root, "", enc);
		for (auto e : enc)
			cout << e.first << "," << e.second << " ";
		cout << endl;

		//return the encoded string
		string res = "";
		for (int i = 0; i < in.size(); ++i)
			res += enc[in[i]];
		return res;
	}

	string decode(string in) {
		string res = "";
		for (int i = 0; i < in.size();) {
			TreeNode *current = root;
			while (!isLeaf(current)) {
				if (in[i++] == '0')
					current = current->left;
				else
					current = current->right;
			}
			res += current->character;
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	string in = "";
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		in += (char) ('a' + rand() % 26);
	}
	cout << in << endl;
	EncoderDecoder enc_dec;
	enc_dec.buildTree(in);
	string enc = enc_dec.encode(in);
	cout << enc << endl;
	cout << enc_dec.decode(enc) << endl;
}

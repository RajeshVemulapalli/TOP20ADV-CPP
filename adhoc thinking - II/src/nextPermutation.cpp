/*
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &in, int i, int j) {
	int tmp = in[i];
	in[i] = in[j];
	in[j] = tmp;
}

void reverse(vector<int> &in, int i, int j) {
	while (i < j) {
		swap(in, i, j);
		++i;
		--j;
	}
}
//4 5 3 2 1
//5 4 3 2 1
//TC:Theta(n)   SC:O(1)
void nextPerm(vector<int> &in) {
	int i;
	for (i = in.size() - 2; i >= 0; --i) {
		if (in[i] < in[i + 1])
			break;
	}
	if (i < 0)
		return;
	int min_ind;
	for (int j = i + 1; j < in.size(); ++j) {
		if (in[j] > in[i])
			min_ind = j;
		else
			break;
	}
	swap(in, i, min_ind);
	reverse(in, i + 1, in.size() - 1);
}
void display(vector<int> &in) {
	for (auto e : in)
		cout << e << " ";
	cout << endl;
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	srand(time(NULL));
	vector<int> in(n);
	for (int i = 0; i < n; ++i)
		in[i] = rand() % n + 1;
	display(in);
	nextPerm(in);
	display(in);
	nextPerm(in);
	display(in);
	nextPerm(in);
	display(in);
}
*/

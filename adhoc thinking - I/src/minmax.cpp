#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

//~2n comparisons
void minMax1(vector<int> &in) {
	int min, max;
	if (in[0] < in[1]) {
		min = in[0];
		max = in[1];
	} else {
		min = in[1];
		max = in[0];
	}
	for (int i = 2; i < in.size(); ++i) {
		if (in[i] < min)
			min = in[i];
		else if (in[i] > max)
			max = in[i];
	}
	cout << min << "," << max << endl;
}

//~1.5n comparisons
void minMax2(vector<int> &in) {
	int min, max;
	if (in[0] < in[1]) {
		min = in[0];
		max = in[1];
	} else {
		min = in[1];
		max = in[0];
	}
	int pmin, pmax, i;
	for (i = 2; i < in.size() - 1; i += 2) {
		if (in[i] < in[i + 1]) {
			pmin = in[i];
			pmax = in[i + 1];
		} else {
			pmin = in[i + 1];
			pmax = in[i];
		}
		if (pmin < min)
			min = pmin;
		if (pmax > max)
			max = pmax;
	}
	if (i < in.size()) {
		if (in[i] < min)
			min = in[i];
		else if (in[i] > max)
			max = in[i];
	}

	cout << min << "," << max << endl;
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<int> in(n);
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		in[i] = rand() % (2 * n) + 1;
	}
	for (auto e : in)
		cout << e << " ";
	cout << endl;
	minMax1(in);
	minMax2(in);
}

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void display(vector<int> &in) {
	for (auto e : in)
		cout << e << " ";
	cout << endl;
}
void update(vector<int> &tt, vector<int> &in, int i, int j) {
	if (in[tt[i]] < in[tt[j]])
		tt[(i - 1) / 2] = tt[i];
	else
		tt[(i - 1) / 2] = tt[j];
}
//2 4 5 3
//0 0 0 0 1 2 3
int secondSmallest(vector<int> &in) {
	int n = in.size();
	vector<int> tt(2 * n - 1);
	int ind = tt.size() - 1;
	for (int i = n - 1; i >= 0; --i)
		tt[ind--] = i;
	display(tt);

	//build tournament tree
	ind = tt.size() - 1;
	while (ind > 0) {
		if (in[tt[ind]] < in[tt[ind - 1]])
			tt[(ind - 1) / 2] = tt[ind];
		else
			tt[(ind - 1) / 2] = tt[ind - 1];
		ind -= 2;
	}
	display(tt);
	cout << in[tt[0]] << endl;

	//find second smallest element
	in[tt[0]] = INT_MAX;
	ind = tt[0] + n - 1;
	while (ind > 0) {
		if (ind % 2 == 0)
			update(tt, in, ind, ind - 1);
		else
			update(tt, in, ind, ind + 1);
		ind = (ind - 1) / 2;
	}
	display(tt);
	return in[tt[0]];
}

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<int> in(n);
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		in[i] = rand() % (2 * n) + 1;
	}
	display(in);
	cout << secondSmallest(in);
}

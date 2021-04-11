#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//TC:Theta(n log n)  SC:O(1)
int minWaitingTime(vector<int> &in) {
	sort(in.begin(), in.end());
	int total_wt = 0;
	int job_wt = 0;
	for (int i = 1; i < in.size(); ++i) {
		job_wt += in[i - 1];
		total_wt += job_wt;
	}
	return total_wt;
}

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<int> in(n);
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
		in[i] = rand() % n + 1;
	for (auto e : in)
		cout << e << " ";
	cout << endl;
	cout << minWaitingTime(in) << endl;
}

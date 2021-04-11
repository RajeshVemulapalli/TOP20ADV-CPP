#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxMatchings(vector<int> &tea_cups, vector<int> &saucers) {
	sort(tea_cups.begin(), tea_cups.end());
	sort(saucers.begin(), saucers.end());
	int i = 0, j = 0, nmatches = 0;
	while (i < tea_cups.size() && j < saucers.size()) {
		if (tea_cups[i] <= saucers[j]) {
			nmatches++;
			i++;
			j++;
		} else
			++j;
	}
	return nmatches;
}

int main(int argc, char *argv[]) {
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);

	vector<int> tea_cups(m);
	vector<int> saucers(n);

	srand(time(NULL));
	for (int i = 0; i < m; ++i)
		tea_cups[i] = rand() % 10 + 1;
	for (int i = 0; i < n; ++i)
		saucers[i] = rand() % 10 + 1;

	for (auto e : tea_cups)
		cout << e << " ";
	cout << endl;
	for (auto e : saucers)
		cout << e << " ";
	cout << endl;

	cout << maxMatchings(tea_cups, saucers);
}

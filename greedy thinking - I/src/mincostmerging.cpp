#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Comparator {
	bool operator()(int e1, int e2) {
		return e1 > e2;
	}
};
//TC:Theta(n log n)   SC:Theta(n)
int minCostMerge(vector<int> &in) {
	priority_queue<int, vector<int>, Comparator> pq;
	for (auto e : in)
		pq.push(e);

	int tot = 0;
	while (pq.size() > 1) {
		int smallest1 = pq.top();
		pq.pop();
		int smallest2 = pq.top();
		pq.pop();
		pq.push(smallest1 + smallest2);
		tot += (smallest1 + smallest2);
	}
	return tot;
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<int> in(n);
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
		in[i] = rand() % 10 + 1;
	for (auto e : in)
		cout << e << " ";
	cout << endl;
	cout << minCostMerge(in) << endl;
}

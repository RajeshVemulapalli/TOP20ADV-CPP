#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

//TC:theta(n)   SC:theta(n)
int minCandies(vector<int> &in) {
	vector<int> candies(in.size());
	//left to right scan
	candies[0] = 1;
	for (int i = 1; i < in.size(); ++i) {
		if (in[i] > in[i - 1])
			candies[i] = candies[i - 1] + 1;
		else
			candies[i] = 1;
	}
	for (auto e : candies)
		cout << e << " ";
	cout << endl;
	int total = candies[in.size() - 1];
	//right to left scan
	for (int i = in.size() - 2; i >= 0; --i) {
		if (in[i] > in[i + 1] && candies[i] <= candies[i + 1])
			candies[i] = candies[i + 1] + 1;
		total += candies[i];
	}
	for (auto e : candies)
		cout << e << " ";
	cout << endl;
	return total;
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
	cout << minCandies(in) << endl;
}

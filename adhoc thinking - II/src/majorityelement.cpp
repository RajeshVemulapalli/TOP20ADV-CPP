#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//TC:Theta(n)   SC:O(1)
int majority(vector<int> &in) {
	int maj = INT_MAX;
	int count = 1;
	for (int i = 0; i < in.size(); ++i) {
		if (in[i] == maj)
			++count;
		else {
			--count;
			if (count == 0) {
				maj = in[i];
				count = 1;
			}
		}
	}
	return maj;
}
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<int> in(n);
	srand(time(NULL));

	int maj = rand() % n + 1;
	for (int i = 0; i < n / 2 + 1; ++i)
		in[i] = maj;
	for (int i = n / 2 + 1; i < n; ++i)
		in[i] = rand() % n + 1;

	for (auto e : in)
		cout << e << " ";
	cout << endl;
	cout << majority(in) << endl;

}

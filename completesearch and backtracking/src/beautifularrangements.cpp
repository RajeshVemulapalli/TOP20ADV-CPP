#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &out) {
	for (auto it = out.begin(); it != out.end(); ++it)
		cout << *it;
	cout << endl;
}
bool isValid1(vector<int> &out) {
	for (int i = 0; i < out.size(); ++i) {
		if (i == 0 || i % 2 == 0) {
			if (out[i] % 2 != 0)
				return false;
		} else {
			if (out[i] % 3 != 0)
				return false;
		}
	}
	return true;
}
void auxArrangements1(int i, vector<int> &out) {
	if (i == out.size()) {
		if (isValid1(out))
			display(out);
		return;
	}
	for (int d = 1; d <= 9; ++d) {
		out[i] = d;
		auxArrangements1(i + 1, out);
	}
}
//TC:Theta(9^n)   SC:Theta(n)
void arrangements1(int n) {
	vector<int> out(n);
	auxArrangements1(0, out);
}
//-------------------------------------------------
bool isValid2(int i, int d) {
	if (i == 0 || i % 2 == 0) {
		if (d % 2 != 0)
			return false;
	} else {
		if (d % 3 != 0)
			return false;
	}
	return true;
}
void auxArrangements2(int i, vector<int> &out) {
	if (i == out.size()) {
		display(out);
		return;
	}
	for (int d = 1; d <= 9; ++d) {
		if (isValid2(i, d)) {
			out[i] = d;
			auxArrangements2(i + 1, out);
		}
	}
}
//TC:Theta(4^n)   SC:Theta(n)
void arrangements2(int n) {
	vector<int> out(n);
	auxArrangements2(0, out);
}
//-------------------------------------------------
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	arrangements2(n);
}

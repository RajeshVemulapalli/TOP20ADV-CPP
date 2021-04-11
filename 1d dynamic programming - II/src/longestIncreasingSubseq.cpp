#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

//TC:O(n*2^n)   SC:O(1)
int lis1(vector<int> &in) {
	return 0;
}
//---------------------------------------------------------------
void auxLis2(int i, int plen, int &gmax, vector<int> &in) {
	if (i == in.size() - 1) {
		gmax = max(gmax, plen + 1);
		return;
	}
	for (int j = i + 1; j < in.size(); ++j) {
		if (in[j] > in[i])
			auxLis2(j, plen + 1, gmax, in);
	}
	gmax = max(gmax, plen + 1);
}
//TC:O(n^ n+1)   SC:Theta(n)
int lis2(vector<int> &in) {
	int gmax = 1;
	for (int i = 0; i < in.size(); ++i)
		auxLis2(i, 0, gmax, in);
	return gmax;
}
//--------------------------------------------------------------------
int auxLis3(int i, vector<int> &in) {
/*	if (i == in.size() - 1) {
		gmax = max(gmax, plen + 1);
		return;
	}*/
	int mx = 1;
	for (int j = i + 1; j < in.size(); ++j) {
		if (in[j] > in[i]) {
			int res = auxLis3(j, in) + 1;
			mx = max(mx, res);
		}
	}
	return mx;
}
//TC:O(n^ n+1)   SC:Theta(n)
int lis3(vector<int> &in) {
	int gmax = 0;
	for (int i = 0; i < in.size(); ++i)
		gmax = max(gmax, auxLis3(i, in));
	return gmax;
}
//----------------------------------------------------------------------------
int auxLis4(int i, vector<int> &mem, vector<int> &in) {
/*	if (i == in.size() - 1) {
		gmax = max(gmax, plen + 1);
		return;
	}*/
	if (mem[i] != 0)
		return mem[i];
	int mx = 1;
	for (int j = i + 1; j < in.size(); ++j) {
		if (in[j] > in[i]) {
			int res = auxLis4(j, mem, in) + 1;
			mx = max(mx, res);
		}
	}
	mem[i] = mx;
	return mem[i];
}
//TC:O(n^2)   SC:Theta(n)
int lis4(vector<int> &in) {
	int gmax = 0;
	vector<int> mem(in.size());
	for (int i = 0; i < in.size(); ++i)
		gmax = max(gmax, auxLis4(i, mem, in));
	return gmax;
}
//-------------------------------------------------------------------------------------

void traceOptimalRoute(int i, vector<int> &mem, vector<int> &in) {
	while (i < mem.size()) {
		cout << in[i] << " ";
		bool end = true;
		for (int j = i + 1; j < in.size(); ++j) {
			if (in[j] > in[i]) {
				end = false;
				if (mem[i] == mem[j] + 1) {
					i = j;
					break;
				}
			}
		}
		if (end)
			break;
	}
}
//TC:O(n^2)   SC:Theta(n)
int lis5(vector<int> &in) {
	int gmax = 0;
	vector<int> mem(in.size());
	mem[in.size() - 1] = 1;
	int mpos = 0;
	for (int i = in.size() - 2; i >= 0; --i) {
		int mx = 1;
		for (int j = i + 1; j < in.size(); ++j) {
			if (in[j] > in[i]) {
				int res = mem[j] + 1;
				mx = max(mx, res);
			}
		}
		mem[i] = mx;
		if (mem[i] > gmax) {
			gmax = mem[i];
			mpos = i;
		}
	}
	traceOptimalRoute(mpos, mem, in);
	cout << endl;
	return gmax;
}

//-------------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	vector<int> in(n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
		in[i] = rand() % n;
	//in[i] = i;
	for (auto it = in.begin(); it != in.end(); ++it)
		cout << *it << " ";
	cout << endl;
	//cout << lis2(in)<<endl;
	//cout << lis3(in)<<endl;
	//cout << lis4(in) << endl;
	cout << lis5(in) << endl;
}

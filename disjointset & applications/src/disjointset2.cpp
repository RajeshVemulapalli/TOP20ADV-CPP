#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

class UnionbySizePathCompressionDisjointSet {
private:
	vector<int> parent;
	vector<int> rank;
	int sz;
public:
	UnionbySizePathCompressionDisjointSet(int n):
			parent(n), rank(n) {
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
			rank[i] = 1;
		}
		sz = n;
	}

	//TC:O(1) am
	int find(int x) {
		if(parent[x] == x) return x;
		parent[x] = find(parent[x]);
		return parent[x];
	}

	//TC:O(1) am
	void union_by_size(int x, int y) {
		int idx = find(x);
		int idy = find(y);
		if (idx == idy)
			return;
		--sz;
		if (rank[idx] > rank[idy]) {
			parent[idy] = idx;
			rank[idx] += rank[idy];
		} else {
			parent[idx] = idy;
			rank[idy] += rank[idx];
		}
	}

	//TC:O(1)
	int size() {
		return sz;
	}

	void display() {
		for (auto e : parent)
			cout << e << " ";
		cout << endl;
		for (auto e : rank)
			cout << e << " ";
		cout << endl;
	}
};

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	srand(time(NULL));
	UnionbySizePathCompressionDisjointSet s1(n);
	s1.display();
	for (int i = 0; i < n / 2; ++i) {
		int x = rand() % n;
		int y = rand() % n;
		cout << x << " " << y << endl;
		s1.union_by_size(x, y);
		s1.display();
	}
	cout << s1.size() << endl;
	cout << s1.find(0) << endl;
	cout << s1.find(n - 1) << endl;
}

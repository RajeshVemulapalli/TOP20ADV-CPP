#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include "radixtrie.cpp"
using namespace std;

class TypeAheadSystem2 {
	RadixTrie index;
public:
	void build(vector<string> names) {
		for (string name : names) {
			for (int i = 0; i < name.length(); ++i) {
					string key = name.substr(i);
					//cout << key << endl;
					index.add(key, name);
			}
		}
	}

	void display() {
		vector<string> values = index.startswith("");
		for(auto v:values)
			cout << v << ",";
		cout << endl;
	}

	vector<string> query(string text) {
		return index.startswith(text);
	}
};
int main(int argc, char *argv[]) {
	vector<string> names = { "krishna", "jesus", "yoga", "lord", "karma yoga",
			"bhakti yoga" };
	TypeAheadSystem2 system;
	system.build(names);
	system.display();

	vector<string> res = system.query(argv[1]);
	for(auto v:res)
		cout << v << ",";
	cout << endl;
}

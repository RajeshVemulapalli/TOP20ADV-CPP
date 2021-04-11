#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class TypeAheadSystem1 {
	unordered_map<string, unordered_set<string>> index;
public:
	void build(vector<string> names) {
		for (string name : names) {
			for (int i = 0; i < name.length(); ++i) {
				for (int j = i + 1; j <= name.length(); ++j) {
					string key = name.substr(i, j - i);
					//cout << key << endl;
					if (index.find(key) == index.end()) {
						index[key] = unordered_set<string>();
					}
					index[key].insert(name);
				}
			}
		}
	}

	void display() {
		for (auto e : index) {
			cout << e.first << ":";
			for (auto v : e.second)
				cout << v << ",";
			cout << endl;
		}
	}

	vector<string> query(string text) {
		if (index.find(text) == index.end())
			return {};
		vector<string> res;
		for (auto e : index[text])
			res.push_back(e);
		return res;
	}
};
int main(int argc, char *argv[]) {
	vector<string> names = { "krishna", "jesus", "yoga", "lord", "karma yoga",
			"bhakti yoga" };
	TypeAheadSystem1 system;
	system.build(names);
	system.display();

	vector<string> res = system.query(argv[1]);
	for(auto v:res)
		cout << v << ",";
	cout << endl;
}

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Entry {
	int ts;
	string val;
public:
	Entry() {
		this->ts = -1;
		this->val = "";
	}

	Entry(int ts, string val) {
		this->ts = ts;
		this->val = val;
	}

	int getTs() const {
		return ts;
	}

	void setTs(int ts) {
		this->ts = ts;
	}

	const string& getVal() const {
		return val;
	}

	void setVal(const string &val) {
		this->val = val;
	}
};
class MiniCassandra {
	unordered_map<string, map<int, string>> store;
public:
	void put(string key, string val, int ts) {
		if (store.find(key) == store.end())
			store[key] = map<int, string>();
		store[key][ts] = val;
	}

	Entry get(string key, int ts) {
		if (store.find(key) == store.end())
			return {};
		auto it = store[key].lower_bound(ts);
		if (it == store[key].begin() && it->first != ts)
			return {};
		if (it->first != ts)
			--it;
		return Entry(it->first, it->second);

	}

	vector<Entry> query(string key, int ts_start, int ts_end) {
		if (store.find(key) == store.end())
			return {};
		vector<Entry> res;
		auto start = store[key].lower_bound(ts_start);
		auto end = store[key].upper_bound(ts_end);
		for (; start != end; ++start) {
			res.push_back(Entry(start->first, start->second));
		}
		return res;
	}

	void display() {
		for (auto it1 : store) {
			cout << it1.first << ":";
			for (auto it2 : it1.second)
				cout << it2.first << "," << it2.second << " ";
			cout << endl;
		}
	}
};

int main(int argc, char *argv[]) {
	MiniCassandra cassandra;
	for (int ts = 0; ts < 20; ++ts) {
		int rid = rand() % 5;
		cassandra.put("user" + to_string(rid), "message" + to_string(rid), ts);
	}
	cassandra.display();
	for(int i = 0; i < 5; ++i) {
		int rid = rand()%5;
		int rts = rand()%20;
		Entry res = cassandra.get("user"+to_string(rid), rts);
		cout << "user"+to_string(rid)+","+ to_string(rts) << endl;
		cout << res.getTs() <<"," << res.getVal() << endl;
	}

	for(int i = 0; i < 5; ++i) {
		int rid = rand()%5;
		vector<Entry> res = cassandra.query("user"+to_string(rid), 5, 10);
		cout << "user"+to_string(rid)+",(5,10)"<< endl;
		for(auto e:res)
			cout << e.getTs() <<"," << e.getVal() << endl;
	}
}

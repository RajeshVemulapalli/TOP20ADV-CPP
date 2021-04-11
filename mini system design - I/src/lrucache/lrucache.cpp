#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
using namespace std;

class DListNode {
public:
	string key;
	string val;
	DListNode *prev;
	DListNode *next;
	DListNode() {
		this->prev = this;
		this->next = this;
	}
	DListNode(string key, string val) {
		this->key = key;
		this->val = val;
		this->prev = this;
		this->next = this;
	}
};

class DoublyLinkedList {
	DListNode *head;
	int sz;
public:
	DoublyLinkedList() {
		head = new DListNode();
		sz = 0;
	}
	int size() {
		return sz;
	}
	DListNode* removeFirst() {
		DListNode *first = head->next;
		first->next->prev = head;
		head->next = first->next;
		--sz;
		return first;
	}
	DListNode* addLast(string key, string val) {
		DListNode *tmp = new DListNode(key, val);
		tmp->prev = head->prev;
		tmp->next = head;
		head->prev->next = tmp;
		head->prev = tmp;
		++sz;
		return tmp;
	}
	void removeAndAddLast(DListNode *tmp) {
		//unlink
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;

		//add at last position
		tmp->prev = head->prev;
		tmp->next = head;
		head->prev->next = tmp;
		head->prev = tmp;

	}
	void display() {
		for (DListNode *current = head->next; current != head;
				current = current->next)
			cout << "(" + current->key + "," + current->val + ")";
		cout << endl;
	}
};

class LRUCache {
	unordered_map<string, DListNode*> map;
	DoublyLinkedList list;
	int capacity;
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}
	//TC:O(1)
	void put(string key, string val) {
		if (map.find(key) != map.end()) {
			map.at(key)->val = val;
		} else {
			if (capacity == list.size()) {
				DListNode *lruNode = list.removeFirst();
				map.erase(lruNode->key);
			}
			DListNode *firstNode = list.addLast(key, val);
			map[key] = firstNode;
		}
	}
	//TC:O(1)
	string get(string key) {
		if (map.find(key) == map.end()) {
			return "not found";
		} else {
			DListNode *tmp = map.at(key);
			list.removeAndAddLast(tmp);
			return tmp->val;
		}

	}
	void display() {
		list.display();
	}
};

int main(int argc, char *argv[]) {
	LRUCache cache(3);
	for (int i = 0; i < 10; ++i) {
		cache.put("key" + to_string(i), "val" + to_string(i));
		cache.display();
	}
	for (int i = 0; i < 5; ++i) {
		string key = "key" + to_string(rand() % 10);
		cout << key << endl;
		cout << cache.get(key) << endl;
		cache.display();
	}
}

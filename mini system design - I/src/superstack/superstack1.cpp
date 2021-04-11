#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class superstack1 {
	stack<int> data_stack;
	stack<int> max_stack;
public:
	//TC:O(1)
	void push(int x) {
		data_stack.push(x);
		if (max_stack.empty() || x > max_stack.top())
			max_stack.push(x);
	}
	//TC:O(1)
	int pop() {
		if (data_stack.empty())
			return INT_MIN;
		int res = data_stack.top();
		data_stack.pop();
		if (res == max_stack.top())
			max_stack.pop();
		return res;
	}
	//TC:O(1)
	int max() {
		if (data_stack.empty())
			return INT_MIN;
		return max_stack.top();
	}
	void display() {
		stack<int> tmp_stack(data_stack);
		while (!tmp_stack.empty()) {
			cout << tmp_stack.top() << " ";
			tmp_stack.pop();
		}
		cout << endl;
	}
};
int main(int argc, char *argv[]) {
	//int n = atoi(argv[1]);
	superstack1 ss1;
	for (int i = 1; i <= 10; ++i) {
		ss1.push(i);
		ss1.display();
	}
	cout << ss1.max() << endl;
	for (int i = 1; i <= 5; ++i) {
		cout << ss1.pop() << endl;
		ss1.display();
	}
	cout << ss1.max() << endl;
}

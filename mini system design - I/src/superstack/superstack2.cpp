#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class superstack2 {
	stack<int> data_stack;
	int mx;
public:
	superstack2() {
		mx = INT_MAX;
	}
	//TC:O(1)
	void push(int x) {
		if (x > mx) {
			data_stack.push(2 * x - mx);
			mx = x;
		} else {
			if (data_stack.empty())
				mx = x;
			data_stack.push(x);
		}
	}
	//TC:O(1)
	int pop() {
		if (data_stack.empty())
			return INT_MIN;
		int res = data_stack.top();
		data_stack.pop();
		int tmp;
		if (res > mx) {
			tmp = mx;
			mx = 2 * mx - res;
		} else {
			tmp = res;
		}
		return tmp;
	}
	//TC:O(1)
	int max() {
		if (data_stack.empty())
			return INT_MIN;
		return mx;
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
	superstack2 ss1;
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

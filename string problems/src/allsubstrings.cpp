#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//TC:Theta(n^2)   SC:O(1)
void substr1(string s) {
	for(int i = 1; i <= s.length(); ++i) {
		for(int j = 0; j < s.length()-i+1; ++j) {
			cout << s.substr(j, i) << endl;
		}
	}
}

//TC:Theta(n^2)   SC:O(1)
void substr2(string s) {
	for(int i = 0; i < s.length(); ++i) {
		for(int j = i+1; j <= s.length(); ++j) {
			cout << s.substr(i, j-i) << endl;
		}
	}

}
int main(int argc, char*argv[]) {
	cout << argv[1] << endl;
	substr1(argv[1]);
	substr2(argv[1]);
}

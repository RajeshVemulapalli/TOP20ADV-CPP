#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//TODO: fill up the evaluation logic
int eval(string out) {
	return 0;
}
void auxEval1(string in, string out, int target) {
	if (in.length() == 0) {
		if (eval(out) == target)
			cout << out << endl;
		return;
	}
	auxEval1(in.substr(1), out + "+" + in.at(0), target);
	auxEval1(in.substr(1), out + "-" + in.at(0), target);
}
//TC:Theta(n*2^n-1)   SC:Theta(n)
void eval1(string in, int target) {
	auxEval1(in.substr(1), in.substr(0, 1), target);
}
//-------------------------------------------------------
void auxEval2(string in, string out, int target, int res) {
	if (in.length() == 0) {
		if (res == target)
			cout << out << endl;
		return;
	}
	auxEval2(in.substr(1), out + "+" + in.at(0), target, res+(in.at(0)-'0') );
	auxEval2(in.substr(1), out + "-" + in.at(0), target,  res-(in.at(0)-'0'));
}
//TC:Theta(2^n-1)   SC:Theta(n)
void eval2(string in, int target) {
	auxEval2(in.substr(1), in.substr(0, 1), target, in.at(0)-'0');
}
//-------------------------------------------------------
int main(int argc, char *argv[]) {
	int target = atoi(argv[2]);
	eval2(argv[1], target);
}

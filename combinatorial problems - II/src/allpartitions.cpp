#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void auxPartitions(string in, string out) {
	if (in.length() == 0) {
		cout << out << endl;
		return;
	}
	string sep = "";
	for (int i = 0; i < in.length(); ++i) {
		if(out.length() != 0)
			sep = "+";
		auxPartitions(in.substr(i + 1), out + sep + in.substr(0, i + 1));
	}
}
//TC:Theta(2^n)  SC:Theta(n)
void partitions(string in) {
	auxPartitions(in, "");
}
int main(int argc, char *argv[]) {
	partitions(argv[1]);
}

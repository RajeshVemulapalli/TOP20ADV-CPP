#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>> &out) {
	for (auto it = out.begin(); it != out.end(); ++it) {
		vector<int> tmp = *it;
		for (auto it2 = tmp.begin(); it2 != tmp.end(); ++it2)
			cout << *it2 << " ";
		cout << endl;
	}
	cout << endl;
}
//TODO: fill up the rules
bool isValid1(vector<vector<int>> &out) {
	return true;
}
void auxSudokuSolver1(int r, int c, vector<vector<int>> &in,
		vector<vector<int>> &out) {
	if (r == 9) {
		if (isValid1(out))
			display(out);
		return;
	}
	if (in[r][c] != 0) {
		auxSudokuSolver1(c == 8 ? r + 1 : r, (c + 1) % 9, in, out);
	} else {
		for (int d = 1; d <= 9; ++d) {
			out[r][c] = d;
			auxSudokuSolver1(c == 8 ? r + 1 : r, (c + 1) % 9, in, out);
		}
	}
}
void sudokuSolver1(vector<vector<int>> &in) {
	vector<vector<int>> out(in);
	auxSudokuSolver1(0, 0, in, out);
}
//---------------------------------------------------------------------
bool isValid2(int r, int c, int d, vector<vector<int>> &out) {
	//row check
	for (int j = 0; j < 9; ++j)
		if (out[r][j] == d)
			return false;
	//column check
	for (int i = 0; i < 9; ++i)
		if (out[i][c] == d)
			return false;
	//subgrid check
	int sr = r / 3 * 3;
	int sc = c / 3 * 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (out[sr + i][sc + j] == d)
				return false;
		}
	}
	return true;
}
void auxSudokuSolver2(int r, int c, vector<vector<int>> &in,
		vector<vector<int>> &out) {
	if (r == 9) {
		display(out);
		return;
	}
	if (in[r][c] != 0) {
		auxSudokuSolver2(c == 8 ? r + 1 : r, (c + 1) % 9, in, out);
	} else {
		for (int d = 1; d <= 9; ++d) {
			if (isValid2(r, c, d, out)) {
				out[r][c] = d;
				auxSudokuSolver2(c == 8 ? r + 1 : r, (c + 1) % 9, in, out);
			}
		}
		out[r][c] = 0;
	}
}
void sudokuSolver2(vector<vector<int>> &in) {
	vector<vector<int>> out(in);
	auxSudokuSolver2(0, 0, in, out);
}
//---------------------------------------------------------------------
int main(int argc, char *argv[]) {
	//vector<vector<int>> in(9, vector<int>(9));
	vector<vector<int>> in = {
			{ 4, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 9, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 7, 8, 5 },
			{ 0, 0, 7, 0, 4, 8, 0, 5, 0 },
			{ 0, 0, 1, 3, 0, 0, 0, 0, 0 },
			{ 0, 0, 6, 0, 7, 0, 0, 0, 0 },
			{ 8, 6, 0, 0, 0, 0, 9, 0, 3 },
			{ 7, 0, 0, 0, 0, 5, 0, 6, 2 },
			{ 0, 0, 3, 7, 0, 0, 0, 0, 0 }
		};
	display(in);
	sudokuSolver2(in);

}

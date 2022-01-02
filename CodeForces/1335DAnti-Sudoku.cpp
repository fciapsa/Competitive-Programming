#include <iostream>
#include <string>
#include <vector>

#define ll long long
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	vector<string> sud(9);
	cin.ignore();
	for (int t = 0; t < T; ++t) {
		for (int i = 0; i < 9; ++i) getline(cin,sud[i]);

		sud[0][1] = sud[0][0];
		sud[1][4] = sud[1][3];
		sud[2][8] = sud[2][7];
		sud[3][3] = sud[3][4];
		sud[4][2] = sud[4][1];
		sud[5][6] = sud[5][7];
		sud[6][7] = sud[6][6];
		sud[7][5] = sud[7][4];
		sud[8][0] = sud[8][1];

		for (int i = 0; i < 9; ++i)cout << sud[i] << '\n';
	}

return 0;
}
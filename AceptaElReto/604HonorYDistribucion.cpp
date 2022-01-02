#include <iostream>
#include <cctype>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int nc, pts;
	string n;
	char p;

	cin >> nc; 
	while (nc--) {
		int np[4] = { 0,0,0,0 };
		pts = 0;

		for (int i = 0; i < 13; ++i) {
			cin >> n >> p;
			if (n == "A") pts += 4;
			else if (n == "K") pts += 3;
			else if (n == "Q") pts += 2;
			else if (n == "J") ++pts;

			if (p == 'C') ++np[0];
			else if (p == 'D') ++np[1];
			else if (p == 'P') ++np[2];
			else ++np[3];
		}

		for (int i = 0; i < 4; ++i) {
			if (np[i] > 2) continue;
			if (np[i] == 2) ++pts;
			else if (np[i] == 1) pts += 2;
			else pts += 3;
		}

		cout << pts << '\n';
	}
}
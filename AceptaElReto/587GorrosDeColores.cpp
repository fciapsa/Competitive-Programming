#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

int main() {
	int t, sol;
	char c;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		sol = 0;
		for (int i = 0; i < s.size(); i += 2) {
			if (s[i] == s[i + 1]) sol += 2;
			else ++sol;
		}

		cout << sol << '\n';
	}

return 0;
}
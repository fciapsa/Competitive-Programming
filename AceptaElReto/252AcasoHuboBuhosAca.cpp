#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	string s;
	bool pal;
	int i, j;
	getline(cin, s);
	while (s != "XXX") {
		pal = true;
		i = 0;
		j = s.size() - 1;
		while (j > i && pal) {
			while (s[i] == ' ') ++i;
			while (s[j] == ' ') --j;
			if (i >= j) continue;
			pal = tolower(s[i]) == tolower(s[j]);
			++i;
			--j;
		}
		if (pal) cout << "SI\n";
		else cout << "NO\n";
		getline(cin, s);
	}
}
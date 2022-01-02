#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, p1, p2;
	string s;
	bool der;
	cin >> n;
	while (n != 0) {
		der = true;
		p1 = p2 = 0;
		while (n--) {
			cin >> s;
			if (s == "PIC") der = !der;
			else if (s == "PONG!") {
				if (der) ++p1;
				else ++p2;
			}
		}

		cout << p1 << ' ' << p2 << '\n';
		cin >> n;
	}
	return 0;
}
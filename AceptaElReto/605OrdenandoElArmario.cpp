#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int i, v;
	char c;
	cin >> c;
	while (c != '.') {
		i = 0;
		v = 0;

		while (c != '.') {
			if (c == 'I') ++i;
			else if (c == 'V') ++v;
			cin >> c;
		}

		if (i > v) cout << "INVIERNO\n";
		else if(v > i) cout << "VERANO\n";
		else cout << "EMPATE\n";

	cin >> c;
	}
}
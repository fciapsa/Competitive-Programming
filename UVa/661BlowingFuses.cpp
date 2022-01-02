#include <iostream>
#include <vector>

using namespace std;

int main() {
	int k = 1, n, m, c,act, max, j;
	cin >> n >> m >> c;
	while(n != 0 && m != 0 && c != 0) {
		max = 0;
		act = 0;
		vector<int> v(n + 1, 0), amps(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> amps[i];
		}

		for (int i = 0; i < m; ++i) {
			cin >> j;
			if (v[j] == 0) {
				v[j] = 1;
				act += amps[j];
				if (act > max) max = act;
			}
			else {
				v[j] = 0;
				act -= amps[j];
			}
		}

		cout << "Sequence " << k << '\n';
		++k;
		if (max > c) cout << "Fuse was blown.\n\n";
		else cout << "Fuse was not blown.\nMaximal power consumption was " << max << " amperes.\n\n";
	cin >> n >> m >> c;
	}
return 0;
}
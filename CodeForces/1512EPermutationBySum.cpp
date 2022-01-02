#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//Since we have numbers from 1 to n, using exactly k of them without repetition we can obtain every sum in the range
// [ k(k+1)/2 , k(n-k+1 + n)/2 ] = [lowest, highest]

int highest(int max, int k) {
	return (k * (max - k + 1 + max) / 2);
}

int lowest(int k) {
	return (k * (k + 1)) / 2;
}

int main() {
	int n, l, r, s, k, i, tc;
	bool first;
	cin >> tc;
	while (tc--) {
		cin >> n >> l >> r >> s;
		k = r - l + 1;
		if (s >= lowest(k) && s <= highest(n, k)) {
			//we try to greedily add i in order n, n-1, ..., 1
			i = n;
			unordered_set<int> range;
			while (i > 0 && s > 0) {
				if (i <= s && lowest(k - 1) <= s - i && highest(i - 1, k - 1) >= s - i) {
					range.insert(i);
					s -= i;
					--k;
				}
				--i;
			}
			first = true;
			for (int p = 1, ind = 1; ind <= n;) {
				if (ind == l) {
					for (int x : range) {
						if (first) {
							first = false;
							cout << x;
						}
						else cout << ' ' << x;
					}
					ind = r + 1;
				}
				else {
					while (range.count(p)) ++p;
					if (p <= n) {
						if (first) {
							first = false;
							cout << p;
						}
						else cout << ' ' << p;
						++p;
						++ind;
					}
				}
			}
			cout << '\n';
		}
		else cout << "-1\n";
	}

return 0;
}
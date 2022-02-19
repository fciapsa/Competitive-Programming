#include <bits/stdc++.h>

using namespace std;
#define ll long long

unordered_set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
199 };

int main() {
	std::ios::sync_with_stdio(false);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool aoki = true;
	for (int i = a; i <= b && aoki; ++i) {
		aoki = false;
		for (int j = c; j <= d && !aoki; ++j) {
			if (primes.count(i + j)) aoki = true;
		}
	}
	if (!aoki) cout << "Takahashi\n";
	else cout << "Aoki\n";
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, mxa, mxb;
	cin >> tc;
	while (tc--) {
		cin >> n;

		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];


		for (int i = 0; i < n; ++i) {
			if (a[i] < b[i]) swap(a[i], b[i]);
		}
		mxa = mxb = 0;
		for (int i = 0; i < n; ++i) if (a[i] > mxa) mxa = a[i];
		for (int i = 0; i < n; ++i) if (b[i] > mxb) mxb = b[i];
		cout << mxa * mxb << '\n';
	}
	return 0;
}
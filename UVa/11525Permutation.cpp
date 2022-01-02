#include <bits/stdc++.h>

using namespace std;
#define ll long long

class FenwickTree {
	vector<int> ft;
public:
	FenwickTree(int n) { ft.assign(n + 1, 0); }
	int getSum(int b) {
		int ret = 0;
		while (b) {
			ret += ft[b]; b -= (b & -b);
		}
		return ret;
	}
	void add(int pos, int val) {
		while (pos < ft.size()) {
			ft[pos] += val; pos += (pos & -pos);
		}
	}
	/*
	int getSum(int a, int b) {
		return getSum(b) - getSum(a - 1);
	}
	int getValue(int pos) {
		return getSum(pos) - getSum(pos - 1);
	}
	void setValue(int pos, int val) {
		add(pos, val - getValue(pos));
	}
	*/
};

int main() {
	std::ios::sync_with_stdio(false);
	int tc, k, s, ini, fin, m;
	cin >> tc;
	while (tc--) {
		cin >> k;
		FenwickTree ft(k);
		for (int i = 2; i <= k; ++i) ft.add(i, 1);

		vector<int> perm;
		
		for (int i = 0; i < k; i++) {
			cin >> s;
			ini = 1, fin = k+1;
			while (ini < fin) {
				m = (ini + fin) / 2;
				if (ft.getSum(m) < s) ini = m + 1;
				else fin = m;
			}

			perm.push_back(ini);
			ft.add(ini, -1);
		}
		
		cout << perm[0];
		for (int i = 1; i < k; ++i) cout << ' ' << perm[i];
		cout << '\n';
	}

}
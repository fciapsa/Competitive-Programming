#include <bits/stdc++.h>

using namespace std;
#define ll long long

string T, P;
vector<int> b; // back table
int n, m; // n = length of T, m = length of P
void kmpPreprocess() { // before calling kmpSearch O(m)
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		++i; ++j;
		b[i] = j;
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc, l;
    bool first = true;
    string s;
    cin >> tc;
    while (tc--) {
        cin >> T;
        P = T;
        n = m = T.size();
        b.assign(n + 1, 0);
        kmpPreprocess();
        l = n - b[n];

        if (first) first = false;
        else cout << '\n';
        if (n % l == 0) cout << l << '\n';
        else cout << n << '\n';
    }
    return 0;
}
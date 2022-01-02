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
void kmpSearch() { //O(n)
	int i = 0, j = 0;
	int max = 0, pos;
	while (i < n) {
		while (j >= 0 && T[i] != P[j])
			j = b[j]; // different reset j using b
		++i; ++j; // same, advance both pointers

		if (j > n-i) {
			pos = i - j;//posicion en la que comienza
		}
		if (j == m) {
			//printf("P is found at index %d in T\n", i - j);
			j = b[j];
		}
	}
	cout << T;
	for (int i = pos - 1; i >= 0; --i) cout << T[i];
	cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (cin) {
		P = T;
		reverse(P.begin(), P.end());
		n = m = T.size();
		b.assign(m + 1, 0);
		kmpPreprocess();
		kmpSearch();

    cin >> T;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	unordered_map<char, int> ind;
	int i = 0;
	for (char c = 'a'; i < k; ++i, ++c) ind[c] = i;
	vector<char> ch(k);
	i = 0;
	for (char c = 'a'; i < k; ++i, ++c) ch[i] = c;

	vector<vector<int>> cnt(k, vector<int>(k, 0));
	cout << 'a';
	char prev = 'a';
	int min, indmin;
	for (int i = 1; i < n; ++i) {
		min = 1e9;
		for (int j = 0; j < k; ++j) {
			if (cnt[ind[prev]][j] <= min) {// leq is crucial
				min = cnt[ind[prev]][j];
				indmin = j;
			}
		}

		++cnt[ind[prev]][indmin];
		cout << ch[indmin];
		prev = ch[indmin];
	}
	cout << '\n';
return 0;
}
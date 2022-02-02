#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int p, v, ind;
	cin >> p >> v;
	vector<pair<pair<int, int>, int>> ped(p);
	for (int i = 0; i < p; ++i) {
		cin >> ped[i].first.first >> ped[i].first.second;
		if (ped[i].first.first > ped[i].first.second) swap(ped[i].first.first, ped[i].first.second);
		ped[i].second = i + 1;
	}
	sort(ped.begin(), ped.end());

	vector<pair<int, int>> vas(v);
	for (int i = 0; i < v; ++i) {
		cin >> vas[i].first;
		vas[i].second = i + 1;
	}
	sort(vas.begin(), vas.end());

	vector<int> to(v+1);
	ind = 0;
	for (int i = 0; i < p && ind < v; ++i) {
		if (ped[i].first.first == vas[ind].first || ped[i].first.second == vas[ind].first) {
			to[vas[ind].second] = ped[i].second;
			++ind;
		}
	}

	if (ind == v) for (int i = 1; i <= v; ++i) cout << to[i] << '\n';
	else cout << "impossible\n";
	return 0;
}
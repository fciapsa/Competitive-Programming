#include <iostream>
#include <vector>

#define ll long long
using namespace std;

struct clase {
	int ini, fin;
};

int main() {
	int T, hh, mm, L, n, dura, sol;
	char aux;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> L >> n;
		std::vector<clase> v;
		v.push_back({ 480,480 });
		for (int i = 0; i < n; ++i) {
			cin >> hh >> aux >> mm >> dura;
			v.push_back({ 60 * hh + mm, 60 * hh + mm + dura });
		}
		v.push_back({ 14 * 60,14 * 60 });

		sol = 0;
		for (int i = 0; i < v.size()-1; ++i) {
			if (v[i + 1].ini - v[i].fin >= L) sol += v[i + 1].ini - v[i].fin;
		}

		cout << sol << '\n';
	}

return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

struct tBase {
	int min, bajas, dif;
	bool operator<(tBase const& other) const {
		return dif > other.dif || (dif == other.dif && min > other.min);
	}
};

int main() {
	int N, s, b, r, sol, quedan;
	std::cin >> N;
	while (N != 0) {
		std::vector<tBase> v;
		for (int i = 0; i < N; ++i) {
			std::cin >> s >> b >> r;
			v.push_back({ s,b + r});
			v[i].dif = s - v[i].bajas;
		}

		sort(v.begin(), v.end());

		if (v[0].min >= v[0].bajas) {
			sol = v[0].min;
			quedan = v[0].min - v[0].bajas;
		}
		else {
			sol = v[0].bajas;
			quedan = 0;
		}

		for (int i = 1; i < N; ++i) {
			if (v[i].min > quedan) {
				sol += (v[i].min - quedan);
				quedan = v[i].min;
			}

			if (quedan >= v[i].bajas) quedan -= v[i].bajas;
			else {
				sol += (v[i].bajas - quedan);
				quedan = 0;
			}
		}

		std::cout << sol << '\n';

	std::cin >> N;
	}
return 0;
}
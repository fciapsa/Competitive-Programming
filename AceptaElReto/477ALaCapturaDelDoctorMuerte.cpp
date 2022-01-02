#include <iostream>
#include <vector>
#include <algorithm>

struct arma {
	int id,dmg1, dmg2;
	bool operator<(arma const& other) const {
		return dmg1 < other.dmg1 || (dmg1 == other.dmg1 && dmg2 > other.dmg2 ||
			(dmg1 == other.dmg1 && dmg2 == other.dmg2 && id < other.id));
	}
};

int main() {
	int V, N, dmg1, dmg2, k;
	std::cin >> V;
	while (V != 0) {
		std::cin >> N;
		std::vector<arma> v;
		for (int i = 1; i <= N; ++i) {
			std::cin >> dmg1 >> dmg2;
			v.push_back({ i,dmg1,dmg2 });
		}

		sort(v.begin(), v.end());
		k = 0;
		while (V > 0 && k < N) {
			V -= v[k].dmg2;
			if (V > 0) ++k;
		}

		if (V > 0) std::cout << "MUERTE ESCAPA\n";
		else {
			std::cout << v[0].id;
			for (int i = 1; i <= k; ++i) std::cout << ' ' << v[i].id;
			std::cout << '\n';
		}

	std::cin >> V;
	}
return 0;
}
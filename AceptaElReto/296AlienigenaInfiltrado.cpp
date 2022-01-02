#include <iostream>
#include <vector>
#include <algorithm>

struct tRango {
	int a, b;
};

struct tOrd {
	bool operator()(tRango const& r1, tRango const& r2) {
		return r1.a < r2.a || (r1.a == r2.a && r1.b > r2.b);
	}
};

bool resuelveCaso() {
	int C, F, N;
	std::cin >> C >> F >> N;

	if (C == 0 && F == 0 && N == 0) return false;

	std::vector<tRango> v(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> v[i].a >> v[i].b;
	}

	sort(v.begin(), v.end(), tOrd());
	tRango act = { -1,C }, next = { -1,-1 };
	int i = 0, trabajos = 0;
	while (i < N && act.b < F && act.b != -1) {

		while (i < N && v[i].a <= act.b) {
			if (v[i].b > next.b) next = v[i];
			++i;
		}
		act = next;
		next = { -1,-1 };
		++trabajos;
	}

	if (act.b >= F) std::cout << trabajos << '\n';
	else std::cout << "Imposible\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
//Flavius Abel Ciapsa

#include <iostream>
#include <vector>
#include <algorithm>

struct tRango {
	int a, b;
};

struct tOrd {
	bool operator()(tRango const& r1, tRango const& r2) {
		return r1.b < r2.b || (r1.b == r2.b && r1.a > r2.a);
	}
};

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::vector<tRango> v(N);
	int hh, mm, t;
	char aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> hh >> aux >> mm >> t;
		v[i].a = 60 * hh + mm;
		v[i].b = v[i].a + t;
	}

	sort(v.begin(), v.end(), tOrd());

	int finAnterior = -10, max = 0;
	for (int i = 0; i < N; ++i) {
		if (v[i].a >= finAnterior + 10){
			++max;
			finAnterior = v[i].b;
		}
	}
	std::cout << max << '\n';

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}
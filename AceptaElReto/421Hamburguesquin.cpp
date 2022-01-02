#include <iostream>
#include <vector>
#include <algorithm>

struct tRango {
	long long int ini, fin;
};

struct tOrd {
	bool operator()(tRango const& r1, tRango const& r2) {
		return r1.ini < r2.ini || (r1.ini == r2.ini && r1.fin > r2.fin);
	}
};

bool resuelve() {
	long long int L,N;
	std::cin >> L >> N;

	if (!std::cin) return false;

	if (N > 0) {
		long long int pos, r;
		std::vector<tRango> v;
		for (int i = 0; i < N; ++i) {
			std::cin >> pos >> r;
			v.push_back({ pos - r, pos + r });
		}

		sort(v.begin(), v.end(), tOrd());
		bool cubre = v[0].ini <= 0;
		long long int max = v[0].fin;
		for (int i = 1; i < N - 1 && cubre; ++i) {
			if (v[i].ini > max) cubre = false;
			else max = std::max(max, v[i].fin);
		}
		cubre = cubre && (max >= L || (v[N - (long long int)1].ini <= max && v[N - (long long int)1].fin >= L));

		if (!cubre) std::cout << "-1\n";
		else {
			std::vector<bool> existe(N, true);
			int sol = 0;

			int ant = -1, i = 0, j, k, sig;
			while (i < N) {
				if (existe[i]) {
					k = i - 1;
					while (k >= 0 && std::max(v[k].ini, (long long int)0) >= v[i].ini) {
						if (existe[k]) {
							++sol;
							existe[k] = false;
							if (ant == k) {
								ant = k - 1;
								while (ant >= 0 && !existe[ant]) --ant;
							}
						}
						--k;
					}
					j = i + 1;
					while (j < N && v[j].ini < v[i].fin) {
						if (existe[j] && std::min(v[j].fin, L) <= v[i].fin) {
							++sol;
							existe[j] = false;
						}
						++j;
					}
					if (ant != -1 && i < N - 1) {
						sig = i + 1;
						while (sig < N && !existe[sig]) ++sig;
						if (sig < N) {
							if (v[ant].fin >= v[sig].ini) {
								++sol;
								existe[i] = false;
							}
						}
					}
					if (existe[i]) ant = i;
				}
				++i;
			}
			std::cout << sol << '\n';
		}
	}
	else std::cout << "-1\n";

return true;
}

int main() {
	while (resuelve());
return 0;
}
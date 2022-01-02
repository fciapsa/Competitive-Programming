#include <iostream>
#include <vector>
#include <algorithm>

struct desarrollo {
	double p, c, q;
	bool operator<(desarrollo const& other) const{
		return q < other.q;
	}
};

int main() {
	int np, nc;
	double c;
	std::cin >> np >> nc;
	while (np != 0) {
		std::vector<double> vp(np);
		for (int i = 0; i < np; ++i) std::cin >> vp[i];

		std::vector<desarrollo> vs;
		for (int i = 0; i < nc; ++i) {
			std::cin >> c;
			for (int j = 0; j < np; ++j) {
				vs.push_back({ vp[j],c,vp[j] / c });
			}
		}
		sort(vs.begin(), vs.end());

		std::cout << vs[0].p << '-' << vs[0].c;
		for (int i = 1; i < vs.size(); ++i) std::cout << ' ' << vs[i].p << '-' << vs[i].c;
		std::cout << '\n';

	std::cin >> np >> nc;
	}
}
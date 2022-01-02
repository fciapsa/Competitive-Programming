#include <iostream>
#include <vector>
#include <algorithm>

struct tarea {
	int prio, t;
	bool operator<(tarea const& other) const {
		return this->prio > other.prio || (this->prio == other.prio && this->t < other.t);
	}
};

int main() {
	int n;
	std::cin >> n;
	while(n != 0) {
		std::vector<tarea> v(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> v[i].prio >> v[i].t;
		}

		sort(v.begin(), v.end());
		for (int i = 0; i < n; ++i) {
			std::cout << v[i].prio << ' ' << v[i].t << '\n';
		}
		std::cout << "---\n";
	std::cin >> n;
	}
	return 0;
}
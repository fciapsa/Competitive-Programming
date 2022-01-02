#include <iostream>
#include <queue>
#include <vector>
#include <deque>

struct tCaja {
	int n, tiempo;
};

struct tComp {
	bool operator()(tCaja const& c1, tCaja const& c2) {
		return c1.tiempo > c2.tiempo || (c1.tiempo == c2.tiempo && c1.n > c2.n);
	}
};

bool resuelveCaso() {
	int N, C;
	std::cin >> N >> C;

	if (!std::cin) return false;

	std::priority_queue<tCaja, std::vector<tCaja>, tComp> cola;
	for (int i = 1; i <= N; ++i) cola.push({ i,0 });

	int act, lapso;
	std::deque<tCaja> dcola;
	for (int i = 0; i < C; ++i) {
		lapso = cola.top().tiempo;

		if (lapso > 0) {
			while (!cola.empty()) {
				dcola.push_back({ cola.top().n,cola.top().tiempo - lapso });
				cola.pop();
			}

			while (!dcola.empty()) {
				cola.push(dcola.front());
				dcola.pop_front();
			}
		}

		std::cin >> act;
		cola.push({ cola.top().n,act });
		cola.pop();
	}

	std::cout << cola.top().n << '\n';
return true;
}

int main() {
	while (resuelveCaso());
return 0;
}
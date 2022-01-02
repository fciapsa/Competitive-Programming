#include <iostream>
#include <vector>
#include <algorithm>

struct tTramo {
	int dist, desniv;
};

int main() {
	int D, S, dist, desniv, dias, max_dist, max_desniv, aux_dist, aux_desniv, i;
	std::cin >> D >> S;
	while (std::cin) {
		max_dist = 0;
		max_desniv = 0;
		std::vector<tTramo> tramos;
		std::cin >> dist >> desniv;
		while (dist != 0 || desniv != 0) {
			tramos.push_back({ dist,desniv });
			if (dist > max_dist) max_dist = dist;
			if (desniv > max_desniv) max_desniv = desniv;
			std::cin >> dist >> desniv;
		}

		if (tramos.size() == 0) std::cout << "0\n";
		else if (max_dist > D || max_desniv > S) std::cout << "DESTITUIDO\n";
		else {
			dias = 0;
			i = 0;
			while (i < tramos.size()) {
				aux_dist = tramos[i].dist;
				aux_desniv = std::max(tramos[i].desniv,0);
				while (i + 1 < tramos.size() && aux_dist + tramos[i + 1].dist <= D && 
					aux_desniv + std::max(0,tramos[i + 1].desniv) <= S) {
					++i;
					aux_dist += tramos[i].dist;
					aux_desniv += std::max(0,tramos[i].desniv);
				}
				++dias;
			++i;
			}
			std::cout << dias << '\n';
		}

	std::cin >> D >> S;
	}
return 0;
}
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <climits>

struct arista {
	int t, to;
};
struct tOrd {
	bool operator()(arista const& a1, arista const& a2) {
		return a1.t > a2.t;
	}
};

int main() {
	int N, M, x, cost, first, acum, costeIda, costeVuelta;
	arista act;
	std::string line;
	std::cin >> N >> M;
	while (std::cin) {
		std::getline(std::cin, line);
		//se transforma el grafo de entrada(paradas) en un grafo entre lineas de autobus 
		//Linea 0: facultad Linea M+1: Casa
		std::vector<std::vector<arista>> adyList(M + 2);
		std::vector<std::vector<arista>> vaux(N + 1);
		for (int i = 1; i <= M; ++i) {
			std::getline(std::cin, line);
			std::istringstream os(line);

			os >> first;
			if (first == 1) {
				adyList[0].push_back({ 0,i });
				adyList[i].push_back({ 0,0 });
			}
			else if (first == N) {
				adyList[i].push_back({ 0,M + 1 });
				adyList[M + 1].push_back({ 0,i });
			}

			acum = 0;
			for (int j = 0; j < vaux[first].size(); ++j) {
				if (acum <= vaux[first][j].t) {
					costeIda = vaux[first][j].t - acum;
					costeVuelta = 60 - vaux[first][j].t + acum;
					if (costeVuelta == 60) costeVuelta = 0;
				}
				else {
					costeIda = 60 - acum + vaux[first][j].t;
					costeVuelta = acum - vaux[first][j].t;
					if (costeIda == 60) costeIda = 0;
				}

				adyList[i].push_back({ costeIda,vaux[first][j].to });
				adyList[vaux[first][j].to].push_back({ costeVuelta,i });
			}
			vaux[first].push_back({ 0,i });

			while (os >> cost) {
				os >> x;
				acum += cost;
				if (x == 1) {
					adyList[0].push_back({ 0,i });
					adyList[i].push_back({ 0,0 });
				}
				else if (x == N) {
					adyList[i].push_back({ 0,M + 1 });
					adyList[M + 1].push_back({ 0,i });
				}

				for (int j = 0; j < vaux[x].size(); ++j) {
					if (acum <= vaux[x][j].t) {
						costeIda = vaux[x][j].t - acum;
						costeVuelta = 60 - vaux[x][j].t + acum;
						if (costeVuelta == 60) costeVuelta = 0;
					}
					else {
						costeIda = 60 - acum + vaux[x][j].t;
						costeVuelta = acum - vaux[x][j].t;
						if (costeIda == 60) costeIda = 0;
					}
					adyList[i].push_back({ costeIda,vaux[x][j].to });
					adyList[vaux[x][j].to].push_back({ costeVuelta,i });
				}
				vaux[x].push_back({ acum,i });
			}
		}

		std::vector<int> distTo(M + 2, INT_MAX);
		distTo[0] = 0;
		std::priority_queue<arista, std::vector<arista>, tOrd> pq;//!!!
		pq.push({ 0,0 });
		while (!pq.empty()) {
			act = pq.top();
			pq.pop();

			if (act.t > distTo[act.to]) continue;
			for (int i = 0; i < adyList[act.to].size(); ++i) {
				if (adyList[act.to][i].t + distTo[act.to] < distTo[adyList[act.to][i].to]) {
					distTo[adyList[act.to][i].to] = adyList[act.to][i].t + distTo[act.to];
					pq.push({ distTo[adyList[act.to][i].to] , adyList[act.to][i].to });
				}
			}
		}

		if (distTo[M + 1] != INT_MAX) std::cout << distTo[M + 1] << '\n';
		else std::cout << "Hoy no vuelvo\n";

		std::cin >> N >> M;
	}
	return 0;
}
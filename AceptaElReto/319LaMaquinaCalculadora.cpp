#include <iostream>
#include <vector>
#include <queue>

const int MOD = 10000;

struct tEstado {
	int x, nivel;
};

int main() {
	int x, y, sol, aux;
	bool found;
	tEstado act;
	std::cin >> x >> y;
	while (std::cin) {
		if (x == y) std::cout << "0\n";
		else {
			found = false;
			std::vector<bool> visited(MOD, false);
			visited[x] = true;
			std::queue<tEstado> cola;
			cola.push({ x,0 });
			while (!found) {
				act = cola.front();
				cola.pop();

				aux = act.x + 1;
				if (aux == MOD) aux = 0;
				if (aux == y) {
					found = true;
					sol = act.nivel + 1;
				}
				else {
					if (!visited[aux]) {
						visited[aux] = true;
						cola.push({ aux,act.nivel + 1 });
					}
				}
				if (!found && act.x != 0) {
					aux = (2 * act.x) % MOD;
					if (aux == y) {
						found = true;
						sol = act.nivel + 1;
					}
					else {
						if (!visited[aux]) {
							visited[aux] = true;
							cola.push({ aux,act.nivel + 1 });
						}
					}

					aux = act.x / 3;
					if (aux == y) {
						found = true;
						sol = act.nivel + 1;
					}
					else {
						if (!visited[aux]) {
							visited[aux] = true;
							cola.push({ aux,act.nivel + 1 });
						}
					}
				}
			}

			std::cout << sol << '\n';
		}
	std::cin >> x >> y;
	}
return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

int main() {
	int L, r, remember1, remember2;
	bool ok;
	std::cin >> L;
	while (L != 0) {
		ok = false;
		std::cin >> r;
		std::vector<int> caps(4);
		for (int i = 0; i < r; ++i) {
			std::cin >> caps[i];
			if (caps[i] == L) ok = true;
		}

		if (ok) std::cout << "SI\n";
		else {
			std::vector<int> act;
			std::queue<std::vector<int>> cola;
			cola.push({ 0,0,0,0 });
			std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, int>>>> marcas;
			++marcas[0][0][0][0];
			while (!cola.empty() && !ok) {
				act = cola.front();
				cola.pop();

				for (int i = 0; i < r; ++i) {
					if (act[i] != caps[i]) {//se puede llenar
						remember1 = act[i];
						act[i] = caps[i];
						++marcas[act[0]][act[1]][act[2]][act[3]];
						if (marcas[act[0]][act[1]][act[2]][act[3]] == 1) {
							cola.push({ act[0],act[1],act[2],act[3] });
						}
						act[i] = remember1;
					}

					if (act[i] != 0) {//se puede vaciar
						remember1 = act[i];
						act[i] = 0;
						++marcas[act[0]][act[1]][act[2]][act[3]];
						if (marcas[act[0]][act[1]][act[2]][act[3]] == 1) {
							cola.push({ act[0],act[1],act[2],act[3] });
						}
						act[i] = remember1;
					}

					for (int j = 0; j < r; ++j) {//posibles trasvases
						if (i != j) {
							if (act[i] != caps[i] && act[j] > 0) {//de j a i
								remember1 = act[i];
								remember2 = act[j];

								act[i] = std::min(caps[i], act[i] + act[j]);
								act[j] = std::max(0, act[j] - (caps[i] - remember1));
								++marcas[act[0]][act[1]][act[2]][act[3]];
								if (marcas[act[0]][act[1]][act[2]][act[3]] == 1) {
									if (act[i] == L || act[j] == L) ok = true;
									else cola.push({ act[0],act[1],act[2],act[3] });
								}
								act[i] = remember1;
								act[j] = remember2;
							}
							if (act[j] != caps[j] && act[i] > 0) {//de i a j
								remember1 = act[i];
								remember2 = act[j];

								act[j] = std::min(caps[j], act[j] + act[i]);
								act[i] = std::max(0, act[i] - (caps[j] - remember2));
								++marcas[act[0]][act[1]][act[2]][act[3]];
								if (marcas[act[0]][act[1]][act[2]][act[3]] == 1) {
									if (act[i] == L || act[j] == L) ok = true;
									else cola.push({ act[0],act[1],act[2],act[3] });
								}
								act[i] = remember1;
								act[j] = remember2;
							}
						}
					}

				}
			}


			if (ok) std::cout << "SI\n";
			else std::cout << "NO\n";
		}
	std::cin >> L;
	}
return 0;
}
#include <iostream>
#include <unordered_map>
#include <queue>
#include <unordered_set>

int main() {
	int N, K, x, copias, pillados;
	bool nuevo;
	std::cin >> N >> K;
	while (std::cin) {
		std::unordered_map<int, int> recuerdo;
		std::unordered_set<int> ocurrido;
		std::queue<int> memoria;
		copias = 0;
		pillados = 0;
		for (int i = 0; i < N; ++i) {
			std::cin >> x;
			++recuerdo[x];
			nuevo = ocurrido.insert(x).second;
			memoria.push(x);
			if (recuerdo[x] > 1) ++pillados;
			if (!nuevo) ++copias;
			if (memoria.size() > K) {
				--recuerdo[memoria.front()];
				memoria.pop();
			}
		}
		std::cout << copias << ' ' << pillados << '\n';
	std::cin >> N >> K;
	}
return 0;
}
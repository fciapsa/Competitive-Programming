#include <iostream>
#include <vector>

struct par {
	int a, b;
};
struct obj {
	int tipo, num;
};

int main() {
	int N, x;
	bool found;
	char c;
	std::cin >> N;
	while (N != 0) {
		std::vector<int> puntos(N);
		for (int i = 0; i < N; ++i) std::cin >> puntos[i];
		std::vector<obj> deseos;
		for (int i = 0; i < N; ++i) {
			std::cin >> c >> x;
			if (c == '<') deseos.push_back({ 0, x });
			else if (c == '=') deseos.push_back({ 1,x });
			else deseos.push_back({ 2,x });
		}

		std::vector<bool> marked(N, false);
		std::vector<par> sol;
		for (int i = 0; i < N; ++i) {
			if (!marked[i]) {
				found = false;
				if (deseos[i].tipo == 0) {
					for (int j = i + 1; j < N && !found; ++j) {
						if (!marked[j] && puntos[j] < deseos[i].num) {
							if ((deseos[j].tipo == 0 && puntos[i] < deseos[j].num) || (deseos[j].tipo == 1 && puntos[i] == deseos[j].num)
								|| (deseos[j].tipo == 2 && puntos[i] > deseos[j].num)) {
								found = true;
								sol.push_back({ i + 1,j + 1 });
								marked[j] = true;
							}
						}
					}
				}
				else if (deseos[i].tipo == 1) {
					for (int j = i + 1; j < N && !found; ++j) {
						if (!marked[j] && puntos[j] == deseos[i].num) {
							if ((deseos[j].tipo == 0 && puntos[i] < deseos[j].num) || (deseos[j].tipo == 1 && puntos[i] == deseos[j].num)
								|| (deseos[j].tipo == 2 && puntos[i] > deseos[j].num)) {
								found = true;
								sol.push_back({ i + 1,j + 1 });
								marked[j] = true;
							}
						}
					}
				}
				else {
					for (int j = i + 1; j < N && !found; ++j) {
						if (!marked[j] && puntos[j] > deseos[i].num) {
							if ((deseos[j].tipo == 0 && puntos[i] < deseos[j].num) || (deseos[j].tipo == 1 && puntos[i] == deseos[j].num)
								|| (deseos[j].tipo == 2 && puntos[i] > deseos[j].num)) {
								found = true;
								sol.push_back({ i + 1,j + 1 });
								marked[j] = true;
							}
						}
					}
				}
			}
		}

		if (sol.size() == 0) std::cout << "NO HAY\n";
		else {
			for (int i = 0; i < sol.size(); ++i) std::cout << sol[i].a << ' ' << sol[i].b << '\n';
		}
		std::cout << "---\n";
	std::cin >> N;
	}
return 0;
}
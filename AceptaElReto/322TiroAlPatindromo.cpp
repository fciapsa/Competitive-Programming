#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

bool resuelveCaso() {
	std::string s;
	std::cin >> s;

	if (!std::cin) return false;

	int N = s.size();
	std::vector<std::vector<int >> maxLong(N, std::vector<int>(N));
	//casos base
	for (int i = 0; i < N; ++i) maxLong[i][i] = 1;
	for (int i = 0; i < N - 1; ++i) {
		if (s[i] == s[i + 1]) maxLong[i][i + 1] = 2;
		else maxLong[i][i + 1] = 1;
	}
	//rellenamos el resto de la tabla segun los casos recursivos
	int hasta;
	for (int d = 2; d < N; ++d) {
		hasta = N - d;
		for (int i = 0; i < hasta; ++i) {
			if (s[i] == s[i + d]) maxLong[i][i + d] = 2 + maxLong[i + 1][i + d - 1];
			else maxLong[i][i + d] = std::max(maxLong[i + 1][i + d], maxLong[i][i + d - 1]);
		}
	}

	int tam = maxLong[0][N - 1];
	if (tam == 1) std::cout << s[N - 1] << '\n';
	else if (tam == N) std::cout << s << '\n';
	else {
		int min_i = 0;
		std::stack<char> sol;
		bool saltar;
		for (int j = N - 1; j >= 0 && tam > 0; --j) {
			saltar = false;
			for (int i = j - 1; i >= min_i && !saltar; --i) {
				if (maxLong[i][j] == tam && s[i] == s[j]) {
					std::cout << s[j];
					sol.push(s[j]);
					saltar = true;
					min_i = i + 1;
					tam -= 2;
					if (tam == 1) {
						std::cout << s[j - 1];
						--tam;
					}
				}
			}
		}
		while (!sol.empty()) {
			std::cout << sol.top();
			sol.pop();
		}
		std::cout << '\n';
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
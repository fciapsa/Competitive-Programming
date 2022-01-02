#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	int N;
	std::string s;
	std::cin >> s;
	while (std::cin) {
		N = s.size();
		std::vector<std::vector<int>> necesito(N, std::vector<int>(N));
		//casos base
		//los necesito[i][i] ya estan a cero
		for (int i = 0; i < N-1; ++i) {
			if (s[i] != s[i+1]) necesito[i][i+1] = 1;
		}
		//relleno el resto de la tabla segun la defincion de los casos recursivos
		for (int d = 2; d < N; ++d) {
			for (int i = 0, j = d; j < N; ++i, ++j) {
				if (s[i] == s[j]) necesito[i][j] = necesito[i + 1][j - 1];
				else necesito[i][j] = std::min(1 + necesito[i + 1][j],1 + necesito[i][j - 1]);
			}
		}


		std::cout << necesito[0][N - 1] << '\n';
	std::cin >> s;
	}
return 0;
}
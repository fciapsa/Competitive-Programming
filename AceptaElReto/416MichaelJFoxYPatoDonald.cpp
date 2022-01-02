#include <iostream>
#include <vector>

int main() {
	int N, i, a, b, c;
	char aux;
	std::string s;
	std::cin >> N;
	while (N != 0) {

		if (N == 1) {
			std::cin >> a >> aux >> b >> aux >> c;
			std::cout << "NO\n";
		}
		else {
			std::vector<std::vector<bool>> mat(13, std::vector<bool>(32, false));
			bool rep = false;
			i = 0;
			while (i < N && !rep) {
				std::cin >> a >> aux >> b >> aux >> c;
				if (mat[b][a]) rep = true;
				else mat[b][a] = true;
				++i;
			}
			while (i < N) {
				std::cin >> a >> aux >> b >> aux >> c;
				++i;
			}

			if (rep) std::cout << "SI\n";
			else std::cout << "NO\n";
		}

	std::cin >> N;
	}
return 0;
}
#include <iostream>
#include <vector>

int main() {
int nc;
std::cin >> nc;

	for (int i = 0; i < nc; ++i) {
		int ptsG, t;
		std::cin >> ptsG >> t;

		std::vector<int> v(ptsG);
		for (int i = 0; i < ptsG; ++i) {
			std::cin >> v[i];
		}

		if (v[v.size() - 1] == 0) std::cout << "0\n";
		else if (ptsG == 1) std::cout << "1\n";
		else {
			int acum = 0, ses = 0;
			int i = 0;
			while(i < ptsG) {
				bool add = false;
				if(i == 0) acum += v[i];
				else acum += v[i] - v[i - 1];
				while (i + 1 < ptsG && acum + v[i + 1] - v[i] <= t) {
					acum += v[i + 1] - v[i];
					add = true;
					++i;
				}
				++ses;
				acum = 0;
				++i;
			}

			std::cout << ses << '\n';
		}
	}

return 0;
}
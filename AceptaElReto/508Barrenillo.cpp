#include <iostream>
#include <algorithm>
#include <vector>


bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::vector<int> ini(N);
	std::vector<int> fin(N);

	int x, y;
	for (int i = 0; i < N; ++i) {
		std::cin >> x >> y;
		ini[i] = x - y;
		fin[i] = x + y;
	}

	sort(ini.begin(), ini.end());
	sort(fin.begin(), fin.end());

	int act = 0, mejor = 0;
	int pos = ini[0];
	int j = 0, k = 0;

	while(j < N) {
		while (k < N && fin[k] < pos) {
			--act;
			++k;
		}
		while (j < N && ini[j] <= pos) {
			++act;
			++j;
		}
		if (j < N) pos = ini[j];
		if (act > mejor) mejor = act;
	}
	std::cout << mejor << '\n';

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}
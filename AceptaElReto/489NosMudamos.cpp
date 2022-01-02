#include <iostream>
#include <vector>
#include <algorithm>

bool resuelve() {
	int g, a;
	std::cin >> g >> a;

	if (!std::cin) return false;

	std::vector<int> alu(g);
	std::vector<int> tams(a);


	for (int i = 0; i < g; ++i) {
		std::cin >> alu[i];
	}
	for (int i = 0; i < a; ++i) {
		std::cin >> tams[i];
	}

	std::sort(alu.begin(), alu.end());
	std::sort(tams.begin(), tams.end());

	int i = 0, j = 0;
	while (i < alu.size() && j < tams.size()) {
		if (alu[i] <= tams[j]) {
			++i;
			++j;
		}
		else while (j < tams.size() && tams[j] < alu[i]) ++j;
	}
	
	if (i == alu.size()) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {
	while (resuelve());
	return 0;
}
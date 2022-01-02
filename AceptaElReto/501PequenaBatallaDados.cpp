#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

bool resuelve() {
	int td, ta, dd, da, no;
	std::cin >> td >> ta >> dd >> da >> no;

	if (!std::cin) return false;

	for (int i = 0; i < no; ++i) {
		std::vector<int> def(std::min(td, dd));
		std::vector<int> ata(std::min(ta, da));

		for (int j = 0; j < def.size(); ++j)std::cin >> def[j];
		for (int j = 0; j < ata.size(); ++j)std::cin >> ata[j];

		std::sort(def.begin(), def.end(), std::greater<int>());
		std::sort(ata.begin(),ata.end(), std::greater<int>());

		int compare = std::min(def.size(), ata.size());
		for (int j = 0; j < compare; ++j) {
			if (ata[j] <= def[j]) --ta;
			else --td;
		}
	}

	std::cout << td << ' ' << ta << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int x, y, a, b, c;
	std::cin >> x >> y >> a >> b >> c;
	long long int sol = 0;

	std::vector<long long int> red(a), green(b), blank(c);
	for (int i = 0; i < a; ++i) std::cin >> red[i];
	for (int i = 0; i < b; ++i) std::cin >> green[i];
	for (int i = 0; i < c; ++i) std::cin >> blank[i];

	sort(red.rbegin(), red.rend());
	sort(green.rbegin(), green.rend());
	sort(blank.rbegin(), blank.rend());
	int k = 0;
	int lastR = x - 1, lastG = y - 1;
	
	while (k < c && lastR >= 0 && lastG >= 0 && (blank[k] > red[lastR] || blank[k] > green[lastG])) {
		if (red[lastR] < green[lastG]) {
			--lastR;
			sol += blank[k];
			++k;
		}
		else {
			--lastG;
			sol += blank[k];
			++k;
		}
	}
	while (k < c && lastR >= 0 && blank[k] > red[lastR]) {
		--lastR;
		sol += blank[k];
		++k;
	}
	while (k < c && lastG >= 0 && blank[k] > green[lastG]) {
		--lastG;
		sol += blank[k];
		++k;
	}

	for (int i = 0; i <= lastR; ++i) sol += red[i];
	for (int i = 0; i <= lastG; ++i) sol += green[i];

	std::cout << sol << '\n';
return 0;
}
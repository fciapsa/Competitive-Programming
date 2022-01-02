#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool resuelveCaso() {
	std::string s1, s2;
	std::cin >> s1 >> s2;

	if (!std::cin) return false;

	std::vector<std::vector<int>> maxLong(s1.size() + 1, std::vector<int>(s2.size() + 1,0));
	for (int i = 1; i <= s1.size(); ++i) {
		for (int j = 1; j <= s2.size(); ++j) {
			if (s1[i - 1] == s2[j - 1]) maxLong[i][j] = 1 + maxLong[i - 1][j - 1];
			else maxLong[i][j] = std::max(maxLong[i - 1][j], maxLong[i][j - 1]);
		}
	}

	std::cout << maxLong[s1.size()][s2.size()] << '\n';
return true;
}

int main() {
	while (resuelveCaso());
return 0;
}
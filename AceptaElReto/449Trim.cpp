#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	std::string s;
	int hasta1,hasta2, aux1, aux2;
	std::cin >> s;
	while (std::cin) {
		std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size()));
		//casos base
		for (int i = 0; i < s.size(); ++i) dp[i][i] = 1;
		for (int i = s.size()-1; i > 0; --i) {
			if (s[i-1] == s[i]) dp[i - 1][i] = 1;
			else dp[i - 1][i] = 2;
		}

		for (int d = 2; d < s.size(); ++d) {
			for (int i = 0, j = d; i < s.size() - d; ++i, ++j) {
				if (s[i] == s[j]) {
					hasta1 = i + 1;
					while (hasta1 < s.size() && s[hasta1] == s[i]) ++hasta1;
					hasta2 = j - 1;
					while (hasta2 > i && s[hasta2] == s[i]) --hasta2;

					if (hasta1 <= hasta2) dp[i][j] = 1 + dp[hasta1][hasta2];
					else dp[i][j] = 1;
				}
				else {
					hasta1 = i + 1;
					while (hasta1 < s.size() && s[hasta1] == s[i]) ++hasta1;
					aux1 = 1 + dp[hasta1][j];

					hasta2 = j - 1;
					while (hasta2 > i && s[hasta2] == s[j]) --hasta2;
					aux2 = 1 + dp[i][hasta2];

					dp[i][j] = std::min(aux1, aux2);
				}
			}
		}

		std::cout << dp[0][s.size() - 1] << '\n';
	std::cin >> s;
	}
return 0;
}
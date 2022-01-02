#include <iostream>
#include <vector>
#include <string>

int dp(int pos, std::string const& num, std::vector<int>& memo) {
	if (pos == num.size()) return 1;

	if (memo[pos] != -1) return memo[pos];

	int aux;
	if (num[pos] == 'I') {
		aux = dp(pos + 1, num, memo);
		if (pos + 1 < num.size()) {
			if (num[pos + 1] == 'I') {
				aux += dp(pos + 2, num, memo);
				if (pos + 2 < num.size() && num[pos + 2] == 'I') {
					aux += dp(pos + 3, num, memo);
				}
			}
			else aux += dp(pos + 2, num, memo);
		}
	}
	else if (num[pos] == 'V') {
		aux = dp(pos + 1, num, memo);
		if (pos + 1 < num.size() && num[pos + 1] == 'I') {
			aux += dp(pos + 2, num, memo);
			if (pos + 2 < num.size() && num[pos + 2] == 'I') {
				aux += dp(pos + 3, num, memo);
				if (pos + 3 < num.size() && num[pos + 3] == 'I') {
					aux += dp(pos + 4, num, memo);
				}
			}
		}
	}
	else aux = dp(pos + 1, num, memo);

	memo[pos] = aux;

	return aux;
}

int main() {
	std::string num;
	std::cin >> num;
	while (std::cin) {
		std::vector<int> memo(num.size(), -1);
		std::cout << dp(0, num, memo) << '\n';
		std::cin >> num;
	}
	return 0;
}
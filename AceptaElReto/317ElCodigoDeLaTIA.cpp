#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

const long long int MOD = 1000000007;
std::unordered_set<long long int> symbs;
std::vector<long long int> memo;

long long int resolver(std::string const& word, int act) {
	if (act == word.size()) return 1;

	if (memo[act] != -1) return memo[act];

	long long int aux = 0, num = 0;
	for (int i = 0; i <= 10 && act + i < word.size(); ++i) {
		num *= 10;
		num += (int(word[act + i]) - int('0'));
		if (symbs.count(num)) {
			aux = (aux + resolver(word, act + i + 1)) % MOD;
		}
	}

	memo[act] = aux;
	return aux;
}

int main() {
	std::string msg;
	long long int N, x, ini, fin, sol;
	std::cin >> N;
	while (N != 0) {
		symbs.clear();
		for (int i = 0; i < N; ++i) {
			std::cin >> x;
			symbs.insert(x);
		}

		std::cin >> msg;
		std::vector<std::string> words;
		ini = 0;
		fin = 0;
		while (fin < msg.size()) {
			while (fin + 1 < msg.size() && msg[fin + 1] != '0') ++fin;

			words.push_back(msg.substr(ini, fin - ini + 1));
			if (fin + 1 != msg.size()) {
				ini = fin + 2;
				fin = ini;
			}
			else ++fin;
		}

		std::vector<long long int> vsol;
		for (int i = 0; i < words.size(); ++i) {
			memo = std::vector<long long int>(words[i].size(), -1);
			vsol.push_back(resolver(words[i], 0));
		}

		sol = vsol[0];
		for (int i = 1; i < words.size(); ++i) sol = (sol * vsol[i]) % MOD;
		std::cout << sol << '\n';

		std::cin >> N;
	}
	return 0;
}
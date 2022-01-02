#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

const ll MAX = 100000000000;

struct estado {
	ll del, favor, contra, indec;
};

int main() {
	ll n, del, favor, contra, indec, aux, tn, fn, cn, in, necesito, temp1, temp2, coste;
	cin >> n;
	while (std::cin) {
		tn = 0; fn = 0; cn = 0; in = 0;
		std::vector<estado> estIndec;

		for (int i = 0; i < n; ++i) {
			cin >> del >> favor >> contra >> indec;
			tn += del;

			aux = favor + contra + indec;

			aux /= 2;
			if (favor > aux) fn += del;
			else if (favor + indec <= aux) cn += del;
			else {
				in += del;
				estIndec.push_back({ del,favor,contra,indec });
			}
		}

		if (fn + in <= tn / 2) cout << "IMPOSIBLE\n";
		else if (fn > tn / 2) cout << "0\n";
		else {
			necesito = tn/2 - fn + 1;

			std::vector<std::vector<ll>> dp(necesito + 1, std::vector<ll>(estIndec.size() + 1, MAX));
			for (int j = 0; j <= estIndec.size(); ++j) dp[0][j] = 0;

			for (int j = 1; j <= estIndec.size(); ++j) {
				for (int i = 1; i <= necesito; ++i) {
					coste = (estIndec[j - 1].favor + estIndec[j - 1].contra + estIndec[j - 1].indec) / 2 - estIndec[j - 1].favor + 1;

					if (dp[std::max((ll)0,i - estIndec[j - 1].del)][j - 1] != MAX)
						temp1 = dp[std::max((ll)0,i - estIndec[j - 1].del)][j - 1] + coste;
					else temp1 = MAX;

					temp2 = dp[i][j - 1];

					dp[i][j] = std::min(temp1, temp2);
				}
			}

			cout << dp[necesito][estIndec.size()] << '\n';
		}

	cin >> n;
	}

return 0;
}
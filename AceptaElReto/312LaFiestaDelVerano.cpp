#include <iostream>
#include <vector>

using llint = long long int;

llint MCD(llint const& a, llint const& b) {
	if (a % b == 0) return b;
	return MCD(b, a % b);
}

int main() {
	llint x, mcd, mcd_ant, sol, factor;
	std::cin >> x;
	while (x != 0) {
		mcd = x;
		sol = 1;

		std::cin >> x;
		while (x != 0) {
			mcd_ant = mcd;
			mcd = MCD(mcd, x);
			if (mcd != mcd_ant) {
				factor = mcd_ant / mcd;
				sol = sol * factor;
			}
			sol += x / mcd;
			std::cin >> x;
		}

		std::cout << sol << '\n';
		std::cin >> x;
	}
return 0;
}
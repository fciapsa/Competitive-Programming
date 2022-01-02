#include <iostream>
#include <algorithm>


int main() {
	int nc;
	std::cin >> nc;

	int tot, A, B;
	for (int i = 0; i < nc; ++i) {
		std::cin >> tot >> A >> B;
		int soli = (tot / B) * A;

		if (tot % B != 0) soli += std::min(tot%B, A);
		std::cout << soli << '\n';
	}

return 0;
}
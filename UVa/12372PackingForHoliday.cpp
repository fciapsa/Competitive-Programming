#include <iostream>

int main() {
	int T, w, h, l, max, k = 1;
	std::cin >> T;
	while (T--) {
		std::cin >> w >> h >> l;
		if (w > h) {
			if (w > l) max = w;
			else max = l;
		}
		else if (h > l) max = h;
		else max = l;
		
		std::cout << "Case " << k << ": ";
		if (max > 20) std::cout << "bad\n";
		else std::cout << "good\n";

	++k;
	}
return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

struct tCiudad {
	int x, y;
	bool operator<(tCiudad const& other) const {
		return x > other.x || (x == other.x && y > other.y);
	}
};

int main() {
	int n, x, y;
	bool ok;
	std::cin >> n;
	while (n != 0) {
		std::vector<tCiudad> v(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> x >> y;
			v[i] = { x,y };
		}
		sort(v.begin(), v.end());
		ok = true;
		--n;
		for (int i = 0; i < n && ok; ++i) {
			ok = v[i].y > v[i + 1].y || (v[i].x == v[i + 1].x);
		}
		if (ok) std::cout << "SI\n";
		else std::cout << "NO\n";
	std::cin >> n;
	}
return 0;
}
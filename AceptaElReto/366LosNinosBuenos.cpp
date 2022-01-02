#include <iostream>
#include <vector>
#include <algorithm>

struct kid {
	int b, p;
};
struct tOrd {
	bool operator()(kid const& k1, kid const& k2) {
		return k1.b > k2.b || (k1.b == k2.b && k1.p < k2.p);
	}
};

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		std::vector<kid> v(n);
		for (int i = 0; i < n; ++i) std::cin >> v[i].b >> v[i].p;
		sort(v.begin(), v.end(),tOrd());
		for (int i = 0; i < n; ++i) {
			std::cout << v[i].b << ' ' << v[i].p << '\n';
		}
		std::cout << '\n';

	std::cin >> n;
	}
return 0;
}
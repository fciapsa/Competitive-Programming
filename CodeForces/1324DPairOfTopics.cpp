#include <iostream>
#include <vector>
#include <algorithm>

struct tTopic {
	long long int a, b, res1;
};

struct tOrd1 {
	bool operator()(tTopic const& t1, tTopic const& t2) {
		return t1.res1 > t2.res1;
	}
};

int main() {
	int n;
	std::cin >> n;
	std::vector<tTopic> v1(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> v1[i].a;
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> v1[i].b;
		v1[i].res1 = v1[i].a - v1[i].b;
	}

	sort(v1.begin(), v1.end(),tOrd1());
	std::vector<long long int> v2(n);
	for (int i = 0; i < n; ++i) v2[i] = -v1[i].res1;

	int i = 0, j = n-1;
	long long int  sol = 0;
	while (i < n) {
		while (j > i && v2[j] >= v1[i].res1) --j;
		if (j > i) sol += (j-i);
	++i;
	}
	std::cout << sol << '\n';
return 0;
}
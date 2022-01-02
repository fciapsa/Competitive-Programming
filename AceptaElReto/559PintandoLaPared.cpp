#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>//greater
#include <set>//multiset

struct punto {
	bool abre;
	long long int x,altura;
	bool operator<(punto const& other) const{
		return x < other.x;
	}
};

int main() {
	long long int a, n, x, y;
	long long int sol;
	std::cin >> a;
	while (a != 0) {
		sol = 0;
		std::cin >> n;
		std::vector<punto> v;
		for (int i = 0; i < n; ++i) {
			std::cin >> x >> y;
			v.push_back({ true,x,y });
			v.push_back({ false,x + a,y });
		}
		sort(v.begin(), v.end());

		std::multiset<long long int, std::greater<long long int>> alturas;
		alturas.insert(0);//altura por defecto
		alturas.insert(v[0].altura);
		for (int i = 1; i < v.size(); ++i) {
			sol += (v[i].x - v[i - 1].x) * (*alturas.begin());
			if (v[i].abre) alturas.insert(v[i].altura);
			else alturas.erase(alturas.find(v[i].altura));
		}

		std::cout << sol << '\n';
	std::cin >> a;
	}
return 0;
}
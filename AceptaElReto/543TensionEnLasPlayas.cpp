#include <iostream>
#include <vector>

struct tSombrilla {
	int x, y, r;
};

struct tOrd {
	bool operator()(tSombrilla const& s1, tSombrilla const& s2) {
		return s1.y < s2.y || (s1.y == s2.y && s1.x < s2.x);
	}
};

void resuelve() {
	int n;
	std::cin >> n;

	std::vector<tSombrilla> v(n);
	long long int difx, dify, cont = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i].x >> v[i].y >> v[i].r;

		for (int j = 0; j < i; ++j) {
			difx = v[j].x - v[i].x;
			dify = v[j].y - v[i].y;

			if (difx * difx + dify * dify < (v[i].r + v[j].r) * (v[i].r + v[j].r)) ++cont;
		}
	}

	std::cout << cont << '\n';
}

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) resuelve();
	return 0;
}
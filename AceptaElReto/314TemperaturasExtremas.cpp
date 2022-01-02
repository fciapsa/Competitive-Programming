#include <iostream>
#include <vector>

int numPicos(std::vector<int> const& v) {
	int np = 0, i = 1;
	while (i < v.size() - 1) {
		if (v[i - 1] < v[i] && v[i] > v[i + 1]) ++np;
	++i;
	}

return np;
}

int numValles(std::vector<int> const& v) {
	int nv = 0, i = 1;
	while (i < v.size() - 1) {
		if (v[i - 1] > v[i] && v[i] < v[i + 1]) ++nv;
	++i;
	}

return nv;
}

void resuelveCaso() {
	int N;
	std::cin >> N;
	std::vector<int> v(N);
	for (int i = 0; i < v.size(); ++i) {
		std::cin >> v[i];
	}
	std::cout << numPicos(v) << ' ' << numValles(v) << '\n';
}

int main() {
	int nCasos;
	std::cin >> nCasos;
	for (int i = 0; i < nCasos; ++i) {
		resuelveCaso();
	}
return 0;
}
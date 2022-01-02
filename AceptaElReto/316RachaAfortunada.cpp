#include <iostream>
#include <vector>

void resuelveCaso() {
	long int d;
	std::cin >> d;
	std::vector<long int> v(d);
	std::cin >> v[0];

	long int r = v[0], s = v[0], p = 1, q = 1, pf = 1, qf = 1;

	for (long int i = 1; i < v.size(); ++i) {
		std::cin >> v[i];
		if (v[i] >= s + v[i]) {
			s = v[i];
			p = i+1;
			q = i+1;
			if (s > r) {
				r = s;
				pf = i+1;
				qf = i+1;
			}
			else if (s == r && qf - pf > 0) {
				r = s;
				pf = i+1;
				qf = i+1;
			}
		}
		else{
			s += v[i];
			++q;
			if (s > r) {
				r = s;
				qf = q;
				pf = p;
			}
			else if (s == r && qf - pf > q - p) {
				r = s;
				qf = q;
				pf = p;
			}
		}
	}
	std::cout << pf << ' ' << qf << '\n';
}

int main() {
	int nCasos;
	std::cin >> nCasos;
	for (int i = 0; i < nCasos; ++i) {
		resuelveCaso();
	}
return 0;
}
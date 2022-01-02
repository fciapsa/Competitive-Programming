#include <iostream>
#include <algorithm>
#include <vector>

struct tOp {
	int col;
	int ini;
	int fin;
	int val;
};

bool operator <(tOp const& op1, tOp const& op2) {
	return op1.ini < op2.ini || (op1.ini == op2.ini && op1.col < op2.col);
}
struct ordFin {
	bool operator()(tOp const& op1, tOp const& op2) {
		return op1.fin < op2.fin || (op1.fin == op2.fin && op1.col < op2.col);
	}
};

bool resuelve() {
	int F, C, N;
	std::cin >> F >> C >> N;

	if (F == 0 && C == 0 && N == 0) return false;

	std::vector<tOp> v(N);

	for (int k = 0; k < N; ++k) {
		std::cin >> v[k].col >> v[k].ini >> v[k].fin >> v[k].val;
	}

	std::vector<tOp> aux = v;
	sort(v.begin(), v.end());
	sort(aux.begin(), aux.end(), ordFin());

	int p = 0, q = 0;
	std::vector<long long int> acts(C,0);

	int i = 0, j;
	while(i < F) {
		while(p < N && v[p].col == 0 && v[p].ini == i) {
			acts[0] += v[p].val;
			++p;
		}
		while(q <= p && q < N && aux[q].col == 0 && aux[q].fin < i) {
			acts[0] -= aux[q].val;
			++q;
		}
		std::cout << acts[0];

		j = 1;
		while(j < C) {
			while (p < N && v[p].col == j && v[p].ini == i) {
				acts[j] += v[p].val;
				++p;
			}
			while (q <= p && q < N && aux[q].col == j && aux[q].fin < i) {
				acts[j] -= aux[q].val;
				++q;
			}
			std::cout << ' ' << acts[j];
			++j;
		}

		std::cout << '\n';
		++i;
	}

return true;
}

int main() {
	while (resuelve());
return 0;
}
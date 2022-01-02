#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
int nc;
std::cin >> nc;

int n, cap, tam;
for (int i = 0; i < nc; ++i) {
	std::unordered_set<int> conj;

	std::cin >> n >> cap;
	std::vector<int> v(n);
	std::vector<int> sumas, sumas_aux;
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
		conj.insert(v[i]);
	}

	sumas_aux = v;
	for (int i = 1; i < cap; ++i) {
		sumas = sumas_aux;
		sumas_aux.clear();
		tam = sumas.size();
		for (int j = 0; j < tam; ++j) {
			for (int k = 0; k < n; ++k) {
				auto par = conj.insert(sumas[j] + v[k]);
				if (par.second) {
					sumas_aux.push_back(sumas[j] + v[k]);
				}
			}
		}
	}

	std::cout << conj.size() << '\n';
}

return 0;
}
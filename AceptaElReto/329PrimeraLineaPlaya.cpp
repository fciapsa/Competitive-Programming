//Flavius Abel Ciapsa

#include <iostream>
#include <vector>
#include <algorithm>

struct tRango {
	int a, b;
};

struct tMenor{
	bool operator()(tRango const& r1, tRango const& r2) {
		return r1.a < r2.a || (r1.a == r2.a && r1.b < r2.b);
	}
};

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::vector<tRango> v(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> v[i].a >> v[i].b;
	}

	sort(v.begin(), v.end(), tMenor());
	int grupos = 1, tope = v[0].b;
	//La idea es agrupar todos los edificios que comiencen antes de que el primero del grupo acabe
	//MAL: Faltaba considerar que hay que actualizar el punto final ya que pueden unirse al grupo edificios que acaben antes
	int i = 1;
	while(i < N) {
		while (i < N && v[i].a < tope) {
			tope = std::min(tope, v[i].b);
			++i;
		}
		if (i < N) {
			++grupos;
			tope = v[i].b;
		}
	}

	std::cout << grupos << '\n';

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}
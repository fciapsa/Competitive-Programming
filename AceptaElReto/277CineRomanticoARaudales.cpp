#include <iostream>
#include <vector>
#include <algorithm>

struct tPelicula {
	int inicio, duracion, libera, pos, sig;
};

struct tOrd {
	bool operator()(tPelicula const& p1, tPelicula const& p2) {
		return p1.inicio < p2.inicio;
	}
};

struct tOrd2 {
	bool operator()(tPelicula const& p1, tPelicula const& p2) {
		return p1.libera < p2.libera;
	}
};

int maxTiempo(std::vector<tPelicula> const& pelis) {
	int N = pelis.size();
	std::vector<int> maxTiempo(N);
	//caso base
	maxTiempo[N - 1] = pelis[N - 1].duracion;

	for (int i = N-2; i >= 0; --i) {
		if (pelis[i].sig != -1) {
			maxTiempo[i] = std::max(pelis[i].duracion + maxTiempo[pelis[i].sig], maxTiempo[i + 1]);
		}
		else maxTiempo[i] = std::max(pelis[i].duracion, maxTiempo[i + 1]);
	}

return maxTiempo[0];
}

int main() {
	int N, hh, mm, d;
	char aux;
	std::cin >> N;
	while (N != 0) {
		std::vector<tPelicula> pelis, pelis_aux;
		for (int i = 0; i < N; ++i) {
			std::cin >> hh >> aux >> mm >> d;
			pelis.push_back({ 60 * hh + mm, d,-1,-1,-1});
		}

		sort(pelis.begin(), pelis.end(), tOrd());
		for (int i = 0; i < N; ++i) {
			pelis[i].pos = i;
			pelis[i].libera = pelis[i].inicio + pelis[i].duracion + 10;
		}

		pelis_aux = pelis;
		//calculamos para cada pelicula, la siguiente accesible una vez acabada
		sort(pelis_aux.begin(), pelis_aux.end(), tOrd2());
		int j = 0;
		for (int i = 0; i < N && j < N; ++i) {
			while (j < N && pelis_aux[i].libera > pelis[j].inicio) ++j;

			if (j < N) pelis[pelis_aux[i].pos].sig = j;
		}

		std::cout << maxTiempo(pelis) << '\n';

	std::cin >> N;
	}
return 0;
}
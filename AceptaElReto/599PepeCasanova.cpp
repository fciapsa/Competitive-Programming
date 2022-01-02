#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

struct tCancion {
	double tiempo, punt, q;
	bool operator<(tCancion const& other) const {
		return q > other.q;
	}
};

struct tNodo {
	int k, punt, punt_opt, c1, c2;
	bool operator<(tNodo const& other) const {
		return punt_opt < other.punt_opt;
	}
};

long long int calculoPesimista(std::vector<tCancion> const& canciones, int c1, int c2, int k, int N) {
	long long int ret = 0;
	for (int i = k + 1; i < N; ++i) {
		if (canciones[i].tiempo <= c1) {
			ret += canciones[i].punt;
			c1 -= canciones[i].tiempo;
		}
		else if (canciones[i].tiempo <= c2) {
			ret += canciones[i].punt;
			c2 -= canciones[i].tiempo;
		}
	}

	return ret;
}

long long int calculoOptimista(std::vector<tCancion> const& canciones, int c1, int c2, int k, int N) {
	long long int ret = 0;
	bool stop = false;
	for (int i = k + 1; i < N && !stop; ++i) {
		if (canciones[i].tiempo <= c1) {
			ret += canciones[i].punt;
			c1 -= canciones[i].tiempo;
		}
		else if (canciones[i].tiempo <= c2) {
			ret += canciones[i].punt;
			c2 -= canciones[i].tiempo;
		}
		else {
			ret += std::ceil((c1 + c2) * canciones[i].q);
			stop = true;
		}
	}

	return ret;
}

long long int cancionesMaxPuntRP(std::vector<tCancion> const& canciones, int tiempo_cara, int N) {
	long long int max_punt = calculoPesimista(canciones, tiempo_cara, tiempo_cara, -1, N);

	tNodo padre = { -1,0, 0,tiempo_cara,tiempo_cara }, hijo;
	padre.punt_opt = calculoOptimista(canciones, tiempo_cara, tiempo_cara, -1, N);
	std::priority_queue<tNodo> pq;
	pq.push(padre);
	while (!pq.empty() && pq.top().punt_opt > max_punt) {
		padre = pq.top();
		pq.pop();

		hijo = padre;
		++hijo.k;
		//probamos a grabarla en la primera cara de la cinta
		if (canciones[hijo.k].tiempo <= padre.c1) { //si entra, sus cotas coinciden con las del padre
			hijo.punt += canciones[hijo.k].punt;
			hijo.c1 -= canciones[hijo.k].tiempo;

			if (hijo.k == N - 1) max_punt = hijo.punt;
			else {
				max_punt = std::max(max_punt, hijo.punt + calculoPesimista(canciones, hijo.c1, hijo.c2, hijo.k, N));
				pq.push(hijo);
			}
		}
		//probamos a grabarla en la segunda cara de la cinta
		if (canciones[hijo.k].tiempo <= padre.c2) {
			hijo.punt = padre.punt + canciones[hijo.k].punt;
			hijo.c1 = padre.c1;
			hijo.c2 = padre.c2 - canciones[hijo.k].tiempo;

			if (hijo.k == N - 1) {
				if (hijo.punt > max_punt) max_punt = hijo.punt;
			}
			else {
				hijo.punt_opt = hijo.punt + calculoOptimista(canciones, hijo.c1, hijo.c2, hijo.k, N);
				pq.push(hijo);
				max_punt = std::max(max_punt, hijo.punt + calculoPesimista(canciones, hijo.c1, hijo.c2, hijo.k, N));
			}
		}
		//no grabar la cancion
		hijo.punt = padre.punt;
		hijo.c1 = padre.c1;
		hijo.c2 = padre.c2;
		if (hijo.k == N - 1) {
			if (hijo.punt > max_punt) max_punt = hijo.punt;
		}
		else {
			hijo.punt_opt = hijo.punt + calculoOptimista(canciones, hijo.c1, hijo.c2, hijo.k, N);
			pq.push(hijo);
			max_punt = std::max(max_punt, hijo.punt + calculoPesimista(canciones, hijo.c1, hijo.c2, hijo.k, N));
		}

	}

	return max_punt;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	int tiempo_cara;
	std::cin >> tiempo_cara;

	std::vector<tCancion> canciones(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> canciones[i].tiempo >> canciones[i].punt;
		canciones[i].q = canciones[i].punt / canciones[i].tiempo;
	}
	sort(canciones.begin(), canciones.end());//para poder aplicar estrategia voraz en la cota optimista

	std::cout << cancionesMaxPuntRP(canciones, tiempo_cara, N) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
#include <iostream>
#include <vector>
#include <deque>

struct tTrozo {
	int cont;//cuantos elementos de la secuencia de la clave he visto ya 
	int ini;//guarda el indice en el que empieza
};

bool resuelveCaso() {
	int R, N;//tamano de la clave y tamano del mensaje
	std::cin >> R >> N;

	if (!std::cin) return false;

	std::vector<int> clave(R);
	for (int i = 0; i < R; ++i)std::cin >> clave[i];

	int sol = N;//lleva el tamano minimo de la secuencia que contiene la clave
	std::deque<tTrozo> trozos;
	int aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		if (aux == clave[0]) {//inicia una nueva secuencia(no puede ser otra cosa, la clave no tiene repetidos)
			//quito la secuencia que haya empezado antes pero no ha avanzado mas
			while (!trozos.empty() && trozos.back().cont == 1) trozos.pop_back();
			trozos.push_back({ 1,i });
		}
		else {
			int k = trozos.size();
			for (int j = 0; j < k; ++j) {
				tTrozo act = trozos.front();
				trozos.pop_front();
				if (aux == clave[act.cont]) ++act.cont;//he encontrado el siguiente de la clave

				if (act.cont == R) {
					if (i - act.ini + 1 < sol) sol = i - act.ini + 1;//si la encuentro entera y es mas corta
				}
				else {
					//quitar las secuencias que han empezado antes pero no han avanzado mas
					while (!trozos.empty() && trozos.back().cont <= act.cont && trozos.back().ini < act.ini) {
						trozos.pop_back();
						--k;
					}
					if (i - act.ini + 1 < sol) trozos.push_back(act);
				}
			}
		}
	}

	std::cout << sol << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
return 0;
}
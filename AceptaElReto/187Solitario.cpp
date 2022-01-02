#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>

enum tPalo {OROS, COPAS, ESPADAS,BASTOS};
enum tNumero{AS,DOS,TRES,CUATRO,CINCO,SEIS,SIETE,SOTA,CABALLO,REY};

struct tCarta {
	tPalo palo;
	tNumero num;
};

std::istream& operator >>(std::istream& in, tCarta &card) {
	int x; char c;
	in >> x >> c;
	switch (x) {
	case 1:card.num = AS; break;
	case 2:card.num = DOS; break;
	case 3:card.num = TRES; break;
	case 4:card.num = CUATRO; break;
	case 5:card.num = CINCO; break;
	case 6:card.num = SEIS; break;
	case 7:card.num = SIETE; break;
	case 10:card.num = SOTA; break;
	case 11:card.num = CABALLO; break;
	case 12:card.num = REY; break;
	}

	switch (c) {
	case 'O': card.palo = OROS; break;
	case 'C': card.palo = COPAS; break;
	case 'E': card.palo = ESPADAS; break;
	case 'B': card.palo = BASTOS; break;
	}

	return in;
}

bool resuelveCaso() {
	int N;//numero de palos
	std::cin >> N;

	if (N == 0) return false;

	N *= 10;//lo paso a numero de cartas total
	std::deque<tCarta> monton;
	tCarta aux;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		monton.push_back(aux);//tras leer, la primera carta a coger es la de front
	}


	std::stack<tNumero> oro, copa, espada, basto;
	std::deque<tCarta> visibles;
	bool colocadoAlguna = true;

	while (colocadoAlguna && !monton.empty()) {
		colocadoAlguna = false;

		while (!monton.empty()) {

			int saco = std::min(2, int(monton.size()));
			for (int i = 0; i < saco; ++i) {
				visibles.push_front(monton.front());
				monton.pop_front();
			}//saco dos o una del monton y las pongo visibles en front
			
			bool colocar_aux = true;
			while (colocar_aux && !visibles.empty()) {
				colocar_aux = false;

				if (visibles.front().palo == OROS && (visibles.front().num == AS || (!oro.empty() && oro.top() == visibles.front().num - 1))) {
					oro.push(visibles.front().num);
					visibles.pop_front();
					colocar_aux = true;
					colocadoAlguna = true;
				}
				else if (visibles.front().palo == COPAS && (visibles.front().num == AS || (!copa.empty() && copa.top() == visibles.front().num - 1))) {
					copa.push(visibles.front().num);
					visibles.pop_front();
					colocar_aux = true;
					colocadoAlguna = true;
				}
				else if (visibles.front().palo == ESPADAS && (visibles.front().num == AS || (!espada.empty() && espada.top() == visibles.front().num - 1))) {
					espada.push(visibles.front().num);
					visibles.pop_front();
					colocar_aux = true;
					colocadoAlguna = true;
				}
				else if (visibles.front().palo == BASTOS && (visibles.front().num == AS || (!basto.empty() && basto.top() == visibles.front().num - 1))) {
					basto.push(visibles.front().num);
					visibles.pop_front();
					colocar_aux = true;
					colocadoAlguna = true;
				}
			}//mientras se pueda colocar alguna de las visibles


		}//mientras pueda hacer mas visibles

		while (!visibles.empty()) {//doy la vuelta a las visibles
			monton.push_front(visibles.front());
			visibles.pop_front();
		}

	}//mientras no este vacio y haya colocado alguna en ese ciclo entero

	if (monton.empty()) std::cout << "GANA\n";
	else std::cout << "PIERDE\n";

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}
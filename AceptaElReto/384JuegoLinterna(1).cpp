#include <iostream>
#include <algorithm>
#include <stack>

bool resuelveCaso() {
	int n;
	std::cin >> n;

	if (!std::cin) return false;

	bool lose = false;//evalua a true si se da una situacion perdedora
	std::stack<int> pila;
	int minGlobal , max_act;
	int aux;//ultimo valor leido

	//Trato el primero aparte
	std::cin >> aux;
	minGlobal = aux;
	max_act = aux;
	pila.push(minGlobal);

	int i = 1;
	while(i < n && !lose) {
		std::cin >> aux;
		if (aux < minGlobal) {
			pila.push(max_act);//cierro rango anterior
			pila.push(aux);//inicio nuevo rango
			minGlobal = aux;
			max_act = aux;
		}
		else { //Comprobar los rangos
			int aux_min = pila.top();
			pila.pop();
			while(!pila.empty() && aux > max_act) {
				aux_min = pila.top();
				pila.pop();
			}

		}
		if (aux > max_act) max_act = aux;

		++i;
	}
	//Consumir la entrada que sobre
	while (i < n) {
		std::cin >> aux;
		++i;
	}


	for (int i = c + 1; i < n && !lose; ++i) {
		bool mirar = true;
		for (int j = ranges.size() - 1; j > 0 && !lose && mirar; j = j - 2) {
			mirar = v[i] > v[ranges[j - 1]];
			if (mirar && v[i] < v[ranges[j]]) lose = true;
		}
	}

	if (lose) std::cout << "ELEGIR OTRA\n";
	else std::cout << "SIEMPRE PREMIO\n";

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}
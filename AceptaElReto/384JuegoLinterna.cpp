#include <iostream>
#include <stack>

bool resuelveCaso() {
	int n;
	std::cin >> n;

	if (!std::cin) return false;

	bool lose = false;//evalua a true si se da una situacion perdedora
	std::stack<int> pila;
	int minGlobal, max_act;
	int aux;//ultimo valor leido

	//Trato el primero aparte para inicializar
	std::cin >> aux;
	minGlobal = aux;
	max_act = aux;
	pila.push(minGlobal);
	pila.push(max_act);

	int i = 1;
	while (i < n && !lose) {
		std::cin >> aux;
		if (aux < minGlobal) {
			minGlobal = aux;
			max_act = aux;
			pila.push(minGlobal);//nuevo rango
			pila.push(max_act);
		}
		else { //Comprobar los rangos

		    //Mientras sea mayor que el maximo de los rangos anteriores los deshago
			while (!pila.empty() && aux > pila.top()) {
				pila.pop();
				pila.pop();
			}
			if (!pila.empty()) {
				int save = pila.top();//es menor que este
				pila.pop();
				if (aux > pila.top()) lose = true;
				else {//unificar todos los que he deshecho recuperando el actual
					pila.push(save);
					pila.push(minGlobal);
					if(aux > max_act)pila.push(aux);
					else pila.push(max_act);
				}
			}
			else {//si entro aqui es que los he desecho todos y los unifico
				pila.push(minGlobal);
				pila.push(aux);
			}
		}

		++i;
	}
	//Consumir la entrada que sobra
	while (i < n) {
		std::cin >> aux;
		++i;
	}

	if (lose) std::cout << "ELEGIR OTRA\n";
	else std::cout << "SIEMPRE PREMIO\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
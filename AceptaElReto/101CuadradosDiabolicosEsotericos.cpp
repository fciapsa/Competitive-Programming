#include <iostream>
#include <vector>

bool resuelve() {
	int n;
	std::cin >> n;

	if (n == 0) return false;
	
	if (n == 1) {
		long long int aux;
		std::cin >> aux;
		if (aux == 1) std::cout << "ESOTERICO\n";
		else std::cout << "DIABOLICO\n";
	}
	else {
		bool par = n % 2 == 0;
		long long int tam = n * n;
		std::vector<bool> cifras(tam, false);
		bool todos = true;
		long long int CM = 0, CM2, esquinas = 0, centros = 0, centrosLados = 0;
		bool diabolico = true;

		long long int fila_act = 0, aux, diag1 = 0, diag2 = 0;
		std::vector<long long int> columnas(n, 0);
		for (int i = 0; i < n; ++i) {
			std::cin >> aux;
			//estan todas las cifras
			if (aux <= tam && cifras[aux - 1]) todos = false;
			else if (aux <= tam) cifras[aux - 1] = true;
			else todos = false;
			//recuento de la fila
			fila_act += aux;
			//recuento de las columnas
			columnas[i] += aux;
			//diagonal 1
			if (i == 0) diag1 += aux;
			//diagonal 2
			if (i == n - 1) diag2 += aux;
			//esquinas
			if (i == 0 || i == n - 1) esquinas += aux;
			//centrosLados
			if (par && i == (n / 2) - 1 || i == n / 2)centrosLados += aux;
			else if (!par && i == n / 2) centrosLados += aux;
			//centros
			if (n == 1 || n == 2) centros += aux;
		}
		CM = fila_act;//obtenemos la constante magica
		CM2 = (4 * CM) / n;

		int i = 1, j;
		while (i < n && diabolico) {
			fila_act = 0;

			j = 0;
			while (j < n) {
				std::cin >> aux;
				//estan todas las cifras
				if (aux <= tam && cifras[aux - 1]) todos = false;
				else if (aux <= tam) cifras[aux - 1] = true;
				else todos = false;
				//recuento fila
				fila_act += aux;
				//recuento columnas
				columnas[j] += aux;
				if (columnas[j] > CM) diabolico = false;
				//diagonal 1
				if (i == j) diag1 += aux;
				//diagonal 2
				if (j == n - i - 1) diag2 += aux;
				//esquinas
				if (i == n - 1 && (j == 0 || j == n - 1)) esquinas += aux;
				//centrosLados
				if (par && (j == 0 || j == n - 1) && (i == (n / 2) - 1 || i == n / 2)) centrosLados += aux;
				if (par && i == n - 1 && (j == (n / 2) - 1 || j == n / 2)) centrosLados += aux;

				if (!par && (j == 0 || j == n - 1) && i == n / 2) centrosLados += aux;
				if (!par && i == n - 1 && j == n / 2) centrosLados += aux;
				//centros
				if (par && (j == (n / 2) - 1 || j == n / 2) && (i == (n / 2) - 1 || i == n / 2)) centros += aux;
				if (!par && i == n / 2 && j == n / 2) centros += aux;

				++j;
			}
			if (fila_act != CM || diag1 > CM || diag2 > CM) diabolico = false;
			++i;
		}
		//SI NO ES DIABOLICO, CONSUMIMOS LA ENTRADA
		while (i < n) {
			j = 0;
			while (j < n) {
				std::cin >> aux;
				++j;
			}
			++i;
		}
		//comprobar columnas y diagonales
		diabolico = diabolico && diag1 == CM && diag2 == CM;
		for (int i = 0; i < n && diabolico; ++i) {
			diabolico = columnas[i] == CM;
		}

		if (!diabolico) std::cout << "NO\n";
		else {
			if (!todos) std::cout << "DIABOLICO\n";
			else {
				if (par) {
					if (esquinas == CM2 && centrosLados == 2 * CM2 && centros == CM2) std::cout << "ESOTERICO\n";
					else std::cout << "DIABOLICO\n";
				}
				else {
					if (esquinas == CM2 && centrosLados == CM2 && 4 * centros == CM2) std::cout << "ESOTERICO\n";
					else std::cout << "DIABOLICO\n";
				}
			}
		}
	}

return true;
}

int main() {
	while (resuelve());
return 0;
}
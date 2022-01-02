#include <iostream>
#include <vector>

void merge(std::vector<int> &v, int c, int m, int f, long long int &cont) {
	int n1 = m - c;
	int n2 = f - m;

	std::vector<int> aux1(n1), aux2(n2);
	for (int i = 0; i < n1; ++i) {
		aux1[i] = v[c + i];
	}
	for (int i = 0; i < n2; ++i) {
		aux2[i] = v[m + i];
	}

	int i = 0, j = 0, k = c;
	while (i < n1 && j < n2) {
		if (aux1[i] <= aux2[j]) {
			v[k] = aux1[i];
			++i;
		}
		else {
			cont += n1-i;
			v[k] = aux2[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		v[k] = aux1[i];
		++i;
		++k;
	}
	while (j < n2) {
		v[k] = aux2[j];
		++j;
		++k;
	}
}

void mergeSort(std::vector<int> &v, int c, int f, long long int &cont) {
	if (f - c > 1) {
		int m = (c+f) / 2;
	    mergeSort(v, c, m,cont);
		mergeSort(v, m, f,cont);

		merge(v, c, m, f,cont);
	}
}

int main() {
	int n;
	std::cin >> n;

	while (n != 0) {
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> v[i];
		}
		long long int cont = 0;
		mergeSort(v, 0, n, cont);
		std::cout << cont << '\n';
	std::cin >> n;
	}
return 0;
}
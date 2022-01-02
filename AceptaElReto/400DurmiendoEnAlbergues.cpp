#include <iostream>
#include <string>

int main() {
	int i, j, cont, max, aux;
	std::string s;
	std::cin >> s;
	while (std::cin) {
		i = 0;
		j = s.size() - 1;
		cont = 0;

		while (i < j && s[i] == '.') ++i;
		max = i - 1;
		while (j > i && s[j] == '.') {
			--j;
			++cont;
		}
		if (cont - 1 > max) max = cont - 1;

		while (i < j) {
			while (i < j && s[i] == 'X') ++i;
			
			cont = 0;
			while (i < j && s[i] == '.') {
				++i;
				++cont;
			}

			if (cont % 2 == 0) aux = cont / 2 - 1;
			else aux = cont / 2;

			if (aux > max) max = aux;
		}
		
		std::cout << max << '\n';


	std::cin >> s;
	}

return 0;
}
#include <iostream>
#include <vector>

const std::vector<int> encender = { 6,2,5,5,4,5,6,3,7,6 };
const std::vector<std::vector<int>> cambios = {
	{0,4,3,3,4,3,2,3,1,2},
    {4,0,5,3,2,5,6,1,5,4},
    {3,5,0,2,5,4,3,4,2,3},
    {3,3,2,0,3,2,3,2,2,1},
    {4,2,5,3,0,3,4,3,3,2},
    {3,5,4,2,3,0,1,4,2,1},
    {2,6,3,3,4,1,0,5,1,2},
    {3,1,4,2,3,4,5,0,4,3},
    {1,5,2,2,3,2,1,4,0,1},
    {2,4,3,1,2,1,2,3,1,0}
};

int main() {
	int x, ant, tam, sol;
	std::cin >> x;
	while (x != -1) {
		sol = encender[x];
		ant = x;
		tam = 1;
		std::cin >> x;
		while (x != -1) {
			++tam;
			sol += cambios[ant][x];

			ant = x;
			std::cin >> x;
		}
		sol += encender[ant];

		std::cout << tam*sol << '\n';

	std::cin >> x;
	}

return 0;
}
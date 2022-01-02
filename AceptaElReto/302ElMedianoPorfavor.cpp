#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int main() {
	int N, op, mediana, esperando;
	bool first;
	std::cin >> N;
	while (std::cin) {
		mediana = -1;
		esperando = 0;
		first = true;
		std::priority_queue<int, std::vector<int>, std::greater<int>> mayores;
		std::priority_queue<int> menores;
		for (int i = 0; i < N; ++i) {
			std::cin >> op;
			if (op == 0) {
				if (esperando > 0) {
					if (first) {
						std::cout << mediana;
						first = false;
					}
					else std::cout << ' ' << mediana;
					--esperando;
					if (mayores.size() > 0 || menores.size() > 0) {
						if (esperando % 2 == 0) {
							mediana = menores.top();
							menores.pop();
						}
						else {
							mediana = mayores.top();
							mayores.pop();
						}
					}
					else mediana = -1;
				}
				else {
					if (first) {
						std::cout << "ECSA";
						first = false;
					}
					else std::cout << " ECSA";
				}
			}
			else {
				if (mediana == -1) {
					mediana = op;
					++esperando;
				}
				else {
					++esperando;
					if (esperando % 2 == 0) {
						if (op > mediana) mayores.push(op);
						else {
							menores.push(op);
							mayores.push(mediana);
							mediana = menores.top();
							menores.pop();
						}
					}
					else {
						if (op < mediana) menores.push(op);
						else {
							mayores.push(op);
							menores.push(mediana);
							mediana = mayores.top();
							mayores.pop();
						}
					}
				}
			}
		}
		std::cout << '\n';
	std::cin >> N;
	}
return 0;
}
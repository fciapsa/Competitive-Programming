#include <iostream>

void resuelve() {
	int pisos, escalones, pc, ec;
	std::cin >> pisos >> escalones >> pc >> ec;

	std::cout << pc * escalones + ec << ' ' << pisos * escalones + pc * escalones + ec << '\n';
}

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) resuelve();
	return 0;
}
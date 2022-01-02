#include <iostream>
#include <set>

struct tTipo {
	int piso;
	char letra;
};

bool operator==(tTipo const& t1, tTipo const& t2) {
	return t1.piso == t2.piso && t1.letra == t2.letra;
}

bool operator<(tTipo const& t1, tTipo const& t2) {
	return t1.piso < t2.piso || (t1.piso == t2.piso && t1.letra < t2.letra);
}

int main() {
	int P, L, A;
	std::cin >> P >> L >> A;

	int aux; char auxc;
	while (P != 0 || L != 0 || A != 0) {
		int necesarios = P * L;
		if ((P * L) % 2 != 0) ++necesarios;
		necesarios /= 2;

		std::set<tTipo> conj;
		for (int i = 0; i < A; ++i) {
			std::cin >> aux >> auxc;
			if (conj.count({ aux,auxc }) == 0) conj.insert({ aux,auxc });
		}

		if (conj.size() >= necesarios) std::cout << "EMPEZAMOS\n";
		else std::cout << "ESPERAMOS\n";

		std::cin >> P >> L >> A;
	}

return 0;
}
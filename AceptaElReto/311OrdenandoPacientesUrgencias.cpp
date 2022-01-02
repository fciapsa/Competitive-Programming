#include <iostream>
#include <string>
#include <queue>

struct tDatos {
	std::string nombre;
	int gravedad, pos;
};

struct tComp {
	bool operator()(tDatos const& d1, tDatos const& d2) {
		return d1.gravedad < d2.gravedad || (d1.gravedad == d2.gravedad && d1.pos > d2.pos);
	}
};

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::priority_queue<tDatos, std::vector<tDatos>, tComp> cola;
	std::string nomb; int grav;
	char op;
	for (int i = 0; i < N; ++i) {
		std::cin >> op;
		if (op == 'I') {
			std::cin >> nomb >> grav;
			cola.push({ nomb,grav,i });
		}
		else {
			std::cout << cola.top().nombre << '\n';
			cola.pop();
		}
	}

	std::cout << "----\n";
return true;
}

int main() {
	while (resuelveCaso());
return 0;
}
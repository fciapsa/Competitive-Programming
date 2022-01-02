#include <iostream>
#include <queue>

struct tDatos {
	int id, freq, next;
};

struct tComp {
	bool operator()(tDatos const& d1, tDatos const& d2) {
		return d1.next > d2.next || (d1.next == d2.next && d1.id > d2.id);
	}
};

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::priority_queue<tDatos, std::vector<tDatos>, tComp> cola;
	int id, freq;
	for (int i = 0; i < N; ++i) {
		std::cin >> id >> freq;
		cola.push({ id,freq,freq });
	}

	int K;
	std::cin >> K;

	tDatos aux;;
	while (K > 0) {
		aux = cola.top();
		cola.pop();
		std::cout << aux.id << '\n';
		cola.push({ aux.id, aux.freq, aux.next + aux.freq });
		--K;
	}

	std::cout << "----\n";
return true;
}

int main() {
	while (resuelveCaso());
return 0;
}
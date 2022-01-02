#include <iostream>
#include <vector>

struct semaforo {
	long long int pos, open, closed, mod;
};

int main() {
	long long int N, nc, na, pos, open, closed, end, max, arrive, cociente;
	double speed, time;
	bool ok;
	std::cin >> N >> max;
	while (N != 0 || max != 0) {
		ok = true;
		std::vector<semaforo> v;
		std::cin >> pos >> closed >> open;
		v.push_back({ pos,open,closed, open + closed });
		if (open == 0) ok = false;
		for (int i = 1; i < N; ++i) {
			std::cin >> pos >> closed >> open;
			v.push_back({ v[i - 1].pos + pos,open,closed, open + closed });
			if (open == 0) ok = false;
		}

		if (!ok) std::cout << "IMPOSIBLE\n";
		else {
			end = v[N - 1].pos;

			nc = 1;
			na = 0;
			ok = false;
			arrive = v[N - 1].closed;
			speed = (double)end / arrive;
			while (speed > max && speed >= 0.1) {
				if (nc > na) {
					++na;
					arrive += v[N - 1].open;
				}
				else {
					++nc;
					arrive += v[N - 1].closed;
				}
				speed = (double)end / arrive;
			}

			if (speed < 0.1) std::cout << "IMPOSIBLE\n";
			else {
				while (!ok && speed >= 0.1) {
					ok = true;
					for (int i = 0; i < N - 1 && ok; ++i) {
						time = (double)(v[i].pos * arrive) / end;
						cociente = time / v[i].mod;
						if (time - cociente * v[i].mod < v[i].closed - 0.01 &&
							time - cociente * v[i].mod > 0.01) ok = false;

					}

					//proxima velocidad
					if (!ok) {
						if (nc > na) {
							++na;
							arrive += v[N - 1].open;
						}
						else {
							++nc;
							arrive += v[N - 1].closed;
						}
						speed = (double)end / arrive;
					}
				}
				if (!ok || speed < 0.1) std::cout << "IMPOSIBLE\n";
				else std::cout << end / speed << '\n';
			}
		}
		std::cin >> N >> max;
	}
	return 0;
}
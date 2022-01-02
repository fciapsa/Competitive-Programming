#include <iostream>

int main() {
	long double dist, v_max, t;
	std::cin >> dist >> v_max >> t;
	while (dist != 0 || v_max != 0 || t != 0) {
		if (dist <= 0 || v_max <= 0 || t <= 0) std::cout << "ERROR\n";
		else {
			v_max *= 1000;//pasarlo a m/h
			dist *= 3600;//para que dist/t ahora represente m/h en vez de m/s
			v_max *= t;//para que tengan el mismo denominador
			if (dist <= v_max) std::cout << "OK\n";
			else if (dist < (v_max / 100) * 120) std::cout << "MULTA\n";
			else std::cout << "PUNTOS\n";
		}
	std::cin >> dist >> v_max >> t;
	}
return 0;
}
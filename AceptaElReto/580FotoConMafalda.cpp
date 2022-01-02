#include <iostream>
#include <vector>
#include <queue>
#include <string>

int main() {
	std::string pj;
	int n, cont, min1, min2, act, sobran;
	bool ok;
	std::cin >> n;
	while (n != 0) {
		std::vector<std::queue<int>> colas(7);
		for (int i = 0; i < n; ++i) {
			std::cin >> pj;
			if (pj == "Mafalda") colas[0].push(i);
			else if (pj == "Felipe") colas[1].push(i);
			else if (pj == "Manolito") colas[2].push(i);
			else if (pj == "Susanita") colas[3].push(i);
			else if (pj == "Miguelito") colas[4].push(i);
			else if (pj == "Libertad") colas[5].push(i);
			else colas[6].push(i);
		}

		ok = true;
		cont = 0;
		while (ok) {
			ok = !colas[0].empty();//queda mafalda
			if (ok) {
				min1 = n;
				min2 = n;
				for (int k = 1; k < 7; ++k) {
					if (!colas[k].empty()) {
						if (colas[k].front() < min1) {
							min2 = min1;
							min1 = colas[k].front();
						}
						else if (colas[k].front() < min2) min2 = colas[k].front();
					}
				}

				ok = (min1 != n) && (min2 != n);//hay 3 para hacer una foto
				if (ok) {
					++cont;//hacemos foto
					for (int k = 1; k < 7; ++k) {
						if (!colas[k].empty()) {
							if (colas[k].front() == min1 || colas[k].front() == min2 || 
								colas[k].front() < colas[0].front()) colas[k].pop();
						}
					}
					colas[0].pop();
				}
			}
		}

		sobran = 0;
		for (int i = 0; i < 7; ++i) {
			sobran += colas[i].size();
		}

		std::cout << cont << ' ' << sobran << '\n';
	std::cin >> n;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

struct tPers {
	std::string nomb;
	int num;
};

struct tOrd {
	bool operator()(tPers const& p1, tPers const& p2) {
		return p1.num < p2.num;
	}
};

int main() {
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::string nomb;
	int camas, tam, cont;
	for (int i = 0; i < N; ++i) {
		cont = 0;
		std::queue<tPers> q;

		std::cin >> nomb;
		while (nomb != "F") {
			++cont;
			q.push({ nomb,cont });
			std::cin >> nomb;
		}

		std::cin >> camas >> tam;
		if (camas >= q.size()) std::cout << "TODOS TIENEN CAMA\n";
		else if (camas == 0) std::cout << "NADIE TIENE CAMA\n";
		else {
			int aux;
			while (q.size() > camas) {
				aux = tam;
				while (aux > 1) {
					q.push(q.front());
					q.pop();
					--aux;
				}
				q.pop();
			}
			std::vector<tPers> sol;
			while (!q.empty()) {
				sol.push_back(q.front());
				q.pop();
			}
			
			sort(sol.begin(), sol.end(),tOrd());
			std::cout << sol[0].nomb;
			for (int i = 1; i < camas; ++i) {
				std::cout << ' ' << sol[i].nomb;
			}
			std::cout << '\n';
		}
	}


return 0;
}
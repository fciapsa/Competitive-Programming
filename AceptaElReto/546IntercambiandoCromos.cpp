#include <iostream>
#include <map>
#include <vector>

void resuelve() {
	int N;
	std::cin >> N;

	int aux;
	std::map<int, int> alex;
	for (int i = 0; i < N; ++i) {
		std::cin >> aux;
		++alex[aux];
	}

	int M;
	std::cin >> M;
	std::map<int, int> mateo;
	for (int i = 0; i < M; ++i) {
		std::cin >> aux;
		++mateo[aux];
	}

	std::map<int, int>::iterator itA = alex.begin(), itM = mateo.begin();
	std::vector<int> repalex, repmateo;
	while (itA != alex.end() && itM != mateo.end()) {
		if (itA->first == itM->first) {
			++itA;
			++itM;
		}
		else if (itA->first < itM->first) {
			if (itA->second > 1) repalex.push_back(itA->first);
			++itA;
		}
		else {
			if (itM->second > 1) repmateo.push_back(itM->first);
			++itM;
		}
	}
	while (itA != alex.end()) {
		if (itA->second > 1) repalex.push_back(itA->first);
		++itA;
	}
	while (itM != mateo.end()) {
		if (itM->second > 1) repmateo.push_back(itM->first);
		++itM;
	}

	if (repalex.size() > 0) {
		std::cout << repalex[0];
		for (int i = 1; i < repalex.size(); ++i) {
			std::cout << ' ' << repalex[i];
		}
		std::cout << '\n';
	}
	else std::cout << "Nada que intercambiar\n";

	if (repmateo.size() > 0) {
		std::cout << repmateo[0];
		for (int i = 1; i < repmateo.size(); ++i) {
			std::cout << ' ' << repmateo[i];
		}
		std::cout << '\n';
	}
	else std::cout << "Nada que intercambiar\n";

}

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) resuelve();
return 0;
}
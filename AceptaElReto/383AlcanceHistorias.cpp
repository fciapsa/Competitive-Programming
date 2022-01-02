#include <iostream>
#include <vector>

void resolverCaso() {
	int numpag = 0;
	int x = 0, resta = 0;
	std::cin >> numpag;
	std::vector<int> leidas(numpag);
	for (int i = 0; i < numpag; ++i) {
		std::cin >> leidas[i];
	}
	x = leidas[0] - leidas[1];
	for (int i = 0; i < leidas.size(); ++i) {
		if (leidas[i] > x){
			for (int j = i + 1; j < leidas.size(); ++j) {
				resta = leidas[i] - leidas[j];
				if (resta > x) x = resta;
			}
		}
	}
	std::cout << x << '\n';
}

int main(){
	int numCasos = 0;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resolverCaso();
return 0;
}
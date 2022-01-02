#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

std::unordered_map<int,char> map = {
	{0,'T'},{1,'R'},{2,'W'},{3,'A'},{4,'G'},{5,'M'},{6,'Y'},{7,'F'},{8,'P'},{9,'D'},{10,'X'},{11,'B'},
{12,'N'},{13,'J'},{14,'Z'},{15,'S'},{16,'Q'},{17,'V'},{18,'H'},{19,'L'},{20,'C'},{21,'K'},{22,'E'}
};

int resolver(std::string s) {
	std::vector<int> pesos;
	int sol = 0, pot = 1, numero = 0, aux;

	for (int i = 7; i >= 0; --i) {
		if (s[i] == '?') {
			pesos.push_back(pot);
		}
		else {
			numero += (s[i] - '0') * pot;
		}
		pot *= 10;
	}

	std::vector<int> posValor(pesos.size());
	for (int i1 = 0; i1 < pesos.size() && i1 < 1; ++i1) {
		for (int j1 = 0; j1 < 10; ++j1) {
			posValor[i1] = j1;

			for (int i2 = 1; i2 < pesos.size() && i2 < 2; ++i2) {
				for (int j2 = 0; j2 < 10; ++j2) {
					posValor[i2] = j2;

					for (int i3 = 2; i3 < pesos.size() && i3 < 3; ++i3) {
						for (int j3 = 0; j3 < 10; ++j3) {
							posValor[i3] = j3;

							for (int i4 = 3; i4 < pesos.size() && i4 < 4; ++i4) {
								for (int j4 = 0; j4 < 10; ++j4) {
									posValor[i4] = j4;

									aux = numero;
									for (int k = 0; k < 4; ++k) {
										aux += pesos[k] * posValor[k];
									}
									if (map[aux % 23] == s[8]) ++sol;
								}
							}

							if (pesos.size() < 4) {
								aux = numero;
								for (int k = 0; k < 3; ++k) {
									aux += pesos[k] * posValor[k];
								}
								if (map[aux % 23] == s[8]) ++sol;
							}

						}
					}

					if (pesos.size() < 3) {
						aux = numero;
						for (int k = 0; k < 2; ++k) {
							aux += pesos[k] * posValor[k];
						}
						if (map[aux % 23] == s[8]) ++sol;
					}

				}
			}

			if (pesos.size() < 2) {
				aux = numero;
				aux += pesos[0] * posValor[0];
				if (map[aux % 23] == s[8]) ++sol;
			}

		}
	}

	return sol;
}

int main() {
	int n;
	cin >> n;
	std::string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		cout << resolver(s) << '\n';
	}

return 0;
}
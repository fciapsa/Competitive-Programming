#include <iostream>
#include <vector>
#include <string>

const int TAM = 84;

/*Do,Si# == 0
Do#,Reb == 1
Re == 2
Re#,Mib == 3
Mi,Fab == 4
Fa,Mi# == 5
Fa#,Solb == 6
Sol == 7
Sol#,Lab == 8
La == 9
La#,Sib == 10
Si,Dob == 11
*/

int main() {
	int n;
	std::cin >> n;
	std::string aux;
	while (n != 0) {
		std::vector<int> v(TAM, 0);
		for (int i = 0; i < n; ++i) {
			std::cin >> aux;
			switch (aux[0]) {
			case 'D': if (aux[2] == '#') ++v[1 + (int(aux[3]) - int('0') - 1)*12];
					  else if (aux[2] == 'b') ++v[11 + (int(aux[3]) - int('0') - 2)*12];
					  else ++v[(int(aux[2]) - int('0')-1)*12];
				break;
			case 'R': if (aux[2] == '#') ++v[3 + (int(aux[3]) - int('0') - 1) * 12];
					  else if (aux[2] == 'b') ++v[1 + (int(aux[3]) - int('0') - 1) * 12];
					  else ++v[2 + (int(aux[2]) - int('0') - 1) * 12];
				break;
			case 'M': if (aux[2] == '#') ++v[5 + (int(aux[3]) - int('0') - 1) * 12];
					  else if (aux[2] == 'b') ++v[3 + (int(aux[3]) - int('0') - 1) * 12];
					  else ++v[4 + (int(aux[2]) - int('0') - 1) * 12];
				break;
			case 'F': if (aux[2] == '#') ++v[6 + (int(aux[3]) - int('0') - 1) * 12];
					  else if (aux[2] == 'b') ++v[4 + (int(aux[3]) - int('0') - 1) * 12];
					  else ++v[5 + (int(aux[2]) - int('0') - 1) * 12];
				break;
			case 'S': 
				if (aux[1] == 'o') {
					if (aux[3] == '#') ++v[8 + (int(aux[4]) - int('0') - 1) * 12];
					else if (aux[3] == 'b') ++v[6 + (int(aux[4]) - int('0') - 1) * 12];
					else ++v[7 + (int(aux[3]) - int('0') - 1) * 12];
				}
				else {
					if (aux[2] == '#') ++v[(int(aux[3]) - int('0')) * 12];
					else if (aux[2] == 'b') ++v[10 + (int(aux[3]) - int('0') - 1) * 12];
					else ++v[11 + (int(aux[2]) - int('0') - 1) * 12];
				}
				break;
			case 'L':if (aux[2] == '#') ++v[10 + (int(aux[3]) - int('0') - 1) * 12];
					 else if (aux[2] == 'b') ++v[8 + (int(aux[3]) - int('0') - 1) * 12];
					 else ++v[9 + (int(aux[2]) - int('0') - 1) * 12];
				break;
			}
		}

		int j = 0, k;
		while (v[j] == 0) ++j;
		for (int i = j; i < TAM; ++i) if (v[i] != 0) k = i;

		std::cout << v[j];
		for (int i = j + 1; i <= k; ++i) std::cout << ' ' << v[i];
		std::cout << '\n';

	std::cin >> n;
	}
return 0;
}


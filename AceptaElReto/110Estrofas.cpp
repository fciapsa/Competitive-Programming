#include <iostream>
#include <string>
#include <cctype>

bool esVocal(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	int N, fin1, fin2, fin3, fin4, vocales;
	std::string s1, s2, s3, s4, cons1, cons2, cons3, cons4, voc1, voc2, voc3, voc4;
	std::cin >> N;
	while (N != 0) {
		std::cin.ignore();
		if (N == 1 || N > 4) {
			for (int i = 0; i < N; ++i) std::getline(std::cin, s1);
			std::cout << "DESCONOCIDO\n";
		}
		else {
			std::getline(std::cin, s1);
			std::getline(std::cin, s2);
			fin1 = s1.size() - 1;
			while (tolower(s1[fin1]) < 97 || tolower(s1[fin1]) > 122) --fin1;
			fin2 = s2.size() - 1;
			while (tolower(s2[fin2]) < 97 || tolower(s2[fin2]) > 122) --fin2;

			vocales = 0;
			cons1 = "";
			voc1 = "";
			while (vocales < 2) {
				cons1 = char(tolower(s1[fin1])) + cons1;
				if (esVocal(tolower(s1[fin1]))) {
					voc1 = char(tolower(s1[fin1])) + voc1;
					++vocales;
				}
				--fin1;
			}
			vocales = 0;
			cons2 = "";
			voc2 = "";
			while (vocales < 2) {
				cons2 = char(tolower(s2[fin2])) + cons2;
				if (esVocal(tolower(s2[fin2]))) {
					voc2 = char(tolower(s2[fin2])) + voc2;
					++vocales;
				}
				--fin2;
			}

			if (N == 2) {
				if (cons1 == cons2) std::cout << "PAREADO\n";
				else std::cout << "DESCONOCIDO\n";
			}
			else {
				std::getline(std::cin, s3);

				fin3 = s3.size() - 1;
				while (tolower(s3[fin3]) < 97 || tolower(s3[fin3]) > 122) --fin3;

				vocales = 0;
				cons3 = "";
				voc3 = "";
				while (vocales < 2) {
					cons3 = char(tolower(s3[fin3])) + cons3;
					if (esVocal(tolower(s3[fin3]))) {
						voc3 = char(tolower(s3[fin3])) + voc3;
						++vocales;
					}
					--fin3;
				}

				if (N == 3) {
					if (cons1 == cons3 && cons2 != cons1) std::cout << "TERCETO\n";
					else std::cout << "DESCONOCIDO\n";
				}
				else {
					std::getline(std::cin, s4);

					fin4 = s4.size() - 1;
					while (tolower(s4[fin4]) < 97 || tolower(s4[fin4]) > 122) --fin4;

					vocales = 0;
					cons4 = "";
					voc4 = "";
					while (vocales < 2) {
						cons4 = char(tolower(s4[fin4])) + cons4;
						if (esVocal(tolower(s4[fin4]))) {
							voc4 = char(tolower(s4[fin4])) + voc4;
							++vocales;
						}
						--fin4;
					}

					if (cons1 == cons4) {
						if (cons1 == cons2 && cons2 == cons3) std::cout << "CUADERNA VIA\n";
						else if (cons2 == cons3) std::cout << "CUARTETO\n";
						else std::cout << "DESCONOCIDO\n";
					}
					else if (cons1 == cons3 && cons2 == cons4) std::cout << "CUARTETA\n";
					else if (voc2 == voc4 && cons2 != cons4 && voc1 != voc3 && voc1 != voc2 && voc3 != voc2) std::cout << "SEGUIDILLA\n";
					else std::cout << "DESCONOCIDO\n";
				}
			}
		}

		std::cin >> N;
	}
	return 0;
}
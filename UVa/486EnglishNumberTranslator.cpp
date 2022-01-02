#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>

int simpleNum(std::string const& s) {
	if (s == "zero") return 0;
	else if (s == "one") return 1;
	else if (s == "two") return 2;
	else if (s == "three") return 3;
	else if (s == "four") return 4;
	else if (s == "five") return 5;
	else if (s == "six") return 6;
	else if (s == "seven") return 7;
	else if (s == "eight") return 8;
	else if (s == "nine") return 9;
	else if (s == "ten") return 10;
	else if (s == "eleven") return 11;
	else if (s == "twelve") return 12;
	else if (s == "thirteen") return 13;
	else if (s == "fourteen") return 14;
	else if (s == "fifteen") return 15;
	else if (s == "sixteen") return 16;
	else if (s == "seventeen") return 17;
	else if (s == "eighteen") return 18;
	else if (s == "nineteen") return 19;
	else if (s == "twenty") return 20;
	else if (s == "thirty") return 30;
	else if (s == "forty") return 40;
	else if (s == "fifty") return 50;
	else if (s == "sixty") return 60;
	else if (s == "seventy") return 70;
	else if (s == "eighty") return 80;
	else if (s == "ninety") return 90;
}

int buscar(std::vector<std::string> const& v, int ini, int fin, std::string const& s) {
	int i = ini;
	bool encontrado = false;

	while (i < fin && !encontrado) {
		if (v[i] == s)encontrado = true;
		else ++i;
	}

return i;
}

int toInt(std::vector<std::string> const& v, int ini, int fin) {
	if (ini == fin) return 0;
	else if (v[ini] == "negative") return -toInt(v, ini + 1, fin);
	else if (ini == fin-1) return simpleNum(v[ini]);
	else {
		int sol = 0;

		int millon = buscar(v, ini, fin, "million");
		if (millon < fin) {
			sol += toInt(v, ini, millon) * 1000000;
			ini = millon + 1;
		}

		int mil = buscar(v, ini, fin, "thousand");
		if (mil < fin) {
			sol += toInt(v, ini, mil) * 1000;
			ini = mil + 1;
		}

		int cien = buscar(v, ini, fin, "hundred");
		if (cien < fin) {
			sol += toInt(v, ini, cien) * 100;
			ini = cien + 1;
		}

		while (ini < fin) {
			sol += simpleNum(v[ini]);
			++ini;
		}

		return sol;
	}

}

int main() {
	char w[32];
	char c;

	while (scanf("%s", &w) == 1){
		std::vector<std::string> v;
		v.push_back(w);

		scanf("%c", &c);
		while (c != '\n') {
			scanf("%s", &w);
			v.push_back(w);
			scanf("%c", &c);
		}

		int sol = toInt(v,0,v.size());
		printf("%d\n", sol);
	}
}
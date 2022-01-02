#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>//sort

struct check {
	int day, month, year;
	int number;
	int dollars, cents;
};

struct tOrd {
	bool operator() (check const& c1, check const& c2) {
		return c1.number < c2.number;
	}
};

int main() {
	int N;
	scanf("%d", &N);

	check aux;
	char s[64];
	char c;
	scanf("\n\n");

	while (N--) {
		std::vector<check> v;

		while (scanf("%[^\n]",s) == 1 && s != "\n") {
			int x = s[0] - '0';
			x *= 10;
			x += (s[1] - '0');
			aux.year = x;

			x = s[3] - '0';
			x *= 10;
			x += (s[4] - '0');
			aux.month = x;

			x = s[6] - '0';
			x *= 10;
			x += (s[7] - '0');
			aux.day = x;

			int i = 9;
			x = 0;
			while (s[i] >= '0' && s[i] <= '9') {
				x *= 10;
				x += s[i] - '0';
				++i;
			}
			aux.number = x;
			++i;
			
			if (s[i] && s[i] >= '0' && s[i] <= '9') {
				x = 0;
				while (s[i] && s[i] >= '0' && s[i] <= '9') {
					x *= 10;
					x += s[i] - '0';
					++i;
				}
				aux.dollars = x;

				if (s[i] && s[i] == '.') {
					++i;
					x = 0;
					while (s[i] && s[i] >= '0' && s[i] <= '9') {
						x *= 10;
						x += s[i] - '0';
						++i;
					}
					while (x >= 100) x /= 10;
					aux.cents = x;
				}
				else aux.cents = 0;
			}
			else {
				if (s[i] && s[i] == ' ') ++i;
				if (s[i] && s[i] == '.') {
					aux.dollars = 0;
					++i;
					x = 0;
					while (s[i] && s[i] >= '0' && s[i] <= '9') {
						x *= 10;
						x += s[i] - '0';
						++i;
					}
					while (x >= 100) x /= 10;
					aux.cents = x;
				}
				else {
					aux.dollars = 0;
					aux.cents = 0;
				}
			}

			v.push_back(aux);
			scanf("%c", &c);//leer un salto
		}
		scanf("%c", &c);//leer un salto

		sort(v.begin(), v.end(), tOrd());

		int tam = v.size();
		int perCol = tam / 3;
		if (tam % 3 != 0) ++perCol;

		if (tam > 0) {
			printf("%4d  %6d.%02d %02d/%02d/%02d",
				v[0].number, v[0].dollars, v[0].cents, v[0].year, v[0].month, v[0].day);
			if (tam == 1) printf("\n");

			if (tam > 1) {
				if (v[perCol].number == v[perCol - 1].number + 1) {
					printf("   %4d  %6d.%02d %02d/%02d/%02d",
						v[perCol].number, v[perCol].dollars, v[perCol].cents, v[perCol].year, v[perCol].month, v[perCol].day);
				}
				else {
					printf("   %4d* %6d.%02d %02d/%02d/%02d",
						v[perCol].number, v[perCol].dollars, v[perCol].cents, v[perCol].year, v[perCol].month, v[perCol].day);
				}

				if (tam == 2 || tam == 4) printf("\n");
			}

			if (tam > 2 && tam != 4) {
				if (v[2 * perCol].number == v[2 * perCol - 1].number + 1) {
					printf("   %4d  %6d.%02d %02d/%02d/%02d\n",
						v[2*perCol].number, v[2*perCol].dollars, v[2*perCol].cents, v[2*perCol].year, v[2*perCol].month, v[2*perCol].day);
				}
				else {
					printf("   %4d* %6d.%02d %02d/%02d/%02d\n",
						v[2*perCol].number, v[2*perCol].dollars, v[2*perCol].cents, v[2*perCol].year, v[2*perCol].month, v[2*perCol].day);
				}
			}

			if (tam > 3) {
				for (int i = 1, j = i + perCol, k = j + perCol; i < perCol; ++i, ++j, ++k) {
					//1era columna
					if (v[i].number == v[i - 1].number + 1) {
						printf("%4d  %6d.%02d %02d/%02d/%02d",
							v[i].number, v[i].dollars, v[i].cents, v[i].year, v[i].month, v[i].day);
					}
					else {
						printf("%4d* %6d.%02d %02d/%02d/%02d",
							v[i].number, v[i].dollars, v[i].cents, v[i].year, v[i].month, v[i].day);
					}

					//2a columna
					if (j < tam) {
						if (v[j].number == v[j - 1].number + 1) {
							printf("   %4d  %6d.%02d %02d/%02d/%02d",
								v[j].number, v[j].dollars, v[j].cents, v[j].year, v[j].month, v[j].day);
						}
						else {
							printf("   %4d* %6d.%02d %02d/%02d/%02d",
								v[j].number, v[j].dollars, v[j].cents, v[j].year, v[j].month, v[j].day);
						}
					}

					if (tam == j + 1 || k >= tam) printf("\n");

					//3era columna
					if (k < tam) {
						if (v[k].number == v[k - 1].number + 1) {
							printf("   %4d  %6d.%02d %02d/%02d/%02d\n",
								v[k].number, v[k].dollars, v[k].cents, v[k].year, v[k].month, v[k].day);
						}
						else {
							printf("   %4d* %6d.%02d %02d/%02d/%02d\n",
								v[k].number, v[k].dollars, v[k].cents, v[k].year, v[k].month, v[k].day);
						}
					}
				}
			}
		}

		if(N != 0)printf("\n");
	}
return 0;
}
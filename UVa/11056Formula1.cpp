#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>//sort

struct tPiloto {
	char name[32];
	int min, sec, ms;
};

bool lower(char const p1[], char const p2[]) {
	char c1, c2;

	int i = 0;
	for (; p1[i] && p2[i]; ++i) {
		c1 = p1[i];
		if (c1 < 'a') c1 = 'a' + (c1 - 'A');
		c2 = p2[i];
		if (c2 < 'a') c2 = 'a' + (c2 - 'A');

		if (c1 < c2) return true;
		else if (c2 < c1) return false;
	}

	if (p2[i]) return true;
	else return false;
}

struct tOrd {
	bool operator() (tPiloto const&p1,tPiloto const&p2){
		return (p1.min < p2.min || (p1.min == p2.min && (p1.sec < p2.sec ||
			(p1.sec == p2.sec && (p1.ms < p2.ms || (p1.ms == p2.ms && lower(p1.name, p2.name)))))));
	}
};

int main() {
	int N;
	tPiloto aux;

	while (scanf("%d", &N) == 1) {
		//scanf("\n");
		std::vector<tPiloto> lista;

		for (int i = 0; i < N; ++i) {
			scanf("%s : %d min %d sec %d ms", &aux.name, &aux.min, &aux.sec, &aux.ms);
			lista.push_back(aux);
		}

		sort(lista.begin(), lista.end(), tOrd());

		int R = 1;
		for (int i = 0; i < N; i += 2) {
			printf("Row %d\n", R++);
			printf("%s\n", lista[i].name);
			if (i + 1 < N) printf("%s\n", lista[i + 1].name);
		}
		printf("\n");
	}
return 0;
}
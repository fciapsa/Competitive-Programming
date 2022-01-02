#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

int main() {
	long int q, a, b;
	long int tot;
	long int avg, sobra, sol;
	scanf("%ld", &q);

	while (q > 0) {
		tot = 0; sol = 0;
		std::vector<int> pagos;

		for (int i = 0; i < q; ++i) {
			scanf("%ld.%ld", &a, &b);
			a = a*100 + b;
			pagos.push_back(a);
			tot += a;
		}

		avg = tot / q;
		sobra = tot % q;

		for (int i = 0; i < q; ++i) {
			if (pagos[i] > avg) {
				if (sobra > 0) {
					sol += pagos[i] - 1 - avg;
					--sobra;
				}
				else sol += pagos[i] - avg;
			}
		}

		long int aux = sol % 100;
		sol /= 100;

		if(aux > 9) printf("$%ld.%ld\n", sol, aux);
		else printf("$%ld.0%ld\n", sol, aux);
		scanf("%d",&q);
	}
return 0;
}
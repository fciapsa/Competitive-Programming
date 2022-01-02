#include <iostream>
#include <string>

long long int fact(int n){
return (n == 1 || n == 0) ? 1 : fact(n - 1) * n;
}

void generate(int C, int V,std::string &sol, int cont,long long int &done,long long int tot){
	if (C == 0 && V == 0) {
		++done;
		if(done != tot) std::cout << sol << ' ';
		else std::cout << sol;
	}
	else if (C == 0) {
		sol += 'V';
		--cont;
		generate(C, V - 1,sol,cont,done, tot);
	}
	else if (V == 0) {
		sol += 'C';
		--cont;
		generate(C - 1, V,sol,cont,done,tot);
	}
	else {
		sol += 'C';
		--cont;
		generate(C - 1, V,sol,cont,done,tot);

		++cont;
		for (int i = 0; i < cont; ++i) {
			sol.pop_back();
		}

		sol += 'V';
		--cont;
		generate(C, V - 1,sol,cont,done,tot);
	}
}

int main() {
	int c, C, V;
	std::cin >> c;
	for (int i = 0; i < c; ++i) {
		std::string sol = "";
		std::cin >> C >> V;
		int cont = C + V;
		long long int tot = fact(C + V)/(fact(C)*fact(V));
		long long int done = 0;
		generate(C, V,sol,cont,done,tot);
		std::cout << '\n';
	}
return 0;
}
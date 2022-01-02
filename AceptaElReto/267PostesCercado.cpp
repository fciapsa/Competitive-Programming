#include <iostream>

long int resolverCaso(long int l1, long int l2, long int dmax) {
	long int sol = 0;
	if (l1%dmax == 0 && l2%dmax == 0) sol =(l1 / dmax) * 2 + (l2 / dmax) * 2;
	else if (l1%dmax == 0 || l2%dmax == 0) sol = 2 + (l1 / dmax) * 2 + (l2 / dmax) * 2;
	else sol = 4 + (l1 / dmax)*2 + (l2 / dmax) * 2;
	return sol;
}

bool resolver(){
	long int l1 = 0; long int l2 = 0; long int dmax = 0; long int sol = 0;
	std::cin >> l1 >> l2 >> dmax;
	if (l1 == 0 && l2 == 0 && dmax == 0) return false;

	sol = resolverCaso(l1, l2, dmax);
	std::cout << sol << '\n';
	return true;
	}

int main() {
	while (resolver());
return 0;
}
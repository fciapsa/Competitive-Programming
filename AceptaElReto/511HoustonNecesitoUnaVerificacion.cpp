#include <iostream>
#include <vector>

bool resuelve() {
	long long int A, B;
	std::cin >> A >> B;

	if (!std::cin) return false;

	std::vector<long long int> amult(A), aval(A), bmult(B), bval(B);
	for (long long int i = 0; i < A; ++i) {
		std::cin >> amult[i] >> aval[i];
	}
	for (long long int i = 0; i < B; ++i) {
		std::cin >> bmult[i] >> bval[i];
	}

	long long int sol = 0;
	long long int iam = 0, iav = 0, ibm = 0, ibv = 0;

	while (iam < A && ibm < B && iav < A && ibv < B) {
		if (amult[iam] >= bmult[ibm]) {
			sol += bmult[ibm] * aval[iav] * bval[ibv];
			amult[iam] -= bmult[ibm];
			++ibm;
			++ibv;
			if (amult[iam] == 0) {
				++iam;
				++iav;
			}
		}
		else {
			sol += amult[iam] * aval[iav] * bval[ibv];
			bmult[ibm] -= amult[iam];
			++iam;
			++iav;
			if (bmult[ibm] == 0) {
				++ibm;
				++ibv;
			}
		}
	}
	std::cout << sol << '\n';

	return true;
}

int main() {
	while (resuelve());
	return 0;
}
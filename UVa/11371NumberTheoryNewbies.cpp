#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>//sort

//OJO: La interpretacion correcta es que no debe haber ceros al principio 
// del numero b, pero todos los digitos(los 0 incluidos) tienen que aparecer en b

long long int reverseToInt(std::vector<char> const& v) {
	int i = v.size() - 1;
	long long int sol = 0;

	while (i >= 0) {
		sol *= 10;
		sol += v[i] - '0';
		--i;
	}

return sol;
}

long long int toInt(std::vector<char> const& v) {
	int i = 0, z = 0;
	long long int sol = 0;

	while (i < v.size() && v[i] == '0') {
		++i;
		++z;
	}
	if (i < v.size() && v[i] != '0' && z > 0) {
		sol += v[i] - '0';
		while (z--) sol *= 10;
		++i;
	}
	while (i < v.size()) {
		sol *= 10;
		sol += v[i] - '0';
	++i;
	}

return sol;
}

int main() {
	char c;
	while (scanf("%c", &c) == 1) {
		std::vector<char> v;
		v.push_back(c);

		scanf("%c", &c);
		while (c != '\n') {
			v.push_back(c);
			scanf("%c", &c);
		}

		sort(v.begin(), v.end());
		long long int b = toInt(v);
		long long int a = reverseToInt(v);

		printf("%lld - %lld = %lld = 9 * %lld\n", a, b, a - b, (a-b) / 9);
	}
return 0;
}
#include <iostream>

void restar(int M,char* act, char* next) {
	bool carry = false;
	int x1, x2;
	for (int i = M + 1; i >= 2; --i) {
		x1 = act[i] - '0';
		x2 = next[i] - '0';
		if (carry) {
			carry = false;
			--x1;
		}
		if (x1 >= x2) act[i] = char('0' + (x1 - x2));
		else {
			carry = true;
			act[i] = char('0' + 10 + x1 - x2);
		}
	}
	if (carry) act[0] = char(act[0] - 1);
}

void sumar(int M,char* act,char* next) {
	bool carry = false;
	int x1, x2;
	for (int i = M + 1; i >= 2; --i) {
		x1 = act[i] - '0';
		x2 = next[i] - '0';
		if (carry) {
			carry = false;
			++x1;
		}

		if (x1 + x2 >= 10) {
			carry = true;
			act[i] = char('0' + x1 + x2 - 10);
		}
		else act[i] = char('0' + x1 + x2);
	}
	if (carry) act[0] = char(act[0] + 1);
}

int main() {
	char act[502], next[502];
	next[0] = '0';
	next[1] = '.';
	int N, M, x, c, r;
	std::cin >> N;
	while (N != 0) {
		std::cin >> M;
		act[0] = '1';
		act[1] = '.';
		for (int i = 0; i < M; ++i) act[i+2] = '0';

		//en los impares se resta y en los pares se suma
		for (int k = 1, q = 3; k < N; ++k, q += 2) {
			x = 10;
			for (int j = 0; j < M; ++j) {
				if (x < q) {
					next[j + 2] = '0';
					x *= 10;
				}
				else {
					c = x / q;
					r = x % q;
					next[j + 2] = char('0' + c);
					x = r * 10;
				}
			}

			if (k % 2 == 0) sumar(M,act,next);
			else restar(M,act,next);
		}

		M += 2;
		for (int i = 0; i < M; ++i) std::cout << act[i];
		std::cout << '\n';

	std::cin >> N;
	}
return 0;
}
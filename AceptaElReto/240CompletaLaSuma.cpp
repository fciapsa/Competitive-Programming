#include <iostream>
#include <string>
#include <vector>

struct sol {
	int n1, n2, n3;
};

int main() {
	std::ios::sync_with_stdio(false);
	int n1, n2, n3, pot, p1, p2, p3, o1, o2, o3, min1, min2, min3;
	std::string op1, op2, res;
	std::cin >> op1;
	while (std::cin) {
		std::cin >> op2 >> res;
		if (op1[0] == '-' && op1.size() > 1) min1 = 1;
		else min1 = 0;
		if (op2[0] == '-' && op2.size() > 1) min2 = 1;
		else min2 = 0;
		if (res[0] == '-' && res.size() > 1) min3 = 1;
		else min3 = 0;

		pot = 1;
		n1 = 0;
		for (int i = op1.size() - 1; i >= 0; --i) {
			if (op1[i] != '-') n1 += ((int(op1[i]) - int('0')) * pot);
			else p1 = pot;
			pot *= 10;
		}
		o1 = n1;
		pot = 1;
		n2 = 0;
		for (int i = op2.size() - 1; i >= 0; --i) {
			if (op2[i] != '-') n2 += ((int(op2[i]) - int('0')) * pot);
			else p2 = pot;
			pot *= 10;
		}
		o2 = n2;
		pot = 1;
		n3 = 0;
		for (int i = res.size() - 1; i >= 0; --i) {
			if (res[i] != '-') n3 += ((int(res[i]) - int('0')) * pot);
			else p3 = pot;
			pot *= 10;
		}
		o3 = n3;

		std::vector<sol> v;
		if (min1 == 1) n1 += p1;
		for (int i = min1; i <= 9; ++i) {
			if (min2 == 1) n2 += p2;
			for (int j = min2; j <= 9; ++j) {
				if (min3 == 1) n3 += p3;
				for (int k = min3; k <= 9; ++k) {
					if (n1 + n2 == n3) v.push_back({ n1,n2,n3 });

					n3 += p3;
				}
				n3 = o3;
				n2 += p2;
			}
			n2 = o2;
			n1 += p1;
		}

		if (v.size() == 0) std::cout << "IMPOSIBLE\n";
		else if (v.size() > 1) std::cout << "VARIAS\n";
		else std::cout << v[0].n1 << ' ' << v[0].n2 << ' ' << v[0].n3 << '\n';

		std::cin >> op1;
	}
	return 0;
}
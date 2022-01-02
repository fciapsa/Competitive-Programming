#include <iostream>
#include <string>
#include <vector>

bool divisor(int n, std::vector<int> const&dig) {
	int aux = 0;
	int pot = 10;
	aux += dig[dig.size() - 1];
	for (int i = dig.size() - 2; i >= 0; --i) {
		aux += dig[i] * pot;
		pot *= 10;
	}
return (aux != 0 && n%aux == 0);
}

bool vampiro(int n, std::string &num, int nd, std::vector<int> &dig1, std::vector<int> &dig2) {
	if (dig1.size() == nd / 2 && dig2.size() == nd / 2) {
		int n1 = 0;
		int pot = 10;
		n1 += dig1[dig1.size() - 1];
		for (int i = dig1.size() - 2; i >= 0; --i) {
			n1 += dig1[i]*pot;
			pot *= 10;
		}
		int n2 = 0;
		pot = 10;
		n2 += dig2[dig2.size() - 1];
		for (int i = dig2.size() - 2; i >= 0; --i) {
			n2 += dig2[i]*pot;
			pot *= 10;
		}
		return((n1*n2 == n) && (n1 % 10 != 0 || n2 % 10 != 0));
	}
	else if(dig1.size() != nd/2){
		dig1.push_back(int(num[0]) - int('0'));
		std::string aux = num.substr(1, num.size() - 1);
		bool b = vampiro(n, aux, nd, dig1, dig2);
		for (int i = 1; i < num.size() && !b; ++i) {
			dig1.pop_back();
			dig1.push_back(int(num[i]) - int('0'));
			aux.clear();
			aux += num.substr(0, i);
			aux += num.substr(i + 1, num.size() - i - 1);
			b = vampiro(n, aux, nd, dig1, dig2);
		}
		dig1.pop_back();
		return b;
	}
	else if (dig2.size() != nd / 2) {
		if (divisor(n, dig1)) {
			dig2.push_back(int(num[0]) - int('0'));
				std::string aux = num.substr(1, num.size() - 1);
				bool b = vampiro(n, aux, nd, dig1, dig2);
				for (int i = 1; i < num.size() && !b; ++i) {
					dig2.pop_back();
						dig2.push_back(int(num[i]) - int('0'));
						aux.clear();
						aux += num.substr(0, i);
						aux += num.substr(i + 1, num.size() - i - 1);
						b = vampiro(n, aux, nd, dig1, dig2);
				}
			dig2.pop_back();
			return b;
		}
		else return false;
	}
}

void solve() {
	std::string num;
	std::cin >> num;

	if (num.size() % 2 != 0) std::cout << "NO\n";
	else {
		int n = 0;
		int pot = 10;
		n += int(num[num.size() - 1]) - int('0');
		for (int i = num.size() - 2; i >= 0; --i) {
			n += (int(num[i]) - int('0'))*pot;
			pot *= 10;
		}
		std::vector<int> dig1, dig2;
		if (vampiro(n,num, num.size(),dig1,dig2)) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
}

int main() {
	int nc;
	std::cin >> nc;
	for (int i = 0; i < nc; ++i) {
		solve();
	}
return 0;
}
#include <iostream>
#include <string>

void next(std::string& num) {
	bool keep = true;
	int pos = num.size() - 1;
	while (keep && pos >= 0) {
		if (num[pos] == '9') {
			num[pos] = '0';
			--pos;
		}
		else {
			++num[pos];
			keep = false;
		}
	}

	if (keep) num = '1' + num;
}

int toInt(std::string const& num) {
	int aux = 0;
	int pos = num.size() - 1;
	int pot = 1;
	while (pos >= 0) {
		aux += (int(num[pos]) - int('0')) * pot;
		--pos;
		pot *= 10;
	}

	return aux;
}

void capicua(std::string& num, int pos1, int pos2) {
	if (pos1 >= pos2) return;

	if (num[pos1] == num[pos2]) capicua(num, pos1 + 1, pos2 - 1);
	else if (num[pos1] > num[pos2]) {
		num[pos2] = num[pos1];
		capicua(num, pos1 + 1, pos2 - 1);
	}
	else {
		bool keep = true;
		int ind = pos2 - 1;
		while (keep) {
			if (num[ind] == '9') {
				num[ind] = '0';
				--ind;
			}
			else {
				++num[ind];
				keep = false;
			}
		}

		num[pos2] = num[pos1];
		capicua(num, pos1 + 1, pos2 - 1);
	}
}

int main() {
	int T, val1, val2;
	bool all9;
	std::string num1, num2;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> num1;
		if (num1.size() == 1) {
			if (num1 == "9") std::cout << "2\n";
			else std::cout << "1\n";
		}
		else if (num1.size() == 2) {
			if (num1 == "99") std::cout << "2\n";
			else if (num1[0] == num1[1]) std::cout << "11\n";
			else if (num1[0] > num1[1]) std::cout << int(num1[0]) - int(num1[1]) << '\n';
			else std::cout << 10 - (int(num1[1]) - int('0')) + (int(num1[0]) - int('0')) + 1 << '\n';
		}
		else if (num1.size() == 3) {
			if (num1 == "999") std::cout << "2\n";
			else if (num1[0] == num1[2]) {
				if (num1[1] == '9') std::cout << "11\n";
				else std::cout << "10\n";
			}
			else if (num1[0] > num1[2]) std::cout << int(num1[0]) - int(num1[2]) << '\n';
			else {
				if (num1[1] == '9') std::cout << 10 - (int(num1[2]) - int('0')) + (int(num1[0]) - int('0')) + 1 << '\n';
				else std::cout << 10 - (int(num1[2]) - int('0')) + (int(num1[0]) - int('0')) << '\n';
			}
		}
		else {
			all9 = true;
			for (int i = 0; i < num1.size() && all9; ++i) {
				all9 = num1[i] == '9';
			}
			if (all9) std::cout << "2\n";
			else {
				num2 = num1;
				next(num2);
				capicua(num2, 0, num2.size() - 1);

				val1 = toInt(num1);
				val2 = toInt(num2);
				std::cout << val2 - val1 << '\n';

			}
		}
	}
	return 0;
}
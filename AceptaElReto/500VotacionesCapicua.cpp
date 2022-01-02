#include <iostream>
#include <vector>
#include <string>

void next(std::string &num) {
	if (num[3] == '9') {
		num[3] = '0';
		if (num[2] == '9') {
			num[2] = '0';
			if (num[1] == '9') {
				num[1] = '0';
				if (num[0] == '9') num[0] = '0';
				else num[0] = char(int(num[0]) + 1);
			}
			else num[1] = char(int(num[1]) + 1);
		}
		else num[2] = char(int(num[2]) + 1);
	}
	else num[3] = char(int(num[3]) + 1);
}

void prev(std::string &num) {
	if (num[3] == '0') {
		num[3] = '9';
		if (num[2] == '0') {
			num[2] = '9';
			if (num[1] == '0') {
				num[1] = '9';
				if (num[0] == '0') num[0] = '9';
				else num[0] = char(int(num[0]) - 1);
			}
			else num[1] = char(int(num[1]) - 1);
		}
		else num[2] = char(int(num[2]) - 1);
	}
	else num[3] = char(int(num[3]) - 1);
}

void next10(std::string& num) {
	if (num[2] == '9') {
		num[2] = '0';
		if (num[1] == '9') {
			num[1] = '0';
			if (num[0] == '9') num[0] = '0';
			else num[0] = char(int(num[0]) + 1);
		}
		else num[1] = char(int(num[1]) + 1);
	}
	else num[2] = char(int(num[2]) + 1);
}

void prev10(std::string& num) {
	if (num[2] == '0') {
		num[2] = '9';
		if (num[1] == '0') {
			num[1] = '9';
			if (num[0] == '0') num[0] = '9';
			else num[0] = char(int(num[0]) - 1);
		}
		else num[1] = char(int(num[1]) - 1);
	}
	else num[2] = char(int(num[2]) - 1);
}

bool capicua(std::string const& s1, std::string const& s2) {
	return s1[0] == s2[3] && s1[1] == s2[2] && s1[2] == s2[1] && s1[3] == s2[0];
}

void init(std::vector<int> &sumas) {
	bool noZero;
	int cont, ind = 1;
	std::string s1, s2, act = "1000";
	while (act != "0000") {
		cont = 0;
		noZero = true;
		s1 = act;
		s2 = "0000";
		while (noZero || s1[0] == '0') {
			if (s1[0] != s2[3]) {
				prev(s1);
				next(s2);

				if (s1[0] == '0') noZero = false;
			}
			else if (s1[1] == '0' && s1[2] == '0') {
				if (capicua(s1, s2)) ++cont;
				next(s2);
				prev(s1);

				if (s1[0] == '0') noZero = false;
			}
			else {
				if (capicua(s1, s2)) ++cont;
				next10(s2);
				prev10(s1);

				if (s1[0] == '0') noZero = false;
			}
		}

		sumas[ind] = sumas[ind - 1] + cont;
	next(act);
	++ind;
	}
	
}

int main() {
	std::vector<int> sumas(9001);
	init(sumas);
	int N, Q;
	std::cin >> N >> Q;
	while (N != 0) {
		std::cout << N << ' ' << Q << ' ' << sumas[N - 999] - sumas[Q - 1000] << '\n';
	std::cin >> N >> Q;
	}
return 0;
}
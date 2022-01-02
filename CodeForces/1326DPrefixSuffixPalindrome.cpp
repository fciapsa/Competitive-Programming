#include <iostream>
#include <string>
#include <algorithm>

char T[2000001];
int P[2000001];

int main() {
	std::string s;
	int t, until, copyTo;
	std::cin >> t;
	std::cin.ignore();
	for (int k = 0; k < t; ++k) {
		getline(std::cin, s);
		if (s.size() == 1) std::cout << s << '\n';
		else {
			until = -1;
			while (until + 1 < s.size() / 2 && s[until + 1] == s[s.size() - until - 2]) ++until;
			if (until >= int(s.size() / 2 - 1)) std::cout << s << '\n';
			else {
				copyTo = s.size() - until - 2;
				int manacher_size = 2 * (s.size() - 2 * (until + 1)) + 1;
				T[0] = '#';
				for (int i = 1, j = until + 1; j <= copyTo; i += 2, ++j) {
					T[i] = s[j];
					T[i + 1] = '#';
				}
				//Algoritmo de Manacher + guardarse los palindromos mas grandes pegados a un extremo
				int C = 0, R = -1, rad;
				//+
				int max = 1;
				bool left = true, right = false;
				for (int i = 0; i < manacher_size; ++i) {
					if (i < R) {
						rad = std::min(P[2 * C - i], R - i);
					}
					else {
						rad = 0;
					}
					// Try to extend
					while (i + rad +1  < manacher_size && i - rad - 1 >= 0 && T[i - rad - 1] == T[i + rad + 1]) {
						rad++;
					}
					P[i] = rad;
					if (i + rad > R) {
						C = i;
						R = i + rad;
					}
					//+
					if (i - rad == 0 && rad > max) {
						max = rad;
						left = true;
						right = false;
					}
					if (i + rad == manacher_size-1 && rad > max) {
						max = rad;
						left = false;
						right = true;
					}
				}
				if(until >= 0) std::cout << s.substr(0, until + 1);
				if (left) std::cout << s.substr(until + 1, max);
				else std::cout << s.substr(s.size() - until - 1 - max, max);
				if (until >= 0) std::cout << s.substr(s.size() - until - 1, until + 1) << '\n';
				else std::cout << '\n';
			}
		}
	}
return 0;
}
#include <iostream>
#include <string>

int main() {
	int N, m, a, c;
	std::string s;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> m >> a >> c;
		getline(std::cin, s);

		bool ok = true;
		for (int j = 1; ok && j < s.size(); ++j) {
			switch (s[j]) {
			case 'M': if (m > 0) --m;
					  else ok = false; break;
			case 'A': if (a > 0) --a;
					  else ok = false; break;
			case 'C': if (c > 0) --c;
					  else ok = false; break;
			case 'R': if (m > 0 && a > 0) {
				--m;
				--a;
			}
					  else ok = false; break;
			case 'L': if (m > 0 && c > 0) {
				--m;
				--c;
			}
					  else ok = false; break;
			case 'V': if (a > 0 && c > 0) {
				--a;
				--c;
			}
					  else ok = false; break;
			case 'N': if (a > 0 && m > 0 && c > 0) {
				--a;
				--m;
				--c;
			}
					  else ok = false; break;
			}
		}

		if (ok) std::cout << "SI " << m << ' ' << a << ' ' << c << '\n';
		else std::cout << "NO\n";
	}
return 0;
}
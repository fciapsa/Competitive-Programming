#include <iostream>
#include <string>
#include <cctype>

bool iguales(char const&a,char const&b) {
	return (tolower(a) == tolower(b)) || ((tolower(a) == 'b' || tolower(a) == 'v') && (tolower(b) == 'b' || tolower(b) == 'v'));
}

int main() {
	bool same, stop;
	std::string s1, s2;
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> s1 >> s2;
		if (s1.size() != s2.size()) std::cout << "NO\n";
		else {
			same = true;
			for (int i = 0; i < s1.size() && same; ++i) {
				same = iguales(s1[i], s2[i]);
			}

			if (same) std::cout << "NO\n";//son la misma palabra salvo b/v
			else {
				stop = false;
				for (int i = 1; i < s1.size() && !stop; ++i) {
					if (iguales(s1[i],s2[0])) {
						same = true;
						
						for (int j = 1; j < s2.size() && same; ++j) {
							same = iguales(s1[(j + i) % s1.size()], s2[j]);
						}

						if (same) {
							std::cout << "SI\n";
							stop = true;
						}
					}
				}

				if (!stop) std::cout << "NO\n";
			}
		}
	}

return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int TOT = 26;

struct piloto {
	int pos;
	std::string name;
	bool operator<(piloto const& other) const {
		return pos < other.pos;
	}
};

int main() {
	int N, x;
	std::string s;
	bool ok;
	std::cin >> N;
	while (N != 0) {
		ok = true;
		std::vector<piloto> v;
		std::vector<bool> marked(TOT + 1, false);
		for (int i = 1; i <= N; ++i) {
			std::cin >> x;
			std::cin.ignore();
			getline(std::cin, s);

			if (i + x < 1 || i + x > TOT || marked[i + x]) ok = false;
			else {
				marked[i + x] = true;
				v.push_back({ i + x,s });
			}
		}

		if (ok) {
			sort(v.begin(), v.end());
			for (int i = 0; i < N; ++i) {
				std::cout << v[i].pos << ' ' << v[i].name << '\n';
			}
		}
		else std::cout << "IMPOSIBLE\n";

		std::cout << "-----\n";
	std::cin >> N;
	}
return 0;
}
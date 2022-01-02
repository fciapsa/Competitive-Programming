#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct tInfo {
	std::string instruct;
	int salto;
};

int main() {
	int T, n, next;
	std::string instruct;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		next = 10;
		std::unordered_map<int, int> renum;
		std::vector<tInfo> v;
		std::cin >> n;
		while (n != 0) {
			renum[n] = next;
			next += 10;
			std::cin >> instruct;
			if (instruct == "RETURN") v.push_back({ instruct,0 });
			else {
				std::cin >> n;
				v.push_back({ instruct,n });
			}

		std::cin >> n;
		}
		next = 10;
		for (int j = 0; j < v.size(); ++j) {
			if (v[j].instruct == "RETURN") std::cout << next << ' ' << v[j].instruct << '\n';
			else std::cout << next << ' ' << v[j].instruct << ' ' << renum[v[j].salto] << '\n';
			next += 10;
		}
		std::cout << "---\n";
	}
return 0;
}
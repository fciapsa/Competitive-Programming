#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> song = { "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy",
"birthday", "to", "Rujia", "Happy", "birthday", "to", "you" };

int main() {
	int n, t, j = 0;
	std::cin >> n;
	std::vector<std::string> names(n);
	for (int i = 0; i < n; ++i) std::cin >> names[i];

	t = n / 16;
	if (n % 16 != 0) ++t;
	t *= 16;
	for (int i = 0; i < t; ++i) {
		std::cout << names[j % n] << ": " << song[j % 16] << '\n';
		++j;
	}

return 0;
}
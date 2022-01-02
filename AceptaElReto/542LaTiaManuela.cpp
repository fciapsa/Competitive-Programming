#include <iostream>
#include <vector>
#include <algorithm>

void resuelve() {
	std::vector<int> v1(3), v2(3);

	std::cin >> v1[0] >> v1[1] >> v1[2] >> v2[0] >> v2[1] >> v2[2];

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	bool ok = true;
	for (int i = 0; i < 3 && ok; ++i) {
		ok = v1[i] < v2[i];
	}

	if (ok) std::cout << "SIRVE\n";
	else std::cout << "NO SIRVE\n";
}

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) resuelve();
return 0;
}
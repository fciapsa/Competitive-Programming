#include <iostream>
#include <map>
#include <functional>
#include <iterator>

using llint = long long int;

int main() {
	llint n, m, k;
	std::cin >> n >> m >> k;
	std::map<int, int> A;
	std::map<int, int, std::greater<int>> B;
	llint consec = 0;
	int act;
	for (int i = 0; i < n; ++i) {
		std::cin >> act;
		if (act == 1) ++consec;
		else {
			if (consec > 0) ++A[consec];
			consec = 0;
		}
	}
	if (consec > 0) ++A[consec];
	consec = 0;
	for (int i = 0; i < m; ++i) {
		std::cin >> act;
		if (act == 1) ++consec;
		else {
			if (consec > 0) ++B[consec];
			consec = 0;
		}
	}
	if (consec > 0) ++B[consec];

	long long int count = 0, cols;
	auto it1 = A.begin();
	auto it3 = B.begin();
	if (it3 != B.end()) {
		auto it3Next = std::next(it3);
		int maxI = n;
		if (k < n) maxI = k;
		for (int i = 1; i <= maxI && it1 != A.end(); ++i) {
			while (it1 != A.end() && it1->first < i) ++it1;
			while (it3Next != B.end() && (i * it3Next->first) >= k) {
				++it3;
				++it3Next;
			}

			if (k % i == 0 && (it3->first * i) >= k) {
				cols = k / i;

				for (auto it2 = it1; it2 != A.end(); ++it2) {
					auto it4 = it3;
					while (it4 != B.begin()) {
						count += (it2->first - i + 1) * (it4->first - cols + 1) * it2->second * it4->second;
						--it4;
					}
					count += (it2->first - i + 1) * (it4->first - cols + 1) * it2->second * it4->second;
				}
			}
		}
	}
	std::cout << count << '\n';
	return 0;
}
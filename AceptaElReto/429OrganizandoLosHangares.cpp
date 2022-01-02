#include <iostream>
#include <queue>
#include <string>

int main() {
	int H, N, x;
	std::string dump;
	bool posible;
	std::cin >> H;
	while (H != 0) {
		posible = true;
		std::priority_queue<int> pq;
		for (int i = 0; i < H; ++i) {
			std::cin >> x;
			pq.push(x);
		}
		std::cin >> N;
		for (int i = 0; i < N && posible; ++i) {
			std::cin >> x;
			if (x <= pq.top()) {
				pq.push(pq.top() - x);
				pq.pop();
			}
			else posible = false;
		}
		getline(std::cin, dump);
		if (posible) std::cout << "SI\n";
		else std::cout << "NO\n";
	std::cin >> H;
	}
return 0;
}
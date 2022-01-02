#include <iostream>
#include <vector>
#include <functional>//greater
#include <queue>

const std::vector<int> pots = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768 };

int main() {
	int m, n, best, est, rm, ok, c1, c2;
	std::cin >> m;
	while (m != 0) {
		std::cin >> n;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) std::cin >> v[i];

		best = 0;
		for (int i = 1; i <= pots[n]; ++i) {
			est = 0;
			for (int j = 0; j < n; ++j) {
				if (i & (1 << j)) est += v[j];
			}

			if (est > best && est <= m) {//podamos si no va a mejorar a la mejor encontrada hasta el momento
				std::priority_queue<int,std::vector<int>,std::greater<int>> pq;
				for (int j = 0; j < n; ++j) {
					if (i & (1 << j)) pq.push(v[j]);
				}

				rm = m;
				ok = true;
				while (ok && pq.size() > 1) {
					c1 = pq.top();
					pq.pop();
					c2 = pq.top();
					pq.pop();
					if (rm >= c1 + c2) {
						pq.push(c1 + c2);
						rm -= (c1 + c2);
					}
					else {
						ok = false;
						pq.push(c1);
						pq.push(c2);
					}
				}

				while (pq.size() > 1) pq.pop();
				if (pq.top() > best) best = pq.top();
			}
		}

		std::cout << best << '\n';
	std::cin >> m;
	}
return 0;
}
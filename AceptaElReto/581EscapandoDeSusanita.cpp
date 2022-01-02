#include <iostream>
#include <deque>

int main() {
	int t, n, m, pops;
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		std::deque<int> dq;
		for (int i = 1; i <= n; ++i) dq.push_back(i);

		while (n > 1) {
			pops = m % n;
			if(pops == 0) pops = m;
			if (pops <= n-pops+1) {
				for (int i = 1; i < pops; ++i) {
					dq.push_back(dq.front());
					dq.pop_front();
				}
				dq.pop_front();
			}
			else {
				pops = n - pops + 1;
				for (int i = 1; i < pops; ++i) {
					dq.push_front(dq.back());
					dq.pop_back();
				}
				dq.pop_back();
			}
		--n;
		}

		std::cout << dq.front() << '\n';
	}
return 0;
}
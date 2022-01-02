#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

bool resuelve() {
	int n, t;
	std::cin >> n >> t;

	if (n == 0) return false;

	std::vector<int> llegadas(n), duraciones(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> llegadas[i] >> duraciones[i];
	}

	int sol = 1, max = n, act;
	while (sol < max) {
		act = (sol + max - 1) / 2;

		std::priority_queue<int,std::vector<int>,std::greater<int>> cola;
		for (int i = 0; i < n && cola.size() <= act; ++i) {
			while (!cola.empty() && cola.top() <= llegadas[i]) cola.pop();
			
			if (cola.size() < act) cola.push(llegadas[i] + duraciones[i]);
			else if (cola.top() - llegadas[i] <= t) {
				cola.push(cola.top() + duraciones[i]);
				cola.pop();
			}
			else cola.push(llegadas[i] + duraciones[i]);
		}

		if (cola.size() <= act) max = act;
		else sol = act + 1;
	}

	std::cout << sol << '\n';
return true;
}

int main() {
	while (resuelve());
return 0;
}
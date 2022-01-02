#include <iostream>
#include <queue>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int nc, n, s, p, k, kills;
	bool iron, spidey;
	cin >> nc;
	while (nc--) {
		cin >> n >> s >> p >> k;
		queue<int> q;
		for (int i = 1; i <= n; ++i) q.push(i);

		if (n % 2) kills = n / 2 + 1;
		else kills = n / 2;

		spidey = iron = true;
		while (kills--) {
			for (int i = 0; i < k; ++i) {
				q.push(q.front());
				q.pop();
			}
			if (q.front() == s) iron = false;
			else if (q.front() == p) spidey = false;
			q.pop();
		}

		if (iron == spidey) cout << "No hay abrazo\n";
		else if (iron && !spidey) cout << "No quiero irme, Sr. Stark!\n";
		else cout << "No quiero irme, Peter!\n";
	}
}
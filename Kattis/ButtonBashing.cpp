#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define INF 1e9

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, t, act, next;
	cin >> tc;
	while (tc--) {
		cin >> n >> t;

		vector<int> opts(n);
		for (int i = 0; i < n; ++i) cin >> opts[i];

		vector<int> distTo(3601, INF);
		distTo[0] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			act = q.front();
			q.pop();

			for (int i = 0; i < n; ++i) {
				if (act + opts[i] > 3600) next = 3600;
				else if (act + opts[i] < 0) next = 0;
				else next = act + opts[i];

				if (distTo[next] == INF) {
					distTo[next] = 1 + distTo[act];
					q.push(next);
				}
			}
		}

		act = t;
		while (distTo[act] == INF) ++act;
		cout << distTo[act] << ' ' << act - t << '\n';
	}
	return 0;
}
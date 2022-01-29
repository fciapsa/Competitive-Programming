#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, m, id, cont, act;
	string a, b;
	cin >> tc;
	while (tc--) {
		cin >> m;
		vector<vector<int>> ady(3000);
		id = 0;
		unordered_map<string, int> mp;
		while (m--) {
			cin >> a >> b;
			if (mp.count(a) == 0)mp[a] = id++;
			if (mp.count(b) == 0)mp[b] = id++;
			ady[mp[a]].push_back(mp[b]);
			ady[mp[b]].push_back(mp[a]);
		}

		cont = 0;
		for (int i = 0; i < id; ++i) {
			vector<int> dist(id, 3001);
			dist[i] = 0;
			queue<int> q;
			q.push(i);
			bool stop = false;		
			while (!q.empty() && !stop) {
				act = q.front();
				q.pop();

				for (int v : ady[act]) {
					if (1 + dist[act] < dist[v]) {
						dist[v] = 1 + dist[act];
						q.push(v);
						if (dist[v] > 6) {
							++cont;
							stop = true;
						}
					}
				}
			}
		}

		if ((cont * 100.0) / id > 5.0) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
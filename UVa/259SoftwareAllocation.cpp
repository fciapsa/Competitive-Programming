#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define MAX_TASKS 234

int M, N;//M parte izquierda, N parte derecha
vector<vector<int>> grafo; // dirigido, tamaño M
vector<int> match, vis;

int aug(int l) {//devuelve 1 si encuentra un augmenting path
				//para el matching M representado en match
	if (vis[l]) return 0;
	vis[l] = 1;
	for (auto r : grafo[l]) {
		if (match[r] == -1 || aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;
	int task_id, n, total;
    getline(cin, s);
	M = 10;
	N = MAX_TASKS;//computers
    while (cin) {
		grafo.assign(10, {});
		total = 0;
        while (s != "") {
			task_id = (int(s[0]) - int('A')) * 9;
			n = int(s[1]) - int('0');
			total += n;
			for (int i = 0; i < n; ++i) {
				for (int j = 3; s[j] != ';'; ++j) {
					grafo[int(s[j] - int('0'))].push_back(task_id);
				}
				++task_id;
			}
            getline(cin, s);
        }

		int mcbm = 0;
		match.assign(N, -1);
		for (int l = 0; l < M; ++l) {
			vis.assign(M, 0);
			mcbm += aug(l);
		}
		if (mcbm != total) cout << "!\n";
		else {
			vector<char> sol(10, '_');
			for (int i = 0; i < match.size(); ++i) {
				if (match[i] != -1) sol[match[i]] = char(int('A') + i / 9);
			}
			for (int i = 0; i < 10; ++i) cout << sol[i];
			cout << '\n';
		}

    getline(cin, s);
    }
    return 0;
}
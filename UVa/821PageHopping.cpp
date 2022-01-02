#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int a, b, caso = 1, tot;
    cin >> a >> b;
    while (a != 0) {
        vector<vector<int>> dist(101, vector<int>(101, 101));
        unordered_set<int> conj;
        for (int i = 1; i < 101; ++i) dist[i][i] = 0;
        while (a != 0) {
            conj.insert(a);
            conj.insert(b);
            dist[a][b] = 1;
            cin >> a >> b;
        }

        for (int k = 1; k < 101; ++k) {
            for (int i = 1; i < 101; ++i) {
                for (int j = 1; j < 101; ++j) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        tot = 0;
        for (int i = 1; i < 101; ++i) {
            for (int j = 1; j < 101; ++j) {
                if (dist[i][j] < 101) tot += dist[i][j];
            }
        }

        cout << "Case " << caso++ << ": average length between pages = ";
        cout << fixed << setprecision(3) << (double)tot / (conj.size() * (conj.size() - 1));
        cout << " clicks\n";

    cin >> a >> b;
    }
    return 0;
}
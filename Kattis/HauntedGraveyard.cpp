#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FREE '.'
#define GRAVESTONE '#'
#define PORTAL 'o'
#define INF 1000000000

int f, c;

bool in(int x, int y) {
    return x >= 0 && y >= 0 && x < f&& y < c;
}

int npos(int x, int y) {
    return x * c + y;
}

struct edge {
    int from, to, cost;
};

int main() {
    std::ios::sync_with_stdio(false);
    int g, e, x1, y1, x2, y2, t;
    cin >> f >> c;
    while (f) {
        vector<vector<char>> mat(f, vector<char>(c, FREE));
        cin >> g;
        while (g--) {
            cin >> x1 >> y1;
            mat[x1][y1] = GRAVESTONE;
        }

        vector<edge> edges;
        cin >> e;
        while (e--) {
            cin >> x1 >> y1 >> x2 >> y2 >> t;
            edges.push_back({ npos(x1,y1), npos(x2,y2), t });
            mat[x1][y1] = PORTAL;
        }

        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                if (i == f - 1 && j == c - 1) continue;//no edges leaving destination
                if (mat[i][j] == FREE) {
                    if (in(i, j + 1) && mat[i][j + 1] != GRAVESTONE)
                        edges.push_back({ npos(i,j), npos(i,j + 1), 1 });
                    if (in(i + 1, j) && mat[i + 1][j] != GRAVESTONE)
                        edges.push_back({ npos(i,j), npos(i + 1,j), 1 });
                    if (in(i - 1, j) && mat[i - 1][j] != GRAVESTONE)
                        edges.push_back({ npos(i,j), npos(i - 1,j), 1 });
                    if (in(i, j - 1) && mat[i][j - 1] != GRAVESTONE)
                        edges.push_back({ npos(i,j), npos(i,j - 1), 1 });
                }
            }
        }

        //Bellman-Ford
        vector<int> d(f * c, INF);
        d[0] = 0;
        for (int i = 0; i < d.size() - 1; ++i) {
            for (int j = 0; j < edges.size(); ++j) {
                if (d[edges[j].from] < INF) {//this also ensures unreachable negative cycles are not considered
                    d[edges[j].to] = min(d[edges[j].to], d[edges[j].from] + edges[j].cost);
                }
            }
        }

        int dest = npos(f - 1, c - 1);
        //check for negative cycle
        bool neg_cycle = false;
        for (int j = 0; j < edges.size(); ++j) {
            if (d[edges[j].from] < INF) {
                if (d[edges[j].from] + edges[j].cost < d[edges[j].to])
                    neg_cycle = true;
            }
        }

        if (neg_cycle) cout << "Never\n";
        else if (d[dest] < INF) cout << d[dest] << '\n';
        else cout << "Impossible\n";

        cin >> f >> c;
    }
    return 0;
}
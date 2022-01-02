#include <bits/stdc++.h>

using namespace std;
#define ll long long

int V; // vértices del grafo completo
vector<vector<int>> dist; // matriz de adyacencia del grafo
vector<vector<int>> memo; // tabla de DP

struct pos {
    int x, y;
};

int distance(pos a, pos b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int tsp(int pos, int visitados) {
    if (visitados == (1 << V) - 1) // hemos visitado ya todos los vértices
        return dist[pos][0]; // volvemos al origen
    if (memo[pos][visitados] != -1)
        return memo[pos][visitados];
    int res = 1000000000; // INF
    for (int i = 1; i < V; ++i)
        if (!(visitados & (1 << i))) // no hemos visitado vértice i
            res = min(res, dist[pos][i] + tsp(i, visitados | (1 << i)));
    return memo[pos][visitados] = res;
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc, x, y, n;
    cin >> tc;
    while (tc--) {
        cin >> x >> y;
        vector<pos> vect;
        cin >> x >> y;
        vect.push_back({ x,y });
        cin >> n;
        V = n + 1;
        while (n--) {
            cin >> x >> y;
            vect.push_back({ x,y });
        }

        dist.assign(V, vector<int>(V, 0));
        // rellenamos la matriz de distancias entre vértices
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j) dist[i][j] = distance(vect[i], vect[j]);
        

        memo.assign(V, vector<int>(1 << V, -1));
        cout << "The shortest path has length " << tsp(0, 1) << '\n';
    }
    return 0;
}
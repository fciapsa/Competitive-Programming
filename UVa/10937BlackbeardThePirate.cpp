#include <bits/stdc++.h>

using namespace std;
#define ll long long

const vector<int> dx = { -1,-1,-1,0,1,1,1,0 }, dy = { -1,0,1,1,1,0,-1,-1 },
vx = { -1,0,1,0 }, vy = { 0,1,0,-1 };

int h, w;
int V; // vértices del grafo completo
vector<vector<int>> dist; // matriz de adyacencia del grafo
vector<vector<int>> memo; // tabla de DP

struct pos {
    int x, y;
};

struct nodo {
    pos p;
    int d;
};

bool inside(int x,int y){
    return x >= 0 && y >= 0 && x < h && y < w;
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
    int x, y, cofres;
    cin >> h >> w;
    while (h != 0) {
        vector<string> mat(h);
        for (int i = 0; i < h; ++i) cin >> mat[i];

        pos pirate;
        vector<pos> treasures;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (mat[i][j] == '@') {
                    pirate.x = i;
                    pirate.y = j;
                }
                else if (mat[i][j] == '!') {
                    treasures.push_back({ i,j});
                }
            }
        }

            bool death = false;
            char c = '0';
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    if (mat[i][j] == '*') {
                        for (int k = 0; k < 8; ++k) {
                            x = i + dx[k];
                            y = j + dy[k];
                            if (inside(x, y)) {
                                if (mat[x][y] == '@' || mat[x][y] == '!') death = true;
                                else if (mat[x][y] != '*') mat[x][y] = '#';
                            }
                        }
                        mat[i][j] = '#';
                    }
                    else if (mat[i][j] == '!') mat[i][j] = c++;//marcar los cofres como 0,1,2,...
                }
            }

            if (death) cout << "-1\n";
            else if (treasures.size() == 0) cout << "0\n";
            else {
                V = treasures.size() + 1;//cofres + pirata(el 0)
                dist.assign(V, vector<int>(V, -1));

                int reached = 0;
                nodo act = { pirate, 0 };
                vector<vector<bool>> visited(h, vector<bool>(w, false));
                visited[pirate.x][pirate.y] = true;
                queue<nodo> q;
                q.push(act);
                while (!q.empty()) {
                    act = q.front();
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        x = act.p.x + vx[k];
                        y = act.p.y + vy[k];

                        if (inside(x, y) && !visited[x][y]) {
                            if (mat[x][y] == '#' || mat[x][y] == '~') visited[x][y] = true;
                            else if (mat[x][y] == '.') {
                                visited[x][y] = true;
                                q.push({ {x,y},act.d + 1 });
                            }
                            else {
                                int id = int(mat[x][y]) - int('0') + 1;
                                visited[x][y] = true;
                                ++reached;
                                dist[0][id] = act.d + 1;
                                q.push({ { x,y }, act.d + 1 });
                            }
                        }
                    }
                }
                if (reached != V - 1) cout << "-1\n";
                else {

                    // rellenamos la matriz de distancias entre vértices
                    for (int i = 1; i < V; ++i) {
                        act = { treasures[i - 1], 0 };
                        visited.assign(h, vector<bool>(w, false));
                        q.push(act);
                        visited[act.p.x][act.p.y] = true;
                        while (!q.empty()) {
                            act = q.front();
                            q.pop();

                            for (int k = 0; k < 4; ++k) {
                                x = act.p.x + vx[k];
                                y = act.p.y + vy[k];

                                if (inside(x, y) && !visited[x][y]) {
                                    if (mat[x][y] == '#' || mat[x][y] == '~') visited[x][y] = true;
                                    else if (mat[x][y] == '.') {
                                        visited[x][y] = true;
                                        q.push({ {x,y},act.d + 1 });
                                    }
                                    else if (mat[x][y] == '@') {
                                        visited[x][y] = true;
                                        dist[i][0] = act.d + 1;
                                        q.push({ { x,y }, act.d + 1 });
                                    }
                                    else {
                                        int id = int(mat[x][y]) - int('0') + 1;
                                        visited[x][y] = true;
                                        dist[i][id] = act.d + 1;
                                        q.push({ { x,y }, act.d + 1 });
                                    }
                                }
                            }
                        }
                    }
                    memo.assign(V, vector<int>(1 << V, -1));
                    cout << tsp(0, 1) << '\n';
                }
            }

        cin >> h >> w;
    }
    return 0;
}
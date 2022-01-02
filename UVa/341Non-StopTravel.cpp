#include <bits/stdc++.h>

using namespace std;
#define ll long long

void printPath(int a, int b, vector<vector<int>> const& camino) {
   
    if (camino[a][b] != -1) {
        printPath(a, camino[a][b], camino);
        printPath(camino[a][b], b, camino);
    }
    else cout << ' ' << b;
}

int main() {
    std::ios::sync_with_stdio(false);
    int ni, e, dest, cost, ini, fin, caso = 1;
    cin >> ni;
    while (ni != 0) {
        vector<vector<int>> distTo(ni + 1, vector<int>(ni + 1, 1e9));
        vector<vector<int>> camino(ni + 1, vector<int>(ni + 1, -1));

        for (int i = 1; i <= ni; ++i) {
            cin >> e;
            while (e--) {
                cin >> dest >> cost;
                distTo[i][dest] = cost;
            }
        }
        cin >> ini >> fin;

        for (int i = 1; i <= ni; ++i) distTo[i][i] = 0;

        for (int k = 1; k <= ni; k++) {
            for (int i = 1; i <= ni; i++) {
                for (int j = 1; j <= ni; j++) {
                    if (distTo[i][k] + distTo[k][j] < distTo[i][j]) {
                        distTo[i][j] = distTo[i][k] + distTo[k][j];
                        camino[i][j] = k;
                    }
                }
            }
        }

        cout << "Case " << caso++ << ": Path = " << ini;
        printPath(ini, fin, camino);
        cout << "; " << distTo[ini][fin] << " second delay\n";

    cin >> ni;
    }
    return 0;
}
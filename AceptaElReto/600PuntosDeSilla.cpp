#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;
#define ll long long

int main() {
    int f, c, max, min;
    cin >> f >> c;
    while (f != 0) {
        vector<int> minFila(f), maxFila(f), minCol(c), maxCol(c);
        vector<vector<int>> mat(f, vector<int>(c));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) cin >> mat[i][j];
        }

        for (int i = 0; i < f; ++i) {
            min = INT_MAX;
            max = INT_MIN;
            for (int j = 0; j < c; ++j) {
                if (mat[i][j] < min) min = mat[i][j];
                if (mat[i][j] > max) max = mat[i][j];
            }
            maxFila[i] = max;
            minFila[i] = min;
        }

        for (int j = 0; j < c; ++j) {
            min = INT_MAX;
            max = INT_MIN;
            for (int i = 0; i< f; ++i) {
                if (mat[i][j] < min) min = mat[i][j];
                if (mat[i][j] > max) max = mat[i][j];
            }
            maxCol[j] = max;
            minCol[j] = min;
        }

        bool silla = false;
        for (int i = 0; i < f && !silla; ++i) {
            for (int j = 0; j < c && !silla; ++j) {
                if (mat[i][j] == maxFila[i] && mat[i][j] == minCol[j]) silla = true;
                else if (mat[i][j] == minFila[i] && mat[i][j] == maxCol[j]) silla = true;
            }
        }

        if (silla) cout << "SI\n";
        else cout << "NO\n";

    cin >> f >> c;
    }
return 0;
}
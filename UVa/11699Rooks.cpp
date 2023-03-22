#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ll long long
#define N 15

int main() {
    std::ios::sync_with_stdio(false);
    vector<string> mat(N);
    cin >> mat[0];
    while (mat[0] != "END") {
        for (int i = 1; i < N; ++i) cin >> mat[i];
        
        int ans = 15, total = (1 << N);
        for (int i = 0; i < total; ++i) {
            int rooks = 0, aux = i;
            int x = 0;
            vector<int> rook_rows;
            while (aux) {
                if (aux % 2) {
                    rook_rows.push_back(x);
                    ++rooks;
                }
                ++x;
                aux >>= 1;
            }

            if (rooks >= ans) continue;
            //check if placing rooks on the rows indicated by the bitmask "i" is sufficient
            vector<string> mat2 = mat;
            for (int k = 0; k < rook_rows.size(); ++k) {
                for (int j = 0; j < N; ++j) mat2[rook_rows[k]][j] = '.';
            }
            int colsToCover = 0;
            for (int j = 0; j < N; ++j) {
                bool toCover = false;
                for (int i = 0; i < N && !toCover; ++i) {
                    toCover = mat2[i][j] == '#';
                }
                if (toCover) ++colsToCover;
            }

            if (colsToCover > rooks) continue;
            ans = rooks;
        }
        cout << ans << '\n';
        cin >> mat[0];
    }

    return 0;
}
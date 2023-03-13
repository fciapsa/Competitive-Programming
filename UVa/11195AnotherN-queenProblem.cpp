#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll ans, finished;
vector<string> mat;

//We use 3 bitmasks to represent the state: free(==0) rows, free left-diagonals and free right-diagonals
void backtrack(int rows, int lds, int rds, int curr_col) {
    if (rows == finished) {
        ++ans;
        return;
    }

    int options = finished & (~(rows | lds | rds));

    while (options) {
        int pos = options & (-options);
        options -= pos;
        if (mat[__builtin_ctz(pos)][curr_col] == '*') continue;
        backtrack(rows | pos, (lds | pos) << 1, (rds | pos) >> 1, curr_col+1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, tc = 1;
    cin >> n;
    while (n) {
        mat.assign(n, "");
        for (int i = 0; i < n; ++i) cin >> mat[i];

        ans = 0; finished = (1 << n) - 1;
        backtrack(0, 0, 0, 0);

        cout << "Case " << tc++ << ": " << ans << '\n';
        cin >> n;
    }

    return 0;
}
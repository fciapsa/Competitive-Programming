#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct ranges {
    int fr, lr, fc, lc;
};

int main() {
    std::ios::sync_with_stdio(false);
    int tc, c, f;
    cin >> tc;
    while (tc--) {
        cin >> c >> f;
        vector<vector<char>> mat(f, vector<char>(c));
        map<char, ranges> mp;
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> mat[i][j];
                if (mp.count(mat[i][j]) == 0) {
                    mp[mat[i][j]].fr = i;
                    mp[mat[i][j]].lr = i;
                    mp[mat[i][j]].fc = j;
                    mp[mat[i][j]].lc = j;
                }
                mp[mat[i][j]].lr = i;
                mp[mat[i][j]].fc = min(j, mp[mat[i][j]].fc);
                mp[mat[i][j]].lc = max(j, mp[mat[i][j]].lc);
            }
        }
        mp.erase('.');

        if (mp.size()) {

            vector<vector<char>> capas;
            bool change = true;
            int round = 0;
            while (change && mp.size()) {
                change = false;
                capas.push_back({});

                for (auto cv : mp) {
                    bool ok = true;
                    for (int i = cv.second.fr; i <= cv.second.lr && ok; ++i) {
                        for (int j = cv.second.fc; j <= cv.second.lc && ok; ++j) {
                            if (mat[i][j] != '.' && mat[i][j] != cv.first) ok = false;
                        }
                    }

                    if (ok) capas[round].push_back(cv.first);

                }

                if (capas[round].size()) {
                    for (char c : capas[round]) {
                        for (int i = mp[c].fr; i <= mp[c].lr; ++i) {
                            for (int j = mp[c].fc; j <= mp[c].lc; ++j) {
                                mat[i][j] = '.';
                            }
                        }
                        mp.erase(c);
                    }
                    change = true;
                }
                ++round;
            }

            if (mp.size()) cout << "IMPOSIBLE\n";
            else {
                for (int i = 0; i < capas.size(); ++i) {
                    sort(capas[i].begin(), capas[i].end());
                    cout << capas[i][0];
                    for (int j = 1; j < capas[i].size(); ++j) cout << ' ' << capas[i][j];
                    cout << '\n';
                }
            }

        }
        cout << "----\n";

    }

    return 0;
}
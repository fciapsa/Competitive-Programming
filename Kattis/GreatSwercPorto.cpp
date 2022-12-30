#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<string> mat;
int n, ans = 0, col_sum = 0;
vector<bool> used(10, false);
map<char, int> mp;

void bt(int row, int col) {
    char act = mat[row][col];

    if (row == n - 1) {//result
        if (col == 0) {
            if (col_sum > 9 || col_sum == 0) return;
            else {
                if ((mp.count(act) && mp[act] == col_sum) ||
                    (mp.count(act) == 0 && !used[col_sum])) ++ans;
            }
        }
        else {
            if(mp.count(act)){
                if (col_sum%10 != mp[act]) return;
                int aux = col_sum;
                col_sum /= 10;
                bt(0, col - 1);
                col_sum = aux;
            }
            else {
                if (used[col_sum % 10]) return;
                mp[act] = col_sum % 10;
                used[col_sum % 10] = true;
                int aux = col_sum;
                col_sum /= 10;
                bt(0, col - 1);
                col_sum = aux;
                mp.erase(act);
                used[col_sum % 10] = false;
            }
        }
    }
    else {//operands
        if (act == 'x') bt(row + 1, col);
        else if (mp.count(act)) {
            if (mp[act] == 0 && col == 0) return;
            col_sum += mp[act];
            bt(row + 1, col);
            col_sum -= mp[act];
        }
        else {
            for (int i = 0; i < 10; ++i) {
                if (i == 0 && (col == 0 || mat[row][col-1] == 'x')) continue;
                if (!used[i]) {
                    used[i] = true;
                    mp[act] = i;
                    col_sum += i;
                    bt(row + 1, col);
                    col_sum -= i;
                    used[i] = false;
                }
            }
            mp.erase(act);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    mat.assign(n, "");
    for (int i = 0; i < n; ++i) cin >> mat[i];

    for (int i = 0; i < n - 1; ++i) {
        while (mat[i].size() < mat[n - 1].size()) mat[i] = "x" + mat[i];
    }

    bt(0, mat[n - 1].size() - 1);
    cout << ans << '\n';

    return 0;
}
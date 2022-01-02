#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int r, c, ans;
    cin >> r >> c;
    vector<string> mat(r);
    for (int i = 0; i < r; ++i) cin >> mat[i];
    int x = 0, y = 0;
    
    vector<vector<bool>> marked(r, vector<bool>(c, false));
    marked[0][0] = true;
    ans = 0;
    bool found = mat[x][y] == 'T', out = false, rep = false;
    while (!found && !out && !rep) {
        switch (mat[x][y]) {
        case 'N': 
            if (x > 0) {
                --x;
                ++ans;
                if (marked[x][y]) rep = true;
                else marked[x][y] = true;
            }
            else out = true;
            break;
        case 'S': 
            if (x < r-1) {
                ++x;
                ++ans;
                if (marked[x][y]) rep = true;
                else marked[x][y] = true;
            }
            else out = true;
            break;
        case 'W': 
            if (y > 0) {
                --y;
                ++ans;
                if (marked[x][y]) rep = true;
                else marked[x][y] = true;
            }
            else out = true;
            break;
        case 'E': 
            if (y < c-1) {
                ++y;
                ++ans;
                if (marked[x][y]) rep = true;
                else marked[x][y] = true;
            }
            else out = true;
            break;
        case 'T': found = true;
            break;
       }
    }

    if (out) cout << "Out\n";
    else if (rep) cout << "Lost\n";
    else cout << ans << '\n';

    return 0;
}
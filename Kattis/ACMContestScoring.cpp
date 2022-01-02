#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int m, solved = 0, pen = 0;
    char p;
    string s;
    vector<int> v(256);

    cin >> m;
    while (m != -1) {
        cin >> p >> s;
        if (s[0] == 'w') ++v[p];
        else {
            ++solved;
            pen += m + 20 * v[p];
        }
        cin >> m;
    }

    cout << solved << ' ' << pen << '\n';

    return 0;
}
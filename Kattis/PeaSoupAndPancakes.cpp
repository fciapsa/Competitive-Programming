#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;
    string s, ans = "";
    cin >> n;
    vector<string> names(n);
    vector<set<string>> dishes(n);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        getline(cin, s);//skip to eol
        getline(cin, s);
        names[i] = s;
        for (int j = 0; j < k; ++j) {
            getline(cin, s);
            dishes[i].insert(s);
        }
        if (ans == "" && dishes[i].count("pea soup") && dishes[i].count("pancakes")) ans = names[i];
    }
    if (ans == "") cout << "Anywhere is fine I guess\n";
    else cout << ans << '\n';
    return 0;
}
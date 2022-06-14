#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct animal {
    int m, f;
};

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    bool m;
    cin >> n;
    while (n) {
        string s;
        map<string, animal> mp;
        while (n--) {
            cin >> s;
            if (s[s.size() - 1] == 'o') m = true;
            else m = false;
            s.pop_back();
            if (m) ++mp[s].m;
            else ++mp[s].f;
        }

        int comp = 0, incomp = 0, sobra = 0;
        for (auto it : mp) {
            if (it.second.f && it.second.m) {
                ++comp;
                sobra += it.second.m - 1 + it.second.f - 1;
            }
            else {
                ++incomp;
                sobra += max(0,it.second.m - 1) + max(0,it.second.f - 1);
            }
        }

        cout << comp << ' ' << incomp << ' ' << sobra << '\n';
        cin >> n;
    }

    return 0;
}
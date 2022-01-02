#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc;
    string s;
    bool bad, can;
    cin >> tc;
    while (tc--) {
        cin >> s;
        bad = false;
        can = true;
        for (int i = s.size() - 2; i >= 0 && can; --i) {
            if (!bad) bad = s[i] == '0' && s[i + 1] == '0';
            else can = s[i] != '1' || s[i + 1] != '1';
        }
        if (can) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
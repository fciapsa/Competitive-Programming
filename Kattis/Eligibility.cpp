#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, yy1, yy2, aux, co;
    char c;
    string name;
    cin >> tc;
    while (tc--) {
        cin >> name >> yy1 >> c >> aux >> c >> aux >> yy2 >> c >> aux >> c >> aux >> co;

        cout << name << ' ';
        if (yy1 >= 2010 || yy2 >= 1991) {
            cout << "eligible\n";
        }
        else if (co > 40) cout << "ineligible\n";
        else cout << "coach petitions\n";
    }

    return 0;
}
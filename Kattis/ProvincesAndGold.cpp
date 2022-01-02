#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int g, s, c, tot;
    cin >> g >> s >> c;
    tot = 3 * g + 2 * s + c;
    if (tot >= 2) {
        if (tot >= 8) cout << "Province";
        else if (tot >= 5) cout << "Duchy";
        else cout << "Estate";
        cout << " or ";
    }
    if (tot >= 6) cout << "Gold\n";
    else if (tot >= 3) cout << "Silver\n";
    else cout << "Copper\n";
    return 0;
}
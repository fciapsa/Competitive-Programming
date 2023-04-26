#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, total, cap, ret, aux;
    cin >> tc;
    while (tc--) {
        cin >> total >> cap >> ret;
        if (total <= cap) cout << "1\n";
        else if (ret >= cap) cout << "IMPOSIBLE\n";
        else {
            total -= cap;
            cout << 1 + total / (cap - ret) + (total%(cap-ret) ? 1 : 0) << '\n';
        }    
    }

    return 0;
}
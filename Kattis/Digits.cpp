#include <bits/stdc++.h>

using namespace std;
#define ll long long

int digits(int n) {
    if (n == 0) return 1;
    int ans = 0;
    while (n > 0) {
        ++ans;
        n /= 10;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    int prev, act, ans;
    cin >> s;
    while (s != "END") {
        if (s.size() <= 9) {
            prev = stoi(s);
            ans = 1;
        }
        else {
            prev = s.size();
            ans = 2;
        }
        act = digits(prev);

        while (act != prev) {
            ++ans;
            prev = act;
            act = digits(prev);
        }
        cout << ans << '\n';
    cin >> s;
    }

    return 0;
}
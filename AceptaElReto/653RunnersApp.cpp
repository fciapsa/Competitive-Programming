#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, x, act, best, bi;
    cin >> n;
    while (n) {
        act = 0;
        queue<int> q;
        for (int i = 0; i < 10; ++i) {
            cin >> x;
            q.push(x);
            act += x;
        }

        best = act;
        bi = 0;
        n -= 10;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            act -= q.front();
            q.pop();
            act += x;
            q.push(x);
            if (act <= best) {
                bi = i;
                best = act;
            }
        }

        cout << bi * 100 << '-' << bi * 100 + 1000 << ' ';
        cout << best / 60 << ':' << setw(2) << setfill('0') << best % 60 << '\n';

        cin >> n;
    }

    return 0;
}
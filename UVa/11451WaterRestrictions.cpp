#include <bits/stdc++.h>

using namespace std;
#define ll long long

int L, S, C, ans;
vector<int> pos, maxc, ones;

void bt(int act, int mask, int accum) {
    if (accum > C) return;

    if (act == S) {
        if (ones[mask] > ans) ans = ones[mask];
        return;
    }

    int addition = 0;
    for (int i = 0; i <= maxc[act] && ans != L;) {
        bt(act + 1, mask | addition, accum + i);
        ++i;
        if (i == 1) addition |= (1 << pos[act]);
        addition |= (1 << (pos[act] - i));
        addition |= (1 << (pos[act] + i));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int highest = (1 << 20);
    ones.assign(highest, 0);
    for (int i = 0; i < highest; ++i) {
        int count = 0, num = i;
        while (num) {
            if (num % 2) ++count;
            num >>= 1;
        }
        ones[i] = count;
    }

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> L >> S;
        pos.assign(S, 0);
        for (int i = 0; i < S; ++i) {
            cin >> pos[i];
            --pos[i];
        }
        cin >> C;
        maxc.assign(S, 0);
        for (int i = 0; i < S; ++i) cin >> maxc[i];
        ans = 0;
        bt(0, 0, 0);
        cout << ans << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, best, pre;
    string obj, act;
    vector<string> suggs(3);
    cin >> tc;
    while (tc--) {
        cin >> obj >> act;
        for (int i = 0; i < 3; ++i) cin >> suggs[i];
        best = 100;

        pre = 0;
        for (int i = 0; i < obj.size() && i < act.size() && obj[i] == act[i]; ++i) ++pre;

        if (pre == obj.size()) best = min(best, int(act.size() - obj.size()));
        else best = min(best, int(act.size() - pre + obj.size() - pre));
        
        for (int i = 0; i < 3; ++i) {
            pre = 0;
            for (int j = 0; j < obj.size() && j < suggs[i].size() && obj[j] == suggs[i][j]; ++j) ++pre;

            if (pre == obj.size()) best = min(best, 1 + int(suggs[i].size() - obj.size()));
            else best = min(best, 1 + int(suggs[i].size() - pre + obj.size() - pre));
        }

        cout << best << '\n';
    }

    return 0;
}
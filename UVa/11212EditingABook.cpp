#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
#define ll long long

struct nodo {
    string state;
    int orig;//0 if originated from start, 1 if originated from target
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, tc = 1;
    cin >> n;
    while (n) {
        string start = "", target = "";
        char c;
        for (int i = 1; i <= n; ++i) {
            cin >> c;
            start.push_back(c);
            target.push_back(char('0' + i));
        }
        
        int ans = 10;
        bool found = false;
        if (start == target) {
            ans = 0;
            found = true;
        }
        unordered_map<string, pair<int,int>> dist_orig;
        dist_orig[start] = { 0, 0 };
        dist_orig[target] = { 0, 1 };
        queue<nodo> q;
        q.push({ start, 0 });
        q.push({ target, 1 });
        while (!found) { //target is always reachable
            nodo act = q.front();
            q.pop();

            string state = act.state;
            int orig = act.orig;
            for (int i = 0; i < n; ++i) { //cut [i,j] and paste it at position k
                for (int j = i; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        if (k >= i && k <= j) continue;

                        string aux = state;
                        int len = j - i + 1;
                        string cut = aux.substr(i, len);
                        aux.insert(k, cut);
                        if (k < i) aux.erase(i + len, len);
                        else aux.erase(i, len);

                        auto it = dist_orig.find(aux);
                        if (it != dist_orig.end()) {
                            if (it->second.second != orig) {
                                ans = it->second.first + dist_orig[state].first + 1;
                                found = true;
                            }
                        }
                        else {
                            dist_orig[aux] = { dist_orig[state].first + 1, orig };
                            q.push({ aux, orig });
                        }
                    }
                }
            }
        }

        cout << "Case " << tc++ << ": " << ans << '\n';
        cin >> n;
    }
    return 0;
}
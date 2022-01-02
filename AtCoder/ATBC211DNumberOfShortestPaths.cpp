#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <utility>
#include <queue>

using namespace std;
#define ll long long

const ll MOD = 1000000007;

struct par {
    ll v, c;
    bool operator<(par const& other)const {
        return c > other.c;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    ll v, e, a, b;
    cin >> v >> e;
    vector<vector<ll>> adyList(v + 1);

    for (int i = 0; i < e; ++i) {
        cin >> a >> b;
        adyList[a].push_back(b);
        adyList[b].push_back(a);
    }

    vector<ll> distTo(v + 1, 1000000000);
    vector<ll> cto(v + 1);
    cto[1] = 1;
    distTo[1] = 0;
    priority_queue<par> pq;
    pq.push({ 1,0 });
    par p;
    while (!pq.empty()) {
        p = pq.top();
        pq.pop();

        if (distTo[p.v] < p.c) continue;

        for (int w : adyList[p.v]) {
            if (distTo[w] > distTo[p.v] + 1) {
                distTo[w] = distTo[p.v] + 1;
                pq.push({ w, distTo[w] });
                cto[w] = cto[p.v];
            }
            else if (distTo[w] == distTo[p.v] + 1) cto[w] = (cto[w] + cto[p.v]) % MOD;
        }
    }

    cout << cto[v] << '\n';

    return 0;
}
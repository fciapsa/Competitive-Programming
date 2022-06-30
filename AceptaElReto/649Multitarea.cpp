#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct tarea {
    int ini, fin, per;
    bool operator<(tarea const& o) const {
        return ini > o.ini;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, t, ini, fin, per;
    bool ok;
    tarea act;
    cin >> n;
    while (cin) {
        cin >> m >> t;

        priority_queue<tarea> pq;
        while (n--) {
            cin >> ini >> fin;
            pq.push({ ini,fin,0 });
        }
        while (m--) {
            cin >> ini >> fin >> per;
            pq.push({ ini,fin, per});
        }

        ok = true;
        while (pq.size() > 1 && ok && pq.top().ini < t) {
            act = pq.top();
            pq.pop();

            if (pq.top().ini < act.fin && pq.top().ini < t) ok = false;

            if (act.per) pq.push({ act.ini + act.per, act.fin + act.per, act.per });
        }

        if (ok) cout << "NO\n";
        else cout << "SI\n";

        cin >> n;
    }

    return 0;
}
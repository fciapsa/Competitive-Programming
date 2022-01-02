#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct nodo {
    int v, d;
};

int main() {
    std::ios::sync_with_stdio(false);
    int e, id, idini, idfin, aux, now, next;
    bool first = true;
    string a, b, ini, fin;
    cin >> e;
    while (cin) {
        map<string, int> mp;
        vector<string> names;
        vector<vector<int>> adyList;
        id = 0;
        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            if (mp.count(a) == 0) {
                adyList.push_back({});
                mp[a] = id++;
                names.push_back(a);
            }
            if (mp.count(b) == 0) {
                adyList.push_back({});
                mp[b] = id++;
                names.push_back(b);
            }
            adyList[mp[a]].push_back(mp[b]);
            adyList[mp[b]].push_back(mp[a]);
        }

        cin >> ini >> fin;
        if (mp.count(ini) == 0) {
            adyList.push_back({});
            mp[ini] = id++;
            names.push_back(ini);
        }
        if (mp.count(fin) == 0) {
            adyList.push_back({});
            mp[fin] = id++;
            names.push_back(fin);
        }

        idini = mp[ini];
        idfin = mp[fin];
        vector<bool> visited(names.size(), false);
        vector<int> edgeTo(names.size(), -1);
        visited[idini] = true;
        edgeTo[idini] = idini;
        queue<nodo> q;
        q.push({ idini, 0 });
        nodo act;
        while (!q.empty() && !visited[idfin]) {
            act = q.front();
            q.pop();

            for (int w : adyList[act.v]) {
                if (!visited[w]) {
                    visited[w] = true;
                    edgeTo[w] = act.v;
                    q.push({ w, act.d + 1 });
                }
            }
        }

        if (!visited[idfin]) {
            if (first) first = false;
            else cout << '\n';
            cout << "No route\n";
        }
        else {
            stack<int> pila;
            pila.push(idfin);
            aux = idfin;
            while (edgeTo[aux] != aux) {
                pila.push(edgeTo[aux]);
                aux = edgeTo[aux];
            }

            if (first) first = false;
            else cout << '\n';
            now = pila.top();
            pila.pop();
            next = pila.top();
            pila.pop();
            cout << names[now] << ' ' << names[next] << '\n';
            now = next;
            while (!pila.empty()) {
                next = pila.top();
                pila.pop();
                cout << names[now] << ' ' << names[next] << '\n';
                now = next;
            }
        }

    cin >> e;
    }
return 0;
}
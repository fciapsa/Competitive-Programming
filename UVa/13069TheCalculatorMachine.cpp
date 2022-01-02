#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct nodo {
    int val, d;
};

int main() {
    std::ios::sync_with_stdio(false);
    int a, b, aux, sol;
    nodo act;
    cin >> a >> b;
    while (cin) {
        vector<bool> visited(10000, false);
        visited[a] = true;
        queue<nodo> q;
        q.push({ a,0 });
        sol = 0;//if a == b
        while (!q.empty() && !visited[b]) {
            act = q.front();
            q.pop();

            aux = (act.val + 1) % 10000;
            if (aux == b) {
                sol = act.d + 1;
                visited[aux] = true;
            }
            else {
                if (!visited[aux]) {
                    visited[aux] = true;
                    q.push({ aux,act.d + 1 });
                }
                aux = (act.val * 2) % 10000;
                if (aux == b) {
                    sol = act.d + 1;
                    visited[aux] = true;
                }
                else {
                    if (!visited[aux]) {
                        visited[aux] = true;
                        q.push({ aux,act.d + 1 });
                    }
                    aux = (act.val / 3) % 10000;
                    if (aux == b) {
                        sol = act.d + 1;
                        visited[aux] = true;
                    }
                    else if (!visited[aux]) {
                        visited[aux] = true;
                        q.push({ aux,act.d + 1 });
                    }
                }
            }
        }
        cout << sol << '\n';

        cin >> a >> b;
    }

    return 0;
}
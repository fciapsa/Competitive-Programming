#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct par {
    int s[3];
    int dist;
    bool operator<(par const& other) const {
        return dist > other.dist;
    }
};

int third(int i, int j) {
    switch (i) {
    case 0:
        switch (j) {
        case 1: return 2; break;
        case 2: return 1; break;
        }break;
    case 1:
        switch (j) {
        case 0: return 2; break;
        case 2: return 0; break;
        }break;
    case 2:
        switch (j) {
        case 0: return 1; break;
        case 1: return 0; break;
        }break;
    }
}

int main() {   
    std::ios::sync_with_stdio(false);
    int tc, d, trasvase, cost, resto;
    int cap[3];
    int next[3];
    par act;
    cin >> tc;
    while (tc--) {
        cin >> cap[0] >> cap[1] >> cap[2] >> d;

        vector<vector<int>> dist(cap[0]+1, vector<int>(cap[1] + 1, 2e9));

        dist[0][0] = 0;//a y b estan vacias, c esta llena
        priority_queue<par> pq;
        pq.push({ {0,0,cap[2]},0 });
        while (!pq.empty()) {
            act = pq.top();
            pq.pop();

            if (act.dist > dist[act.s[0]][act.s[1]]) continue;

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (i != j) {//de jarra i a jarra j
                        if (act.s[i] > 0 && act.s[j] < cap[j]) {
                            next[third(i, j)] = act.s[third(i, j)];
                            trasvase = min(act.s[i], cap[j] - act.s[j]);
                            next[i] = act.s[i] - trasvase;
                            next[j] = act.s[j] + trasvase;

                            cost = act.dist + trasvase;
                            if (cost < dist[next[0]][next[1]]) {
                                dist[next[0]][next[1]] = cost;
                                pq.push({ {next[0], next[1], next[2]}, cost });
                            }
                        }
                    }
                }
            }
        } 

        cost = 2e9;
        while (cost == 2e9) {
            if (d <= cap[2]) {
                for (int i = 0; i <= cap[0]; ++i) {
                    resto = cap[2] - d - i;
                    if (resto >= 0 && resto <= cap[1]) cost = min(cost, dist[i][resto]);
                }                    
            }

            if (d <= cap[0]) {
                for (int j = 0; j <= cap[1]; ++j) {
                    resto = cap[2] - d - j;
                    if (resto >= 0 && resto <= cap[2]) cost = min(cost, dist[d][j]);
                }
            }

            if (d <= cap[1]) {
                for (int i = 0; i <= cap[0]; ++i) {
                    resto = cap[2] - d - i;
                    if (resto >= 0 && resto <= cap[2]) cost = min(cost, dist[i][d]);
                }
            }

            if (cost == 2e9) --d;
        }

        cout << cost << ' ' << d << '\n';
    }
    return 0;
}
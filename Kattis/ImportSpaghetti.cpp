#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define INF 1e9

unordered_map<string, int> mp;
unordered_map<int, string> mpi;
bool first = true;

void showCycle(int from, int to, vector<vector<int>> const& dist, vector<vector<int>> const& marks) {
    if (marks[from][to] != -1) {
        showCycle(from, marks[from][to], dist, marks);
        showCycle(marks[from][to], to, dist, marks);
    }
    else {
        if (first) first = false;
        else cout << ' ';
        cout << mpi[from];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        mp[s] = i;
        mpi[i] = s;
    }

    vector<vector<int>> dist(n, vector<int>(n, INF));
    int e;
    for (int i = 0; i < n; ++i) {
        cin >> s >> e;
        for (int j = 0; j < e; ++j) {
            cin >> s;//read "import"
            bool rep;
            do {
                cin >> s;
                rep = false;
                if (s[s.size() - 1] == ',') {
                    rep = true;
                    s.pop_back();
                }
                dist[i][mp[s]] = 1;
            } while (rep);
        }
    }

    vector<vector<int>> marks(n, vector<int>(n, -1));
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    marks[i][j] = k;
                }
            }
        }
    }

    int mn = INF, croot;
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < mn) {
            mn = dist[i][i];
            croot = i;
        }
    }

    if (mn == INF) cout << "SHIP IT\n";
    else showCycle(croot, croot, dist, marks);

    return 0;
}
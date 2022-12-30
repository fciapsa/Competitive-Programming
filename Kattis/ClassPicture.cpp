#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;
#define ll long long

vector<string> names;
vector<int> pos;
unordered_map<string, unordered_set<string>> nope;

string nameAt(int ind) {
    for (int i = 0; i < names.size(); ++i)
        if (pos[i] == ind) return names[i];

    return "";
}

bool bt(int ind) {
    if (ind == names.size()) {
        for (int i = 0; i < names.size(); ++i) {
            for (int j = 0; j < names.size(); ++j) {
                if (pos[j] == i) {
                    if (i != 0) cout << ' ';
                    cout << names[j];
                    break;
                }
            }
        }
        cout << '\n';
        return true;
    }

    for (int i = 0; i < names.size(); ++i) {
        if (pos[i] == -1 && (ind == 0 || nope[names[i]].count(nameAt(ind - 1)) == 0)) {
            pos[i] = ind;
            if (bt(ind + 1)) return true;
            pos[i] = -1;
        }
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    while (cin) {
        names.resize(n);
        for (int i = 0; i < n; ++i) cin >> names[i];
        sort(names.begin(), names.end());


        cin >> m;
        string s1, s2;
        for (int i = 0; i < m; ++i) {
            cin >> s1 >> s2;
            nope[s1].insert(s2);
            nope[s2].insert(s1);
        }

        pos.assign(n, -1);
        if (!bt(0)) cout << "You all need therapy.\n";
        cin >> n;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAXN 5

class Trie {
public:
    int prefixes;
    int words;
    vector<Trie*> child;
    Trie() : prefixes(0), words(0), child(MAXN, nullptr) {}
    ~Trie() { for(int i = 0; i < MAXN; ++i) delete child[i]; }
    void add(vector<char> const& s, int i = 0) {
        if (i >= s.size()) ++words;
        else {
            Trie* t;
            if (child[s[i] - 'A'] == nullptr) {
                t = child[s[i] - 'A'] = new Trie();
                t->prefixes = 1;
            }
            else {
                t = child[s[i] - 'A'];
                t->prefixes++;
            }
            t->add(s, i + 1);
        }
    }
};

vector<int> guiones_desde;
int id;

int search(vector<char> const& s, int ind, Trie* t) {
    if (ind == s.size()) return t->words;
    int ret = 0;
    if (ind == guiones_desde[id]) {
        for (int i = 0; i < MAXN; ++i)
            if(t->child[i] != nullptr) ret += t->child[i]->prefixes;
        return ret;
    }

    int pos = s[ind] - 'A';
    if (pos < MAXN-1) {
        if (t->child[pos] != nullptr) ret += search(s, ind + 1, t->child[pos]);
        if (t->child[MAXN-1] != nullptr) ret += search(s, ind + 1, t->child[MAXN-1]);
    }
    else {
        for(int i = 0; i < MAXN; ++i) 
            if(t->child[i] != nullptr) ret += search(s, ind + 1, t->child[i]);
    }
    
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    while (cin) {
        vector<string> words(n);
        cin >> words[0];
        m = words[0].size();
        vector<pair<int, int>> guiones(m);
        for (int i = 0; i < m; ++i) guiones[i].second = i;
        for (int i = 0; i < m; ++i) if (words[0][i] == '-') ++guiones[i].first;

        for (int i = 1; i < n; ++i) {
            cin >> words[i];
            for (int j = 0; j < m; ++j) if (words[i][j] == '-') ++guiones[j].first;
        }

        sort(guiones.begin(), guiones.end());
        vector<vector<char>> perm_w(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                perm_w[j][i] = words[j][guiones[i].second];
                if (perm_w[j][i] == 'C') perm_w[j][i] = 'B';
                else if(perm_w[j][i] == 'G') perm_w[j][i] = 'C';
                else if(perm_w[j][i] == 'T') perm_w[j][i] = 'D';
                else if(perm_w[j][i] == '-') perm_w[j][i] = 'E';
            }
        }

        guiones_desde.assign(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = m - 1; j >= 0 && perm_w[i][j] == 'E'; --j)
                guiones_desde[i] = j;

        Trie* t = new Trie();
        for (int i = 0; i < n; ++i) t->add(perm_w[i]);

        if (guiones_desde[0] == 0) cout << n-1;
        else {
            id = 0;
            cout << search(perm_w[0], 0, t) - 1;
        }
        for (int i = 1; i < n; ++i) {
            if (guiones_desde[i] == 0) cout << ' ' << n-1;
            else {
                id = i;
                cout << ' ' << search(perm_w[i], 0, t) - 1;
            }
        }
        cout << '\n';

        cin >> n;
    }

    return 0;
}
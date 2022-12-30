#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX_LEN 10
#define MAXN 27

int h, w, ans = 0;
vector<string> mat;
vector<int> vx = { -1,0,1,0 };
vector<int> vy = { 0,1,0,-1 };

bool in(int x, int y) {
    return x >= 0 && y >= 0 && x < h&& y < w;
}

class Trie {
public:
    int prefixes; // num prefijos a los que pertenece el nodo
    int words; // num. palabras terminando en nodo
    vector<Trie*> child;
    Trie() : prefixes(0), words(0), child(MAXN, nullptr) {}
    ~Trie() { for (int i = 0; i < MAXN; ++i) delete child[i]; }

    void add(string const& s, int i = 0) {
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

vector<vector<bool>> visited;
void search(int x, int y, Trie* t) {
    if (t->words) {
        ans += t->words;
        t->words = 0;
    }

    Trie* aux = t;
    int nx, ny;
    for (int k = 0; k < 4; ++k) {
        nx = x + vx[k];
        ny = y + vy[k];
        if (in(nx, ny) && !visited[nx][ny]) {
            int pos = mat[nx][ny] - 'A';
            if (aux->child[pos] == nullptr) continue;
            visited[nx][ny] = true;
            search(nx, ny, aux->child[pos]);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> h >> w;
    mat.assign(h, "");
    for (int i = 0; i < h; ++i) cin >> mat[i];

    Trie t;
    int n; string s;
    cin >> n;
    while (n--) {
        cin >> s;
        t.add(s);
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            visited.assign(h, vector<bool>(w, false));
            visited[i][j] = true;
            if(t.child[mat[i][j] - 'A'] != nullptr)
                search(i, j, t.child[mat[i][j] - 'A']);
        }
    }

    cout << ans << '\n';
    return 0;
}
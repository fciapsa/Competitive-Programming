#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAXN 26

vector<int> vx = { -1,-1,0,1,1,1,0,-1 };
vector<int> vy = { 0,1,1,1,0,-1,-1,-1 };

vector<vector<char>> bog(4, vector<char>(4));
vector<vector<bool>> vis;

class Trie {
public:
	int prefixes; // num prefijos a los que pertenece el nodo
	int words; // num. palabras terminando en nodo
	vector<Trie*> child;
	Trie() : prefixes(0), words(0), child(MAXN, nullptr) {}
	~Trie() {
		for (int i = 0; i < MAXN; ++i)
			delete child[i];
	}
	void add(string const& s, int i) {
		if (i == s.size())
			++words;
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
			t->add(s, i+1);
		}
	}
};
// devuelve el num. de ocurrencias de s en t
int search(string const& s, Trie* t) {
	Trie* aux = t;
	for (int i = 0; i < s.size(); ++i) {
		int pos = s[i] - 'A';
		if (aux->child[pos] == nullptr)
			return 0;
		aux = aux->child[pos];
	}
	return aux->words;
}

void insertAll(string & s, int i, int j, Trie & t) {
	vis[i][j] = true;
	s.push_back(bog[i][j]);
	t.add(s, 0);

	if (s.size() < 8) {
		int dx, dy;
		for (int d = 0; d < 8; ++d) {
			dx = i + vx[d];
			dy = j + vy[d];
			if (dx >= 0 && dx < 4 && dy >= 0 && dy < 4 && !vis[dx][dy]) insertAll(s, dx, dy, t);
		}
	}

	s.pop_back();
	vis[i][j] = false;
}

int puntos(int len) {
	if (len > 7) return 11;
	if (len > 6) return 5;
	if (len > 5) return 3;
	if (len > 4) return 2;
	if (len > 2) return 1;
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	int w, b, score, cont, maxs;
	string longest;
	cin >> w;
	vector<string> dict(w);
	for (int i = 0; i < w; ++i) cin >> dict[i];
	sort(dict.begin(), dict.end());

	cin >> b;
	while (b--) {
		for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) cin >> bog[i][j];

		Trie t;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				string s = "";
				vis.assign(4, vector<bool>(4, false));
				insertAll(s, i, j, t);
			}
		}

		maxs = score = cont = 0;
		for (int i = 0; i < w; ++i) {
			if (search(dict[i], &t)) {
				score += puntos(dict[i].size());
				++cont;
				if (dict[i].size() > maxs) {
					maxs = dict[i].size();
					longest = dict[i];
				}
			}
		}
		cout << score << ' ' << longest << ' ' << cont << '\n';
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll keystrokes;

const int MAXN = 26;
class Trie {
	int prefixes;
	int words;
	std::vector<Trie*> child;
public:
	Trie() :prefixes(0), words(0), child(MAXN, nullptr) {}
	~Trie() {
		for (int i = 0; i < MAXN; ++i)
			delete child[i];
	}
	void add(const char* s) {
		if (*s == '\0') ++words;
		else {
			Trie* t;
			if (child[*s - 'a'] == nullptr) {
				t = child[*s - 'a'] = new Trie();
				t->prefixes = 1;
			}
			else {
				t = child[*s - 'a'];
				t->prefixes++;
			}
			t->add(s + 1);
		}
	}
	void countKeystrokes(int strokes) {
		if (words) keystrokes += strokes;
		Trie* t;
		for (char c = 'a'; c <= 'z'; ++c) {
			t = child[c - 'a'];
			if (t != nullptr) {
				if (t->prefixes != prefixes) t->countKeystrokes(strokes + 1);
				else t->countKeystrokes(strokes);
			}
		}
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	char s[82];
	cin >> n;
	while (cin) {
		Trie t;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			t.add(s);
		}

		keystrokes = 0;
		t.countKeystrokes(0);

		cout << fixed << setprecision(2) << (round(((double)keystrokes/n)*100))/100.0 << '\n';
		cin >> n;
	}
	return 0;
}
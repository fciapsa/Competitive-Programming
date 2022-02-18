#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct pos {
	char c;
	int f;
	bool operator==(pos const& other)const {
		return c == other.c && f == other.f;
	}
	bool operator!=(pos const& other)const {
		return !(*this==other);
	}
};

int c2i(char c) {
	return 8 - (int(c) - int('A'));
}

int main() {
	ios::sync_with_stdio(false);
	int tc, movs, f;
	char c;
	pos act, dest;
	bool stop;
	cin >> tc;
	while (tc--) {
		cin >> act.c >> act.f >> dest.c >> dest.f;
		if ((c2i(act.c) + act.f) % 2 != (c2i(dest.c) + dest.f) % 2) cout << "Impossible\n";
		else {
			movs = 0;
			unordered_map<char, unordered_map<int, pos>> pos_to;
			pos_to[act.c][act.f] = act;
			queue<pos> q;
			stop = false;
			if (act.f != dest.f || act.c != dest.c) q.push(act);
			else stop = true;

			while (!stop) {
				act = q.front();
				q.pop();

				for (c = act.c + 1, f = act.f + 1; c <= 'H' && f <= 8 && !stop; ++c, ++f) {
					if (c == dest.c && f == dest.f) {
						pos_to[dest.c][dest.f] = act;
						stop = true;
						movs = 1;
						while (pos_to[act.c][act.f] != act) {
							++movs;
							act = pos_to[act.c][act.f];
						}
					}
					else {
						if (pos_to[c].count(f) == 0) {
							pos_to[c][f] = act;
							q.push({ c,f });
						}
					}
				}

				for (c = act.c + 1, f = act.f - 1; c <= 'H' && f >= 1 && !stop; ++c, --f) {
					if (c == dest.c && f == dest.f) {
						pos_to[dest.c][dest.f] = act;
						stop = true;
						movs = 1;
						while (pos_to[act.c][act.f] != act) {
							++movs;
							act = pos_to[act.c][act.f];
						}
					}
					else {
						if (pos_to[c].count(f) == 0) {
							pos_to[c][f] = act;
							q.push({ c,f });
						}
					}
				}

				for (c = act.c - 1, f = act.f + 1; c >= 'A' && f <= 8 && !stop; --c, ++f) {
					if (c == dest.c && f == dest.f) {
						pos_to[dest.c][dest.f] = act;
						stop = true;
						movs = 1;
						while (pos_to[act.c][act.f] != act) {
							++movs;
							act = pos_to[act.c][act.f];
						}
					}
					else {
						if (pos_to[c].count(f) == 0) {
							pos_to[c][f] = act;
							q.push({ c,f });
						}
					}
				}

				for (c = act.c - 1, f = act.f - 1; c >= 'A' && f >= 1 && !stop; --c, --f) {
					if (c == dest.c && f == dest.f) {
						pos_to[dest.c][dest.f] = act;
						stop = true;
						movs = 1;
						while (pos_to[act.c][act.f] != act) {
							++movs;
							act = pos_to[act.c][act.f];
						}
					}
					else {
						if (pos_to[c].count(f) == 0) {
							pos_to[c][f] = act;
							q.push({ c,f });
						}
					}
				}
			}

			cout << movs;
			stack<pos> st;
			st.push(dest);
			while (pos_to[dest.c][dest.f] != dest) {
				st.push(pos_to[dest.c][dest.f]);
				dest = pos_to[dest.c][dest.f];
			}
			while (!st.empty()) {
				cout << ' ' << st.top().c << ' ' << st.top().f;
				st.pop();
			}
			cout << '\n';
		}
	}

	return 0;
}
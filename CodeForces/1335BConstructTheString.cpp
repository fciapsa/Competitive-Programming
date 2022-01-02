#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define ll long long
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T, n, a, b, act;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> n >> a >> b;
		vector<char> s(n);
		queue<char> q;
		act = int('a');
		for (int i = 0; i < b; ++i) {
			q.push(char(act));
			++act;
		}

		map<char, int> map;
		for (int i = 0; i < n; ++i) {
			if (i >= a) {
				--map[s[i - a]];
				if (map[s[i - a]] == 0) map.erase(s[i - a]);
			}

			if (map.size() < b) {
				q.push(q.front());
				q.pop();
				s[i] = q.front();
				++map[s[i]];
			}
			else {
				s[i] = q.front();
				++map[s[i]];
			}
		}

		for (int i = 0; i < n; ++i)cout << s[i];
		cout << '\n';
	}


return 0;
}
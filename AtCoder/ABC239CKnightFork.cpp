#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> vx = { -1,-1,1,1,-2,-2,2,2 };
vector<int> vy = { 2,-2,2,-2,1,-1,1,-1 };

int main() {
	std::ios::sync_with_stdio(false);
	int x1, y1, x2, y2, x, y;
	cin >> x1 >> y1 >> x2 >> y2;
	bool ok = false;
	for (int i = 0; i < 8 && !ok; ++i) {
		x = x1 + vx[i];
		y = y1 + vy[i];
		if ((abs(x - x2) == 1 && abs(y - y2) == 2) || (abs(x - x2) == 2 && abs(y - y2) == 1)) {
			cout << "Yes\n";
			ok = true;
		}
	}
	if (!ok) cout << "No\n";
	return 0;
}
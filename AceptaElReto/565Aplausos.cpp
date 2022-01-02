#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define ll long long
using namespace std;

struct pers {
	int t, p, id;
};

struct tOrdT {
	bool operator()(pers const& ps1, pers const& ps2) {
		return ps1.t > ps2.t;
	}
};

struct tOrdP {
	bool operator()(pers const& ps1, pers const& ps2) {
		return ps1.p < ps2.p;
	}
};

int main() {
	int n, t, p, tiempo;
	cin >> n;
	while (n != 0) {
		std::vector<pers> ps;
		for (int i = 0; i < n; ++i) {
			cin >> t >> p;
			ps.push_back({ t,p,i});
		}

		std::priority_queue<pers, std::vector<pers>, tOrdT> pqT;
		std::priority_queue<pers, std::vector<pers>, tOrdP> pqP;
		std::unordered_map<int, int> map;
		for (int i = 0; i < n; ++i) {
			pqT.push(ps[i]);
			pqP.push(ps[i]);
			map.insert({ i,0 });
		}

		tiempo = pqT.top().t;
		while (map.size() > 1) {
			while (!pqT.empty() && pqT.top().t <= tiempo) {
				if (map.count(pqT.top().id) > 0) {
					map.erase(pqT.top().id);
				}
				pqT.pop();
			}
			while (!pqP.empty() && pqP.top().p > map.size()) {
				if (map.count(pqP.top().id) > 0) {
					map.erase(pqP.top().id);
				}
				pqP.pop();
			}
			
			while (!pqT.empty() && map.count(pqT.top().id) == 0) pqT.pop();

			if (!pqT.empty()) tiempo = pqT.top().t;
		}

		cout << tiempo << '\n';

	cin >> n;
	}


return 0;
}
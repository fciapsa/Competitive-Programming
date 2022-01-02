#include <iostream>
#include <queue>
#include <deque>
#include <unordered_set>

const int TAM = 21;

struct mov {
	int t;
	char m;
};

int main() {
	int n, t, x, y;
	char m, act_dir;
	bool choque;
	std::cin >> n;
	while (n != 0) {
		std::queue<mov> moves;
		for (int i = 0; i < n; ++i) {
			std::cin >> t >> m;
			moves.push({ t,m });
		}

		int hx = 10, hy = 10;
		std::unordered_set<int> ocupa;
		std::deque<int> pos;
		for (int i = 9; i >= 0; --i) {
			ocupa.insert((hx + i) * TAM + hy);
			pos.push_front((hx + i) * TAM + hy);
		}
		t = 0;
		act_dir = 'U';
		choque = false;
		while (!choque) {
			if (t == 0 || t % 10 != 0) {
				ocupa.erase(pos.back());//avanza la cola
				pos.pop_back();
			}

			if (!moves.empty() && moves.front().t == t) {
				act_dir = moves.front().m;
				moves.pop();
			}
			
				x = pos.front() / TAM;
				y = pos.front() % TAM;
				switch (act_dir) {
				case 'U':
					if (x > 0 && !(ocupa.count((x - 1) * TAM + y) > 0)) {
						ocupa.insert((x - 1) * TAM + y);
						pos.push_front((x - 1) * TAM + y);
					}
					else choque = true; break;
				case 'D':
					if (x < TAM - 1 && !(ocupa.count((x + 1) * TAM + y) > 0)) {
						ocupa.insert((x + 1) * TAM + y);
						pos.push_front((x + 1) * TAM + y);
					}
					else choque = true; break;
				case 'L':
					if (y > 0 && !(ocupa.count(x * TAM + y - 1) > 0)) {
						ocupa.insert(x * TAM + y - 1);
						pos.push_front(x * TAM + y - 1);
					}
					else choque = true; break;
				case 'R':
					if (y < TAM - 1 && !(ocupa.count(x * TAM + y + 1) > 0)) {
						ocupa.insert(x * TAM + y + 1);
						pos.push_front(x * TAM + y + 1);
					}
					else choque = true; break;
				}

				if (!choque) ++t;
		}
		std::cout << t << '\n';
	std::cin >> n;
	}
return 0;
}
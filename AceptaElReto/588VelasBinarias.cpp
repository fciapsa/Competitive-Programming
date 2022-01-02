#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;
using ll = long long int;

int main() {
	ll n;
	bool ok;
	cin >> n;
	while (n != 0) {
		deque<int> dq;
		while (n > 0) {
			dq.push_front(n % 2);
			n /= 2;
		}

		while (!dq.empty() && dq.back() == 0) dq.pop_back();

		ok = true;
		while (dq.size() > 1 && ok) {
			ok = dq.front() == dq.back();
			dq.pop_back();
			dq.pop_front();
		}

		if (ok) cout << "SI\n";
		else cout << "NO\n";

	cin >> n;
	}

return 0;
}
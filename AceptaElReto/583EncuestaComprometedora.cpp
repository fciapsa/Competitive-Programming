#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

int main() {
	int t;
	ll a, b, tot, sol;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		tot = a + b;
		sol = (((2* a - tot)*100) / tot);
		cout << sol << '\n';
	}

return 0;
}
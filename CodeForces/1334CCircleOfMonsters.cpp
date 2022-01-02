#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, n, tam;
	ll ans, aux, sum;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> n;
		tam = 2 * n;
		vector<ll> a(tam), b(tam);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i] >> b[i];
			a[n + i] = a[i];
			b[n + i] = b[i];
		}

		vector<ll> need(tam);// , prefix(tam);
		need[0] = a[0];
		//prefix[0] = a[0];
		for (int i = 1; i < tam; ++i) {
			need[i] = std::max(ll(0), a[i] - b[i - 1]);
			//prefix[i] = prefix[i - 1] + need[i];
		}

		sum = 0;
		for (int i = 1; i < n; ++i) sum += need[i];
		
		ans = a[0] + sum;
		for (int i = 1; i < n; ++i) {
			sum -= need[i];
			sum += need[i + n - 1];
			ans = std::min(ans, a[i] + sum);
		}
		cout << ans << '\n';
	}

return 0;
}
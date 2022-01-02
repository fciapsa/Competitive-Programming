#include <iostream>

using namespace std;

int main() {
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	if (a + b + c >= n && a && b && c && n >= 3) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
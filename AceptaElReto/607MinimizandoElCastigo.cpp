#include <iostream>
#include <cmath>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int n, c;
	cin >> n;
	while (n--) {
		cin >> c;
		cout << ceil(log2(c)) << '\n';
	}
}
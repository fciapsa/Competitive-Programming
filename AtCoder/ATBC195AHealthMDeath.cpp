#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define ll long long

int main() {
	int m, h;
	cin >> m >> h;
	if (h % m == 0) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
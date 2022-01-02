#include <iostream>
#include <vector>

#define ll long long
using namespace std;

std::vector<int> v(500001,0);

void init() {
	int val = 2;
	for (int pot = 2; pot <= 500000; ++pot) {
		val *= 2;
		val %= 7;
		if (val == 1) v[pot] = v[pot - 1] + 1;
		else v[pot] = v[pot - 1];
	}

}


int main() {
	int n, x;
	init();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		cout << v[x] << '\n';
	}
return 0;
}
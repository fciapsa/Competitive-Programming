#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
	int n;
	cin >> n;
	float max, min;
	std::vector<float> v(5);
	for (int i = 0; i < n; ++i) {
		min = 10.0;
		max = 0.0;
		for (int j = 0; j < 5; ++j) {
			cin >> v[j];
			if (v[j] > max) max = v[j];
			if (v[j] < min) min = v[j];
		}

		if (min > 0.0 || max >= 9.0) cout << "MEDIA\n";
		else cout << "SUSPENSO DIRECTO\n";
	}

return 0;
}
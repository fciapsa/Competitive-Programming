#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define ll long long

int main() {
	int a, b, w, min, max, goal, dif;
	bool stop = false;
	cin >> a >> b >> w;
	w *= 1000;
	if (w < a) cout << "UNSATISFIABLE";
	else if (a == b) {
		if (w % a == 0) cout << w / a << ' ' << w / a << '\n';
		else cout << "UNSATISFIABLE\n";
	}
	else {
		dif = b - a;
		goal = w;
		min = goal /b;
		goal %= b;
		if (goal > 0) {
			++min;
			goal = b - goal;
		}

		goal = goal - min * dif;
		if (goal > 0) {
			stop = true;
			cout << "UNSATISFIABLE\n";
		}

		if (!stop) {
			goal = w;
			max = goal / a;
			goal %= a;
			goal = goal - max * dif;
			if (goal > 0) {
				stop = true;
				cout << "UNSATISFIABLE\n";
			}
			if (!stop) cout << min << ' ' << max << '\n';
		}
	}

	return 0;
}
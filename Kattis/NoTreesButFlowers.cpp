#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.0)
double a, b;
double step = 1e-6;

double f(double x) {
	return a * exp(-(x * x)) + b * sqrt(x);
}

double integral(double h) {
	double area = 0.0, aux;
	for (double x = step; x <= h; x += step) {
		aux = f(x);
		area += aux * aux;
	}
	return area*step*PI;
}

int main() {
	ios::sync_with_stdio(false);
	double v, h;
	int n;
	cin >> v >> n;
	vector<pair<double, int>> vect;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> h;
		//cout << integral(h) << '\n';
		vect.push_back({fabs(v-integral(h)), i });
	}
	sort(vect.begin(), vect.end());
	cout << vect[0].second << '\n';

	return 0;
}
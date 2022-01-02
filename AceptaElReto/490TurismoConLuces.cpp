#include <iostream>
#include <vector>
#include <algorithm>

bool resuelve() {
	int N, K;
	std::cin >> N >> K;

	if (!std::cin) return false;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i) std::cin >> v[i];

	long long int espect;
	long long int act = 0;
	for (int i = 1; i < K; ++i) act += v[i] - v[i-1];
	espect = act;
	for (int i = K-1; i < N-1; ++i) {
		act -= v[i - K+2] - v[i-K+1];
		act += v[i+1] - v[i];
		if (act > espect) espect = act;
	}

	std::reverse(v.begin(), v.end());

	act = 0;
	for (int i = 1; i < K; ++i) act += v[i] - v[i - 1];
	if (act > espect) espect = act;
	for (int i = K-1; i < N-1; ++i) {
		act -= v[i - K + 2] - v[i - K + 1];
		act += v[i+1] - v[i];
		if (act > espect) espect = act;
	}

	std::cout << espect << '\n';

	return true;
}

int main() {
	while (resuelve());
	return 0;
}
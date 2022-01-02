#include <iostream>
#include <queue>

const int TAM = 20001;

int main() {
	bool visited[TAM] = { false };
	std::queue<int> q;
	q.push(1);
	visited[1] = true;
	int act;
	while (!q.empty()) {
		act = q.front();
		q.pop();

		if (act + 5 < TAM && !visited[act+5]) {
			visited[act + 5] = true;
			q.push(act + 5);
		}
		if (3 * act < TAM && !visited[3 * act]) {
			visited[3 * act] = true;
			q.push(3 * act);
		}
	}

	int N;
	std::cin >> N;
	while (N != 0) {
		if (visited[N]) std::cout << "SI\n";
		else std::cout << "NO\n";
	std::cin >> N;
	}
	
return 0;
}
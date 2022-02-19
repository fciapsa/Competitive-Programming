#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adyList(400001);
vector<int> comp_id(400001 , -1);


void dfs(int v, int comp, int &size, int &edges) {
	++size;
	edges += adyList[v].size();
	comp_id[v] = comp;

	for (int w : adyList[v]) {
		if (comp_id[w] == -1) dfs(w, comp, size, edges);
	}
}

int main() {
	int n, a, b, sol;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		adyList[a].push_back(b);
		adyList[b].push_back(a);
	}

	vector<int> comp_size, comp_edges;
	int size, edges;
	for (int comp = 0, color = 1; color <= 400000; ++color) {
		if (adyList[color].size() && comp_id[color] == -1) {
			size = 0;
			edges = 0;
			dfs(color, comp, size, edges);
			comp_size.push_back(size);
			comp_edges.push_back(edges / 2);
		++comp;
		}
	}

	sol = 0;
	for (int i = 0; i < comp_size.size(); ++i) {
		sol += min(comp_size[i], comp_edges[i]);// if tree n-1 else n
	}

	cout << sol << '\n';

return 0;
}
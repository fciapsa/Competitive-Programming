#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<vector<double>> mult(vector<vector<double>> const& A, vector<vector<double>> const& B) {
	int n = A.size();
	double accum;
	vector<vector<double>> C(n, vector<double>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			accum = 0;
			for (int k = 0; k < n; ++k) accum += A[i][k] * B[k][j];
			C[i][j] = accum;
		}
	}

	return C;
}

vector<vector<double>> pot(vector<vector<double>> const& mat, int k) {
	int n = mat.size();
	if (k == 0) {
		vector<vector<double>> ans(n, vector<double>(n, 0.0));
		for (int i = 0; i < n; ++i) ans[i][i] = 1.0;
		return ans;
	}
	if (k == 1) return mat;

	vector<vector<double>> aux = pot(mat, k / 2);
	if (k % 2) return mult(mult(aux, aux), mat);
	return mult(aux, aux);
}

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, l, t, sj, tj;
	double pj, ans;
	cin >> tc;
	while (tc--) {
		cin >> n >> l >> t;
		vector<vector<double>> mat(n, vector<double>(n, 0.0));
		for (int i = 0; i < n; ++i) mat[i][i] = 1.0;
		vector<vector<bool>> ady(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i) ady[i][i] = true;
		vector<double> vals(n);
		for (int i = 0; i < n; ++i) cin >> vals[i];

		for (int i = 0; i < l; ++i) {
			cin >> sj >> tj >> pj;
			ady[sj][tj] = true;
			ady[tj][sj] = true;
			mat[sj][sj] -= pj;
			mat[tj][sj] = pj;
		}

		mat = pot(mat, t);
		vector<double> end_vals(n, 0.0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) end_vals[i] += vals[j] * mat[i][j];
		}
		vector<double> united(n, 0.0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (ady[i][j]) united[i] += end_vals[j];
			}
		}

		ans = united[0];
		for (int i = 1; i < n; ++i) if (united[i] < ans) ans = united[i];
		cout << ans << '\n';

	}
	return 0;
}
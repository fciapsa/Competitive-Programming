#include <bits/stdc++.h>

using namespace std;
#define ll long long

using cd = complex<double>;
void fft(vector<cd>& a, int sign = 1) {
    int n = a.size();//n must be a power of 2
    double theta = 8 * sign * atan(1.0) / n;
    for (int i = 0, j = 1; j < n - 1; ++j) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
    for (int m, mh = 1; (m = mh << 1) <= n; mh = m) {
        int irev = 0;
        for (int i = 0; i < n; i += m) {
            cd w = exp(cd(0, theta * irev));
            for (int k = n >> 2; k > (irev ^= k); k >>= 1);
            for (int j = i; j < mh+i; ++j) {
                int k = j + mh;
                cd x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
    }
    if (sign == -1) for (int i = 0; i < n; ++i) a[i] /= n;
}

void mult(vector<int> const& a, vector<int> const& b, vector<int> & ans) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, 1); fft(fb, 1);
    for (int i = 0; i < fa.size(); ++i) fa[i] *= fb[i];

    fft(fa, -1);

    ans.assign(fa.size(), 0);
    for (int i = 0; i < fa.size(); ++i) ans[i] = round(fa[i].real());
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, x;
    cin >> n;

    vector<int> input(200001);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ++input[x];
    }

    vector<int> a, b, ans;
    a = input;
    b = input;
    mult(a, b, ans);

    cin >> m;
    int holes = 0;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        if (input[x] || ans[x]) ++holes;
    }

    cout << holes << '\n';

    return 0;
}
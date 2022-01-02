#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

//This solution uses radix sort(in combination with counting sort), in base 10^5 instead
//of base 10 to speed it up

ll tam;

struct nmb {
    ll d1, d2;
};

nmb v[1000005], v1[1000005];
int v2[1000005];

nmb tonmb(ll x, nmb & n) {
    n.d1 = x % 100000;
    x /= 100000;
    n.d2 = x;
    return n;
}

ll tonum(nmb const& x) {
    return x.d1 + 100000 * x.d2;
}

ll radixSortAndHash(ll x, ll y) {

    vector<int> counts1(100000);
    for (int i = 0; i < tam; ++i) {
        ++counts1[v[i].d1];
    }
    for (int i = 1; i < 100000; ++i) counts1[i] += counts1[i - 1];
    for (int i = tam - 1; i >= 0; --i) {
        v1[counts1[v[i].d1] - 1] = v[i];
        --counts1[v[i].d1];
    }

    ll sol = 0;
    vector<int> counts2(100000);
    for (int i = 0; i < tam; ++i) {
        ++counts2[v[i].d2];
    }
    if (counts2[0] != tam) {
        for (int i = 1; i < 100000; ++i) counts2[i] += counts2[i - 1];
        for (int i = tam - 1; i >= 0; --i) {
            v2[counts2[v1[i].d2] - 1] = tonum(v1[i]);
            --counts2[v1[i].d2];
        }
        for (int i = 0; i < tam; ++i) sol = (sol * x + v2[i]) % y;
    }
    else {
        for (int i = 0; i < tam; ++i) sol = (sol * x + tonum(v1[i])) % y;
    }

    return sol;
}

int main() {
    std::ios::sync_with_stdio(false);
    ll tc, prev, act, a, b, c, x, y;
    cin >> tc;
    while (tc--) {
        cin >> tam >> a >> b >> c >> x >> y;
        prev = a;
        tonmb(a, v[0]);
        for (int i = 1; i < tam; ++i) {
            act = (prev * b + a) % c;
            tonmb(act, v[i]);
            prev = act;
        }

        cout << radixSortAndHash(x,y) << '\n';
    }

    return 0;
}
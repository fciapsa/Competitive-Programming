#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool palindrome(unsigned int n) {
    vector<int> v;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    bool pal = true;
    for (int i = 0, j = v.size() - 1; i < j && pal; ++i, --j) pal = v[i] == v[j];
    return pal;
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    unsigned int n, rev, it, aux, sum;
    cin >> tc;
    while (tc--) {
        cin >> n;
        aux = n;
        rev = 0;
        while (aux > 0) {
            rev *= 10;
            rev += (aux % 10);
            aux /= 10;
        }
        sum = n + rev;
        it = 1;
        while (!palindrome(sum)) {
            ++it;
            n = sum;
            aux = n;
            rev = 0;
            while (aux > 0) {
                rev *= 10;
                rev += (aux % 10);
                aux /= 10;
            }
            sum = n + rev;
        }

        cout << it << ' ' << sum << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, k = 1, a, b, sum;
    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        sum = 0;
        if (a % 2 == 0) ++a;
        for (int i = a; i <= b; i += 2) sum += i;
        cout << "Case "<< k++ << ": " << sum << '\n';
    }
    return 0;
}
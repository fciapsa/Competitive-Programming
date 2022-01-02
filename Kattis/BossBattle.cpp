#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << 1 + max(n - 3, 0) << '\n';
    return 0;
}
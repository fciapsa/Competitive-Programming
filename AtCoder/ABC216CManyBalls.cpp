#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    stack<char> p;
    while (n > 1) {
        if (n % 2) {
            --n;
            p.push('A');
        }
        else {
            n /= 2;
            p.push('B');
        }
    }
    cout << "A";
    while (!p.empty()) {
        cout << p.top();
        p.pop();
    }
    cout << '\n';
    return 0;
}
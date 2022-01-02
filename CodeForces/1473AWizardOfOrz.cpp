#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n && i < 2; ++i) cout << 9 - i;
        for (int i = 2; i < n; ++i) cout << (i + 7) % 10;
        cout << '\n';
    }

return 0;
}
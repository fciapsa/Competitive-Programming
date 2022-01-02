#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, min, x, cont;
    cin >> tc;
    while (tc--) {
        cin >> n;
        min = 101;
        cont = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x < min) {
                min = x;
                cont = 1;
            }
            else if (x == min) ++cont;
        }

        cout << n - cont << '\n';
    }

return 0;
}
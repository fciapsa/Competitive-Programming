#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long
using namespace std;

vector<int> primes = { 2,11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007 };
vector<int> primes2 = { 3,13, 103, 1013, 10009, 100019, 1000033, 10000079, 100000037 };
vector<int> primes3 = { 5, 17, 107, 1019, 10037, 100043, 1000037, 10000103, 100000039 };

int main() {
    std::ios::sync_with_stdio(false);

    int tc, a, b, c, x, y;
    cin >> tc;
    while (tc--) {
        cin >> a >> b >> c;
        x = primes3[c-1];
        y = primes3[c-1];
        if (a > c && b > c) {
            if (a - c == b - c) {
                x *= primes[a - c];
                y *= primes2[b - c];
            }
            else {
                x *= primes[a - c];
                y *= primes[b - c];
            }
        }
        else if (a > c) x *= primes[a - c];
        else if (b > c) y *= primes[b - c];
        cout << x << ' ' << y << '\n';
    }

return 0;
}
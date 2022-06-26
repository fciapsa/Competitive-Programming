#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int A, M = 24, N = 5, a, b, c, d, e, dia;
    cin >> A;
    while (A) {
        a = A % 19;
        b = A % 4;
        c = A % 7;
        d = (19 * a + M) % 30;
        e = (2*b + 4*c + 6*d + N) % 7;
        if (d + e < 10) cout << d + e + 22 << " de marzo\n";
        else {
            dia = d + e - 9;
            if (dia == 26) dia = 19;
            else if (dia == 25 && d == 28)  dia = 18;
            cout << dia << " de abril\n";
        }

    cin >> A;
    }

    return 0;
}
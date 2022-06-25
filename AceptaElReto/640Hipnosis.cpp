#include <bits/stdc++.h>

using namespace std;
#define ll long long

//Pasar a base 9 y luego ajustar los dígitos

int main() {
    std::ios::sync_with_stdio(false);
    int n, d, resto;
    cin >> n >> d;
    while (n) {
        string s = "";
        while (n) {
            resto = n % 9;
            n /= 9;
            if (resto >= d) ++resto;
            s.push_back('0' + resto);
        }
        reverse(s.begin(), s.end());
        cout << s << '\n';
        cin >> n >> d;
    }

    return 0;
}
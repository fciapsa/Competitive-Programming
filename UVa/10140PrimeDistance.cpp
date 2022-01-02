#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define uint unsigned int
#define MAX_PRIME 46350

bitset<MAX_PRIME + 1> bs; // #include <bitset>
vector<ll> primes; // unsigned int
void sieve() {
    bs.set(); // De momento, todos son primos
    bs[0] = bs[1] = 0; // El 0 y el 1 no lo son.
    //2 lo es pero sus multiplos no
    for (int i = 4; i <= MAX_PRIME; i += 2) bs[i] = 0;
    primes.push_back(2);
    //itero sobre impares
    for (ll i = 3; i <= MAX_PRIME; i += 2) {
        if (bs[i]) {
            // El actual es primo. Tiramos sus multiplos
            for (ll j = i * i; j <= MAX_PRIME; j += i)
                bs[j] = 0; // i*i en el for ¡Cuidado con el rango!
            primes.push_back(i);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    sieve();
    ll l, u, mn, mx, c1, c2, d1, d2, prev, diff;
    vector<char> isPrime;
    cin >> l >> u;
    while (cin) {
        mn = 1000001;
        mx = 0;

        isPrime.assign(u - l + 1, 1);
        for (ll p : primes) {
            for (ll i = max(p*p, ((l+p-1)/p) * p); i <= u; i += p) {
                isPrime[i-l] = 0;
            }
        }
        if (l < 1) isPrime[0] = 0;
        if (l < 2) isPrime[1 - l] = 0;

        prev = -1;
        for (ll i = l; i <= u; ++i) {
            if (isPrime[i-l]) {
                if (prev == -1) prev = i;
                else {
                    diff = i - prev;
                    if (diff < mn) {
                        mn = diff;
                        c1 = prev;
                        c2 = i;
                    }
                    if (diff > mx) {
                        mx = diff;
                        d1 = prev;
                        d2 = i;
                    }
                    prev = i;
                }
            }
        }

        if (mx == 0) cout << "There are no adjacent primes.\n";
        else cout << c1 << ',' << c2 << " are closest, " << d1 << ',' << d2 << " are most distant.\n";
    cin >> l >> u;
    }
    return 0;
}
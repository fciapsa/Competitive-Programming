#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<bool> primo(3500000, true);
vector<int> spf(3500000, -1);//smallest prime factor

void criba() {
    spf[2] = 2;
    for (int i = 4; i < 3500000; i += 2) {
        primo[i] = false;
        spf[i] = 2;
    }
    for (int i = 3; i < 3500000; i += 2) {
        if (primo[i]) {
            spf[i] = i;
            for (int j = 2 * i; j < 3500000; j += i) {
                if (spf[j] == -1) spf[j] = i;
                primo[j] = false;
            }
        }
    }
}

int factors(int x) {
    if (x == 1) return 0;
    return 1 + factors(x / spf[x]);
}

int main() {
    std::ios::sync_with_stdio(false);
    criba();
    vector<int> minFact(10000002, -1);
    minFact[0] = 0;
    int i = 2, prime_factors = 0;
    while (prime_factors < minFact.size()) {
        prime_factors += factors(i);
        if (prime_factors < minFact.size()) minFact[prime_factors] = i;
        ++i;
    }
    
    int n, k = 1;
    cin >> n;
    while (n >= 0) {
        cout << "Case " << k++ << ": ";
        if (minFact[n] != -1) cout << minFact[n] << "!\n";
        else cout << "Not possible.\n";
        cin >> n;
    }
    return 0;
}
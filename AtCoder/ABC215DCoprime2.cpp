#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define MAXN   100005
int n, m, a, tot;

// stores smallest prime factor for every number
int spf[MAXN];
vector<bool> usedPrimes(MAXN, false);

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void factorAndMark(int x, vector<bool> &coprimes, int &tot)
{
    while (x != 1)
    {
        if (!usedPrimes[spf[x]]) {
            usedPrimes[spf[x]] = true;
            for (int i = spf[x]; i <= m; i += spf[x]) {
                if (coprimes[i]) {
                    coprimes[i] = false;
                    --tot;
                }
            }
        }
        x = x / spf[x];
    }
}

// driver program for above function
int main(int argc, char const* argv[])
{
    // precalculating Smallest Prime Factor
    sieve();

    cin >> n >> m;
    tot = m;
    vector<bool> coprimes(m+1, true);
    for (int i = 0; i < n; ++i) {
        cin >> a;
        factorAndMark(a, coprimes, tot);
    }
    cout << tot << '\n';
    for (int i = 1; i <= m; ++i) {
        if (coprimes[i]) cout << i << '\n';
    }
    return 0;
}
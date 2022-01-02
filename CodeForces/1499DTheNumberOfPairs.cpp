#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define ll long long
using namespace std;

const int MAX = 20000013;
vector<int> minpdiv(MAX,0);
vector<int> cnt(MAX,0);

int tc, c, d, x, sol;


/* 1. gcd always divides lcm, so gcd(a,b) is a divisor of x
   2. For each divisor of x, we can obtain the corresponding lcm value
   3. Now, since gcd * lcm = a * b
                 a = gcd(a,b) * m for some m
                 b = gcd(a,b) * n for some n
      we can deduce lcm / gcd = m * n. The amount of (a,b) pairs is the same as (m,n) pairs.
   4. Finally, if we have two coprime numbers m and n whose product is w = lcm / gcd, the number of (m,n) possibilites is
   2^k where k is the number the distinct prime factors w has.

   Assuming x^(1/3) as upper bound for the number of divisors of x, since we have to factorize lcm for each testcase
   and there are up to 10^4 such testcases in the input, we will need to precompute the number of unique prime factors
   of every number up to 2*10^7(the maximum possible value of lcm(a,b), because we deduce the following:
       c*lcm - d*gcd = x <----> gcd * (c * (lcm/gcd) - d) = x <----> c * w = x/gcd + d <----> w = (x/gcd + d) / c
   and the max values is when x = 10^7, d = 10^7, gcd = 1, c = 1

   This precomputation can be done using sieve of Eratosthenes to find the minimum prime divisor for each number and
   then use DP to compute the number of distinct prime factors:
       cnt[i] = cnt[i / minpdiv[i] ]      if minpdiv[i / minpdiv[i]] == minpdiv[i]
       cnt[i] = cnt[i / minpdiv[i] ] + 1  if minpdiv[i / minpdiv[i]] != minpdiv[i]
*/

void init() {
    minpdiv[2] = 2;
    for (int j = 4; j < MAX; j += 2) minpdiv[j] = 2;

    for (int i = 3; i * i < MAX; i += 2) {
        if (minpdiv[i] == 0) {
            minpdiv[i] = i;
            for (int j = i * i; j < MAX; j += i) {
                if(minpdiv[j] == 0)  minpdiv[j] = i;
            }
        }
    }

    for (int i = 2; i < MAX; ++i) {
        if (minpdiv[i] == 0) minpdiv[i] = i;

        if (minpdiv[i / minpdiv[i]] == minpdiv[i]) cnt[i] = cnt[i / minpdiv[i]];
        else cnt[i] = cnt[i / minpdiv[i]] + 1;
    }
}

void addPairs(int div) {
    if ((x / div + d) % c) return;

    int w = (x / div + d) / c;
    sol += (1 << cnt[w]);
}

int main() {
    std::ios::sync_with_stdio(false);
    init();

    cin >> tc;
    while (tc--) {
        cin >> c >> d >> x;
        sol = 0;
        for (int div = 1; div * div <= x; ++div) {
            if (x % div == 0) {
                addPairs(div);
                if (x != div*div) addPairs(x/div);
            }
        }
        cout << sol << '\n';
    }

    return 0;
}
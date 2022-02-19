#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;
#define ll long long

/*Takahashi gana el juego si tras las N rondas el resto es 0
* Takahashi gana el juego si tras N-1 rondas el resto es r y:
*     - En la ultima ronda le toca a T y 10r OR 10r + S_i da resto cero
*     - En la ultima ronda le toca a A y 10r AND 10r + S_i dan resto cero
* 
* Por tanto se puede resolver como un DP planteado en orden inverso donde
* dp[i] representa el conjunto de r's tras i rondas que hacen que Takahashi gane
* 
* Por ello el caso base es dp[N] = {0}, Takahashi necesita r = 0 tras las N rondas para ganar
* Para 1 <= i <= N:
*     Si en la ronda i le toca a T, dp[i-1] = {r tales que (10r mod 7) OR (10r + S_i mod 7) esta en dp[i] }
*     Si en la ronda i le toca a A, dp[i-1] = {r tales que (10r mod 7) AND (10r + S_i mod 7) estan en dp[i]}
*/

int num(char c) {
    return int(c) - int('0');
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    string s, x;
    cin >> n >> s >> x;
    vector<unordered_set<int>> dp(n + 1);
    dp[n] = { 0 };
    for (int i = n - 1; i >= 0; --i) {
        if (x[i] == 'A') {
            for (int r = 0; r < 7; ++r) {
                if (dp[i + 1].count((10 * r) % 7) && dp[i + 1].count((10 * r + num(s[i])) % 7)) dp[i].insert(r);
            }
        }
        else {
            for (int r = 0; r < 7; ++r) {
                if (dp[i + 1].count((10 * r) % 7) || dp[i + 1].count((10 * r + num(s[i])) % 7)) dp[i].insert(r);
            }
        }
    }

    if (dp[0].count(0)) cout << "Takahashi\n";
    else cout << "Aoki\n";

    return 0;
}
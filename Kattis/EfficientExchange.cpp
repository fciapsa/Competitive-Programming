#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> dp(s.size() + 1);
    //dp[s.size()] = 0;
    int zeroes, change, aux;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '0') dp[i] = dp[i + 1];
        else {
            aux = int(s[i]) - int('0') + dp[i + 1];

            change = zeroes = 0;
            for (int j = i; j < s.size(); ++j) {
                if (s[j] != '0') {
                    if (change) change -= 1;
                    change += zeroes * 9;
                    zeroes = 0;
                    change += int('0') + 10 - int(s[j]);
                }
                else ++zeroes;

                aux = min(aux, 1 + change + dp[j + 1]);
            }
            dp[i] = aux;
        }
    }
    cout << dp[0] << '\n';
    return 0;
}
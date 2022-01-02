#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, x;
    cin >> tc;
    while (tc--) {
        cin >> x;
        x /= 100;
        vector<vector<int>> wind(10, vector<int>(x));
        for (int i = 9; i >= 0; --i) {
            for (int j = 0; j < x; ++j) cin >> wind[i][j];
        }

        //dp(i,j) = minimo coste para ir de la posicion j y altura i a la casilla destino 
        vector<vector<int>> dp(10, vector<int>(x+1, 1000000000));
        dp[0][x] = 0;//caso base(mas los valores por defecto de la ultima columna)
        for (int j = x - 1; j >= 0; --j) {
            for (int i = 0; i < 10; ++i) {
                if (i > 0) dp[i][j] = min(dp[i][j], 20 - wind[i][j] + dp[i-1][j+1]);//bajar
                dp[i][j] = min(dp[i][j], 30 - wind[i][j] + dp[i][j+1]);//mantenerse
                if(i < 9) dp[i][j] = min(dp[i][j], 60 - wind[i][j] + dp[i+1][j+1]);//subir
            }
        }

        cout << dp[0][0] << "\n\n";
    }

    return 0;
}
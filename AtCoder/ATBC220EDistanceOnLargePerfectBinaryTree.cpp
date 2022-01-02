#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll MOD = 998244353, INV2 = 499122177;//inverso modular de 2

//Para contar el numero de pares de un nodo del nivel L, iteramos sobre el numero de subidas 
//S en [(d+1)/2, min(d, L-1) ]. Tras S subidas, el numero de destinos es:
//    1 si D-S==0
//    pow(2,D-S-1) si D-S> 0
//

int main() {
    std::ios::sync_with_stdio(false);
    ll n, d, lowestLevel, mn, sol = 0, pot, ind, aux, aux2, mx, s1, s2;
    cin >> n >> d;
    if (d > 2 * (n - 1)) cout << "0\n";
    else {
        mn = max((ll)0,d-(n-1));//veces que necesito subir como minimo
        lowestLevel = mn + 1;
        vector<ll> pot2mod(max(d+1,n));
        pot2mod[0] = 1;
        pot = 1;
        for (int i = 1; i < pot2mod.size(); ++i) {
            pot2mod[i] = (pot2mod[i - 1] + pot) % MOD;
            pot = (pot * 2) % MOD;
        }

        for (int lvl = lowestLevel, h = n-lowestLevel; lvl <= n; ++lvl, --h) {
            mn = max((ll)0, (d - h + 1)/2);//minimo que hay que subir
            mx = min(d , (ll)lvl-1);//maximo que se puede subir
            s1 = d - mx;//minimo que queda por bajar
            s2 = d - mn;//maximo que queda por bajar
            if (s1 == 0) aux = pot2mod[s2];
            else {
                aux = pot2mod[s2] - pot2mod[s1 - 1];
                if (aux < 0) aux += MOD;
            }
            if (s2 == d) {//no se pierde la mitad como cuando subes
                aux2 = pot2mod[d] - pot2mod[d - 1];
                if (aux2 < 0) aux2 += MOD;
                aux = (aux + aux2) % MOD;
            }
            sol = (sol + (pot2mod[lvl-1] * aux)%MOD) % MOD;
        }

        cout << sol << '\n';
    }

    return 0;
}
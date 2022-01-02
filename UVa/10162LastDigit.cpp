#include <bits/stdc++.h>

using namespace std;
#define ll long long

/*
Para conocer el ultimo digito de n^n es suficiente conocer el del ultimo digito de n, es decir d=n%10,
elevado a n. Ese digito es el ultimo de d, d + 10, d + 20, ... y entre las potencias de d mod 10 se forma
un ciclo. Como para nuestro problema las potencias de cada digito d van a aparecer de 10 en 10, observamos
el ciclo formado por esas potencias. Los valores sumados en S se repetiran con ciclicidad 10 veces el mcm de
las longitudes de los ciclos de cada digito d, que son:
0 -> 1 (siempre 0)
1 -> 1 (siempre 1)
2 -> 2 (4 y 6)
3 -> 2 (7 y 3)
4 -> 1 (siempre 6)
5 -> 1 (siempre 5)
6 -> 1 (siempre 6)
7 -> 2 (3 y 7)
8 -> 2 (6 y 4)
9 -> 1 (siempre 9)

Luego cada 20 terminos se retoma la misma secuencia de sumas. La suma de los 20 primeros tiene como ultimo
digito 4, luego la de multiplos de 20 es 4 -> 8 -> 2 -> 6 -> 0 -> 4 -> ... que es un ciclo de tamaño 5.
El ultimo digito de S se repite con ciclicidad 5*20 = 100
*/

ll potMod10(ll a, ll b) {
    if (b == 0) return 1;

    ll aux = potMod10(a, b / 2);
    if (b % 2) return (((aux * aux) % 10) * a) % 10;
    else return (aux * aux) % 10;
}

int main() {
    std::ios::sync_with_stdio(false);
    int aux = 0, pos;
    //primeros 100, luego ciclo
    vector<int> sol(100);
    for (int i = 1; i < 100; ++i) {
        aux = (aux + potMod10(i, i)) % 10;
        sol[i] = aux;
    }
    sol[0] = (aux + potMod10(100, 100)) % 10;

    string s;
    cin >> s;
    while (s != "0") {
        if (s.size() == 1) pos = int(s[0]) - int('0');
        else pos = 10 * (int(s[s.size() - 2]) - int('0')) + int(s[s.size() - 1]) - int('0');
        cout << sol[pos] << '\n';
        cin >> s;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct interv {
    int ini, fin;//inicio y final, intervalo cerrado [ini, fin]
    bool operator<(interv const& other) const {
        return ini < other.ini;//ordenamos los intervalos de menor a mayor extremo ini
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int l, g, x, r, cubierto, i, j, estaciones, mejor;
    cin >> l >> g;
    while (l != 0) {
        vector<interv> v(g);
        for (int i = 0; i < g; ++i) {
            cin >> x >> r;//transformamos la gasolinera en el intervalo [x-r, x+r]
            v[i].ini = x - r;
            v[i].fin = x + r;
        }

        sort(v.begin(), v.end());//ordenamos los intervalos de menor mayor ini
        i = estaciones = cubierto = 0;
        while (i < g) {
            //si el siguiente intervalo comienza despues de hasta donde hemos llegado, no podemos cubrirlo
            //si hemos cubierto todo, acabamos
            if (v[i].ini > cubierto || cubierto >= l) break;

            //si llegamos aqui, el siguiente intervalo nos vale para seguir cubriendo
            mejor = i;
            j = i+1;
            while (j < g && v[j].ini <= cubierto) {//mientras el siguiente intervalo tambien sirva para seguir cubriendo
                if (v[j].fin > v[mejor].fin) mejor = j;//nos quedamos con el que llegue mas lejos(extremo derecho)
                ++j;
            }
            ++estaciones;//hemos necesitado una gasolinera mas
            cubierto = v[mejor].fin;//cubrimos hasta el extremo derecho del intervalo que mas alcanzaba
            i = j;
        }

        if (cubierto < l) cout << "-1\n";//no se ha conseguido cubrir todo
        else cout << g - estaciones << '\n';//cuantas gasolineras sobran(el total menos las que hemos necesitado)

    cin >> l >> g;
    }

    return 0;
}
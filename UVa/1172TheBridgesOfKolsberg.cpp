#include <bits/stdc++.h>

using namespace std;
#define ll long long

int nn, ns;

struct city {
    string os;
    int trade;
};

struct par {
    int trade, bridges;
    //la mejor solucion es la que mayor tradevalue tiene, y a igualdad la que menos puentes necesita
    bool operator>(par const& other)const {
        return trade > other.trade || (trade == other.trade && bridges < other.bridges);
    }
};

/*En la tabla mem, la posicion mem[a][b] guarda la mejor solucion que podriamos obtener construyendo puentes
  considerando las ciudades [a..nn-1] de la orilla norte y [b..ns-1] de la orilla sur. Como hay a lo sumo
  1000 ciudades por orilla, la tabla tiene tamaño como maximo 10^6.

  El caso base es cuando no nos queda ninguna ciudad de alguna de las orillas(a >= nn || b >= ns), por lo que
  no podemos construir ningun puente y el tradevalue es 0.

  La solucion que nos piden es mem[0][0], es decir, considerando todas las ciudades.

  Para calcular el valor de mem[a][b] si este aun no esta calculado, hacemos el maximo de estas 3 opciones:
      1. construir un puente entre las ciudades a y b(SOLO si son del mismo sistema operativo) y a esto sumarle
      lo que salga de considerar las ciudades [a+1..nn-1] y [b+1..ns-1], es decir mem[a+1][b+1]

      2. omitir la ciudad a y pasar a la siguiente en la orilla norte, es decir el valor de mem[a+1][b]

      3. omitir la ciudad b y pasar a la siguiente en la orilla sur, es decir el valor de mem[a][b+1]

Haciendo esto ademas se garantiza que los puentes no se cruzan,ya que si construimos el puente entre a y b,
al pasar a (a+1,b+1) y siguientes, solo nos planteamos construir puentes entre ciudades mas a la derecha.
*/

par dp(int a, int b, vector<city> const& nc, vector<city> const& sc, vector<vector<par>> & mem) {
    if (a >= nn || b >= ns) return { 0,0 };// ya no hay mas ciudades en alguna orilla, 0 puentes posibles

    if (mem[a][b].trade != -1) return mem[a][b];//si ya esta calculado, lo devolvemos

    par opt1 = { 0,0 }, opt2, opt3;
    if (nc[a].os == sc[b].os) {//si tienen el mismo OS, probar construyendo un puente entre ellas
        opt1 = dp(a + 1, b + 1, nc, sc, mem);
        ++opt1.bridges;
        opt1.trade += nc[a].trade + sc[b].trade;
    }

    opt2 = dp(a + 1, b, nc, sc, mem);//saltandose la ciudad a
    opt3 = dp(a, b + 1, nc, sc, mem);//saltandose la ciudad b

    //nos quedamos con la mejor de las 3 opciones
    if (opt1 > opt2) {
        if (opt1 > opt3) mem[a][b]= opt1;
        else mem[a][b]= opt3;
    }
    else {
        if (opt2 > opt3) mem[a][b]= opt2;
        else mem[a][b]= opt3;
    }

    return mem[a][b];
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    string name, os;
    par p;
    cin >> tc;
    while (tc--) {
        cin >> nn;//numero de ciudades al norte
        vector<city> nc(nn);
        for (int i = 0; i < nn; ++i) cin >> name >> nc[i].os >> nc[i].trade;

        cin >> ns;//numero de ciudades al sur
        vector<city> sc(ns);
        for (int i = 0; i < ns; ++i) cin >> name >> sc[i].os >> sc[i].trade;

        vector<vector<par>> mem(nn, vector<par>(ns, { -1,-1 }));//el valor por defecto (-1,-1) indica que esta sin calcular
        p = dp(0, 0, nc, sc, mem);
        cout << p.trade << ' ' << p.bridges << '\n';
    }
    return 0;
}
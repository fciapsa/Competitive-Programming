#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct pack {
    double precio;
    int cant;
};

int main() {
    std::ios::sync_with_stdio(false);
    double precio, mn, aux;
    int cant, npacks, k, caso = 1;
    string linea;
    cin >> precio;//precio unitario
    while (cin) {
        cin >> npacks;
        vector<pack> v(npacks + 1);
        v[0] = { precio, 1};

        for (int i = 1; i <= npacks; ++i) {
            cin >> cant >> precio;
            v[i] = { precio, cant };
        }

        //nos pueden pedir el precio de hasta 100, por lo que calculamos las soluciones para
        //hasta el doble(p.ej. por si lo mas rentable es comprar dos veces el pack de 99) 
        vector<vector<double>> dp(201, vector<double>(npacks+1));
        //dp(i,j) indica el minimo coste con el que podemos comprar i objetos utilizando solo los primeros j packs

        //casos base
        for (int j = 0; j <= npacks; ++j) dp[0][j] = 0;//comprar 0 objetos cuesta 0 independientemente del pack j al que hemos llegado
        for (int i = 0; i < 201; ++i) {
            dp[i][0] = i * v[0].precio;//hasta el pack 0, el del precio por 1 unidad, lo minimo para comprar i objetos es i * precio
        }

        for (int j = 1; j <= npacks; ++j) {//vamos considerando un nuevo pack cada vez
            for (int i = 1; i < 201; ++i) {
                mn = dp[i][j - 1];//comprando 0 veces el pack j
                for (int c = v[j].cant, x = 1; c <= i; c += v[j].cant, ++x) {//x es cuantas veces compramos el pack j, probamos todas las opciones
                    aux = dp[i - c][j - 1] + x * v[j].precio;
                    mn = fmin(mn, aux);//nos quedamos con el minimo de todas las opciones consideradas
                }
                dp[i][j] = mn;
            }
        }

        //como nos dicen que podemos comprar de mas si eso sale mas barato, vamos haciendo el minimo de derecha a izquierda de la fila
        //para tener el minimo de todas las cantidades mayores
        for (int j = 199; j >= 0; --j) dp[j][npacks] = fmin(dp[j][npacks], dp[j + 1][npacks]);


        getline(cin, linea);//acabar de consumir la linea anterior
        getline(cin, linea);//la linea con la lista de enteros K
        stringstream ss(linea);
        cout << "Case " << caso++ << ":\n";
        while (ss >> k) {
            cout << "Buy " << k << " for $";
            cout << fixed << setprecision(2) << dp[k][npacks] << '\n';//la solucion esta en la ultima fila, en la que se han considerado ya
                                                                      //todos los packs posibles
        }

    cin >> precio;
    }
    return 0;
}
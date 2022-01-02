#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;//para leer la linea entera
    int x, i, aux;
    bool ok;

    getline(cin, s);
    while (cin) {
        stringstream ss(s);
        vector<int> v;
        while (ss >> x) {//vamos extrayendo del stringstream los enteros uno a uno
            v.push_back(x);
        }

        ok = true;//flag que pondremos a falso si la secuencia no es valida
        stack<int> inicios;//aqui apilamos las matrioshkas abiertas y las desapilamos cuando se cierran
        //para comprobar que siempre se cierra la que toca(la ultima en abrir)
        stack<int> sumas;//aqui apilamos la suma de tamaños de las matrioshkas contenidas en las abiertas
        //para comprobar que cuando se cierren la suma es menor que su tamaño

        if (v[0] < 0) {
            inicios.push(v[0]);
            sumas.push(0);
        }
        else ok = false;//lo primero debe ser que se abra una matrioshka
        i = 1;
        while (i < v.size() && ok) {
            if (v[i] > 0) {//se cierra
                if (inicios.empty()) ok = false;//invalido, no habia ninguna abierta
                else if (v[i] == -inicios.top()) {//la que se abre y la que se cierra deben tener mismo tamaño
                    if (sumas.top() < v[i]) {//las contenidas deben caber dentro
                        inicios.pop();
                        sumas.pop();
                    }
                    else ok = false;//no cabian
                }
                else ok = false;//los tamaños no coinciden
            }
            else {//se abre
                inicios.push(v[i]);

                aux = sumas.top();
                sumas.pop();
                sumas.push(aux - v[i]);//se la sumamos(v[i] es negativo) al tamaño de las contenidas en la anterior
                sumas.push(0);//y como acabamos de abrir una, llevamos la cuenta de las contenidas en esta
            }

            ++i;
        }

        if (ok && inicios.empty()) cout << ":-) Matrioshka!\n";//si inicios no esta vacio, significaria
                                                             //que no hemos cerrado todas las matrioshkas abiertas
        else cout << ":-( Try again.\n";

    getline(cin, s);
    }

return 0;
}
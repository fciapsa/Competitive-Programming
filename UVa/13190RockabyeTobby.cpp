#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct medi {
    string name;
    ll frec, time, prio;
    //como la priority_queue con el operador < es de maximos, un truco para que sea de minimos sin 
    //cambiar nada mas es definir el < como el >
    bool operator<(medi const& other) const {
        return time >  other.time || (time == other.time && prio > other.prio);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    ll tc, f, n, k;
    string s;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;

        priority_queue<medi> pq;
        for (int i = 0; i < n; ++i) {
            cin >> s >> f;
            //de cada medicina guardamos su nombre, su frecuencia, el momento siguiente en el que hay que
            //tomarla(inicialmente f) y su prioridad(la posicion en la que aparece en la entrada)
            pq.push({ s,f,f, i });
        }

        medi m;
        //sacamos k veces la mas prioritaria, volviendo a meterla en la cola tras sumar la frecuencia al 
        //momento siguiente en el que hay que tomarla
        for (int i = 0; i < k; ++i) {
            m = pq.top();
            cout << m.time << ' ' << m.name << '\n';
            pq.pop();
            m.time += m.frec;
            pq.push(m);
        }

    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll u, v;

//Ecuacion diofantica Ax + By = C tiene sol <==> gcd(A,B) | C
//Si d=gcd(A,B) y (x0,y0) una solucion, todas las soluciones son
//x = x0 + lambda(B/d) e y = y0 - lambda(A/d)
//Primero resolvemos Ax+By=gcd(A,B) y luego multiplicamos u y v por C/gcd(A,B)
ll extendedEuclidRec(ll a, ll b) {
	if (!b) {
		u = 1;
		v = 0;
		return a;
	}
	ll r = extendedEuclidRec(b, a % b);
	ll uAux = v;
	ll vAux = u - (a / b) * v;
	u = uAux;
	v = vAux;
	return r;
} // extendedEuclidRec,

int main() {
    std::ios::sync_with_stdio(false);
	ll n, c1, n1, c2, n2, gcd, p1, p2, q, m1, m2;
    cin >> n;
    while (n != 0) {
        cin >> c1 >> n1 >> c2 >> n2;
		extendedEuclidRec(n1, n2);
		gcd = u * n1 + v * n2;
		if (n % gcd) cout << "failed\n";
		else {
			u *= (n / gcd);
			v *= (n / gcd);
			m1 = n2 / gcd;
			m2 = n1 / gcd;

			if (u < 0) {
				q = abs(u / m1);
				if (abs(u) % m1) ++q;
				u += q * m1;
				v -= q * m2;
			}
			if (v < 0) {
				q = v / m2;
				if (abs(v) % m2) --q;
				u += q * m1;
				v -= q * m2;
			}

			if (u < 0 || v < 0) cout << "failed\n";
			else {
				p1 = c1 * n2;
				p2 = n1 * c2;
				//caja 1 mejor si c1*n2 < n1*c2
				if (p1 < p2) {
					q = v / m2;
					u += q * m1;
					v -= q * m2;
				}
				//caja 2 mejor si c1*n2 > n1*c2
				else if (p1 > p2) {
					q = u / m1;
					u -= q * m1;
					v += q * m2;
				}
				//ambas cajas iguales si c1*n2 = n1*c2
				cout << u << ' ' << v << '\n';
			}
		}
    cin >> n;
    }
    return 0;
}
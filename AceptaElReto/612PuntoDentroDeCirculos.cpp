#include <iostream>

using namespace std;
#define ll long long

ll x, y;

ll count(ll cx, ll cy, ll r) {
	ll dx = x - cx, dy = y - cy;
	ll Euc = dx * dx + dy * dy, rSq = r * r;

	ll cont = 0;
	if (Euc <= rSq) cont = 1;

	//dado un centro y un radio, lo maximo que puede variar cada coordenada es R + R/2 + R/4 +...+ 1 --> 2R-1
	ll supx, infx, supy, infy, newcx, newcy, newr = r / 2, var = 2 * r - 1;
	ll newvar = 2 * newr - 1;
	//izquierda
	newcx = cx + r;
	newcy = cy;
	supx = cx + var;
	supy = cy + newvar;
	infx = newcx - newvar;
	infy = cy - newvar;
	if (infx <= x && supx >= x && infy <= y && supy >= y) cont += count(newcx, newcy, newr);
	//derecha
	newcx = cx - r;
	newcy = cy;
	supx = newcx + newvar;
	supy = cy + newvar;
	infx = cx - var;
	infy = cy - newvar;
	if (infx <= x && supx >= x && infy <= y && supy >= y) cont += count(newcx, newcy, newr);
	//arriba
	newcx = cx;
	newcy = cy + r;
	supx = cx + newvar;
	supy = cy + var;
	infx = cx - newvar;
	infy = newcy - newvar;
	if (infx <= x && supx >= x && infy <= y && supy >= y) cont += count(newcx, newcy, newr);
	//abajo
	newcx = cx;
	newcy = cy - r;
	supx = cx + newvar;
	supy = newcy + newvar;
	infx = cx - newvar;
	infy = cy - var;
	if (infx <= x && supx >= x && infy <= y && supy >= y) cont += count(newcx, newcy, newr);

	return cont;
}

int main() {
	std::ios::sync_with_stdio(false);

	ll r;
	while (cin >> r >> x >> y) {
		cout << count(0, 0, r) << '\n';
	}
}
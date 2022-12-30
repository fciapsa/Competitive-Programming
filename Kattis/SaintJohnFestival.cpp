#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define EPS 1e-5

using T = double;
struct pt {
    T x, y;
    pt operator+(pt p) const {
        return { x + p.x, y + p.
y };
    }
    pt operator-(pt p) const {
        return { x - p.x, y - p.
y };
    }
    pt operator*(T d) const { return { x * d, y * d }; }
    pt operator/(T d) const {
        return { x / d, y / d };
    } // solo para T punto flotante
    bool operator==(pt o) const {
        return x == o.x && y
            == o.y;
    }
    bool operator!=(pt o) const {
        return !(*this == o);
    }
    /*
    bool operator<(pt o) const { // orden lexicografico
    if (x == o.x) return y < o.y;
    return x < o.x;
    }
    */
    bool operator<(pt o) const {
        if (fabs(x - o.x) < EPS) // 1e-9
            return y < o.y;
        return x < o.x;
    }
};

// Prod. escalar, indica como de similares son las direcciones de V y W
// > 0 si V y W forman angulo menor a 90° (PI/2)
// 0 si angulo de 90°
// < 0 si angulo mayor a 90°
T dot(pt v, pt w) {
    return v.x * w.x + v.y * w.y;
}

// Prod. vectorial, indica como de perpendiculares son V y W
// > 0 si V y W forman angulo a tal que 0 < a < PI (PI = 180°)--->se gira de V a W en sentido antihorario
// 0 si V y W son paralelos o alineados
// < 0 si V y W forman angulo a tal que -PI < a < 0 --->se gira de V a W en sentido horario
T cross(pt v, pt w) {
    return v.x * w.y - v.y * w.x;
}

// Posicion relativa de C respecto AB
// indica el sentido en el que giramos al hacer el recorrido A->B->C
// positivo/negativo: C a la izquierda/derecha de AB. Cero si A, B y C colineales
T orient(pt a, pt b, pt c) {
    return cross(b - a, c - a);
}

// true si P dentro de disco de diametro [AB]
bool inDisk(pt a, pt b, pt p) {
    return dot(a - p, b - p) <= 0;
}

// true si P esta en el segmento [AB]
bool onSegment(pt a, pt b, pt p) {
    return orient(a, b, p) == 0 && inDisk(a, b, p);
}

// true si P es al menos tan alto como A
bool above(pt a, pt p) {
    return p.y >= a.y;
}

// true si segmento [PQ] cruza el rayo (semirrecta) que va hacia la derecha desde A
bool crossesRay(pt a, pt p, pt q) {
    return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}

// Comprueba en O(logn) si el punto Q esta dentro del poligono convexo P
// Funciona en sentido horario cambiando los < por >
bool inConvexPolygon(pt q, vector<pt> const& p) {
    if (orient(p[0], p[1], q) < 0 || orient(p[int(p.
        size()) - 2], p[0], q) < 0)
        return false;
    int ini = 1, fin = int(p.size()) - 2, mid;
    while (ini != fin - 1) {
        mid = (ini + fin) / 2;
        if (orient(p[0], p[mid], q) < 0) fin = mid;
        else ini = mid;
    }
    return !(orient(p[ini], p[fin], q) < 0);
}

// devuelve true si R esta en el lado izquierdo de la linea PQ
bool ccw(pt p, pt q, pt r) {
    return orient(p, q, r) > 0; // >= para admitir puntos colineales
}

// Los puntos del convex hull se devuelven en sentido antihorario y con H.front() == H.back()
vector<pt> convexHull(vector<pt> &P) {
    sort(P.begin(), P.end());
    //P.erase(unique(P.begin(), P.end()), P.end()); //Descomentar si hay puntos repetidos en P
        int n = int(P.size()), k = 0;
    vector<pt> H(2 * n);
    // hull inferior
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && !ccw(H[k - 2], H[k - 1], P[i]))
            --k;
        H[k++] = P[i];
    }
    // hull superior
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && !ccw(H[k - 2], H[k - 1], P[i]))
            --k;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}

int main() {
    std::ios::sync_with_stdio(false);
    int l, s, x, y;
    cin >> l;

    vector<pt> pts;
    for (int i = 0; i < l; ++i) {
        cin >> x >> y;
        pts.push_back({ (double)x,(double)y });
    }
    vector<pt> hull = convexHull(pts);

    cin >> s;
    int ans = 0;
    pt p;
    for (int i = 0; i < s; ++i) {
        cin >> x >> y;
        p = { (double)x, (double)y };
        if (inConvexPolygon(p, hull)) ++ans;
    }
    cout << ans << '\n';

    return 0;
}
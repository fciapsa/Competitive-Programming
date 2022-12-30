#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define db double
#define INF 1e9
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

// Distancia Euclidea
double dist(pt a, pt b) {
    return hypot(a.x - b.x, a.y - b.y);
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

struct tree {
    double x, y, l;
    int v;
};

vector<tree> trees;
int all;

int solve(int subset) {
    vector<pt> pts;
    int lost = 0;
    double wood = 0;

    for (int i = 1, j = 0; i <= all; i <<= 1, ++j) {
        if (i & subset) pts.push_back({ trees[j].x , trees[j].y });
        else {
            lost += trees[j].v;
            wood += trees[j].l;
        }
    }

    vector<pt> poly = convexHull(pts);
    double perim = 0;
    for (int i = 1; i < poly.size(); ++i) {
        perim += dist(poly[i], poly[i - 1]);
    }

    if (wood >= perim) return lost;
    return INF;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, x, y, v, l;
    cin >> n;
    while (n) {
        trees.resize(n);
        for(int i = 0; i < n; ++i){
            cin >> x >> y >> v >> l;
            trees[i] = { (db)x,(db)y,(db)l, v };
        }

        int ans = INF;
        //try all subsets
        all = (1 << n) - 1;
        for (int subset = all; subset; subset = (all & (subset - 1))) {
            ans = min(ans, solve(subset));
        }
        cout << "The lost value is " << ans << ".\n";
        
        cin >> n;
    }

    return 0;
}
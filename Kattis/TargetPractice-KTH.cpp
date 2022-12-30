#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define db double
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

// norma al cuadrado, distancia a (0,0) al cuadrado, mejor para comparaciones
T sq(pt v) {
    return v.x * v.x + v.y * v.y;
}

// norma del vector V, distancia del punto al origen
double abs(pt v) {
    return sqrt(sq(v));
}

// Prod. vectorial, indica como de perpendiculares son V y W
// > 0 si V y W forman angulo a tal que 0 < a < PI (PI = 180°)--->se gira de V a W en sentido antihorario
// 0 si V y W son paralelos o alineados
// < 0 si V y W forman angulo a tal que -PI < a < 0 --->se gira de V a W en sentido horario
T cross(pt v, pt w) {
    return v.x * w.y - v.y * w.x;
}

// Prod. escalar, indica como de similares son las direcciones de V y W
// > 0 si V y W forman angulo menor a 90° (PI/2)
// 0 si angulo de 90°
// < 0 si angulo mayor a 90°
T dot(pt v, pt w) {
    return v.x * w.x + v.y * w.y;
}

// rotar punto P 90° en sentido antihorario
pt perp(pt p) {
    return { -p.y, p.x };
}

// Representamos una recta ax + by = c mediante un vector v y un offset c
struct line {
    pt v; T c;
    // Constructor con vector de direccion v y offset c
    line(pt _v, T _c) : v(_v), c(_c) {}
    // Contructor mediante la ecuacion ax + by = c
    line(T a, T b, T _c) : v({ b,-a }), c(_c) {}
    // Constructor dados dos puntos p y q
    line(pt p, pt q) : v(q - p), c(cross(v, p)) {}
    // Permiten T = int:
    // A que lado de la recta esta el punto p, depende de la direccion de v
    // positivo --> izquierda, 0 --> en la recta, negativo-- > derecha
    T side(pt p) { return cross(v, p) - c; }

    // distancia (minima) del punto p a la recta
    double dist(pt p) { return abs(side(p)) / abs(v); }

    // distancia al cuadrado, util cuando se trabaja con distancias enteras
        double sqDist(pt p) {
        return side(p) * side(p) / (
            double)(sq(v));
    }
    // recta perpendicular que pasa por el punto p
    line perpThrough(pt p) { return { p, p + perp(v) }; }
    // True si p va antes que Q en la recta, siguiendo la direccion del vector v,
        // Para ordenar puntos de una recta, o proyecciones de puntos sobre la recta
        bool cmpProj(pt p, pt q) {
        return dot(v, p) < dot(v,
            q);
    }
    // trasladar la recta segun un vector t, solo cambia el offset c(no v)
        // devuelve una recta trasladada, no modifica la recta que llama a la funcion
        line translate(pt t) { return{ v, c + cross(v,t) }; }
    // No permiten T = int:
    // Trasladar la recta una distancia dist a la izquierda(o - dist para derecha)
        // devuelve una recta trasladada, no modifica la recta que llama a la funcion
        line shiftLeft(double dist) {
        return{ v, c + dist * abs(v) };
    }
    // proyeccion ortogonal de p en la recta, punto de la recta mas cercano a p
        pt proj(pt p) { return p - perp(v) * side(p) / sq(v); }
    // reflejo de p al otro lado de la recta
    pt refl(pt p) {
        return p - perp(v) * 2 * side(p) / sq(v);
    }
};

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

// --> A partir de aqui se necesita Line.cpp <--
// distancia (minima) de punto P a segmento [AB]
double segPoint(pt a, pt b, pt p) { // cuidado si T=long double
        if (a != b) {
            line l(a, b);
            if (l.cmpProj(a, p) && l.cmpProj(p, b)) // P mas cercano a su proyeccion en[AB]
                return l.dist(p); // distancia a la recta
        }
    return min(abs(p - a), abs(p - b)); // P mas cercano a extremo a o b
}

// true si P es al menos tan alto como A
bool above(pt a, pt p) {
    return p.y >= a.y;
}
// true si segmento [PQ] cruza el rayo (semirrecta) que va hacia la derecha desde A
bool crossesRay(pt a, pt p, pt q) {
    return (above(a, q) - above(a, p)) * orient(a, p, q) >
        0;
}
// Comprueba si punto a esta dentro de poligono p en O(n), tambien funciona en sentido horario
// Si strict a true devuelve false cuando a esta en el borde del poligono
// Requiere Segment.cpp
bool inPolygon(vector<pt>& p, pt a, bool strict) {
    int numCrossings = 0;
    for (int i = 0; i < int(p.size()) - 1; ++i) {
        if (onSegment(p[i], p[i + 1], a))
            return !strict; // esta en el borde
        numCrossings += crossesRay(a, p[i], p[i + 1]);
    }
    return numCrossings & 1; // esta dentro si hay un numero impar de cortes
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, x, y, s, k=1;
    pt shot;
    cin >> n;
    while (n) {
        vector<pt> pts(n);
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            pts[i] = { (db)x, (db)y };
        }
        pts.push_back(pts[0]);

        cout << "Case " << k++ << '\n';
        cin >> s;
        while (s--) {
            cin >> x >> y;
            shot = { (db)x, (db)y };
            db mn = segPoint(pts[n - 1], pts[0], shot);
            for (int i = 1; i < n; ++i)
                mn = min(mn, segPoint(pts[i], pts[i-1], shot));

            if (mn < EPS) cout << "Winged!\n";
            else {
                if(inPolygon(pts,shot, true)) cout << "Hit! ";
                else cout << "Miss! ";
                cout << fixed << setprecision(4) << mn << '\n';
            }
        }

        cin >> n;
    }


    return 0;
}
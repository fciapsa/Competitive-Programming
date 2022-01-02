#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-9;//epsilon para comparar numeros reales

//El codigo de geometria se ha obtenido de la bibliografia: Competitive Programming 3

struct point {
    double x, y;
};

//una forma de representar una recta es en la forma a*x + b*y + c = 0
struct line {
    double a, b, c; 
};

//dados dos puntos devuelve la recta que pasa por ellos
void pointsToLine(point p1, point p2, line& l) {
    if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
        l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
    }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

//dadas dos rectas que se intersecan devuelve el punto de interseccion
void intersectionPoint(line l1, line l2, point& p) {
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
}

int main() {
    std::ios::sync_with_stdio(false);
    double x, y, c, h1, h2, ini, fin, w;
    int iters;
    line l1, l2;
    point p;
    cin >> x >> y >> c;
    while (cin) {
        ini = 0;
        fin = max(x, y);//la medida de la escalera mas grande
        iters = 10000;
        //cuando hacemos una busqueda binaria sobre un espacio de soluciones de numeros reales (ini,fin)
        //es mas comodo hacer un numero de iteraciones fijo para asegurarse de que la busqueda converge
        //con suficiente precision
        while (iters--) {
            w = (ini + fin) / 2;//probamos con el punto medio como medida del ancho
            h1 = sqrt(y * y - w * w);//altura a la que se apoya la escalera de medida x(despejando por Pitagoras)
            h2 = sqrt(x * x - w * w);//altura a la que se apoya la escalera de medida y(despejando por Pitagoras)

            pointsToLine({0,0}, {w,h2}, l1);//recta que contiene la escalera de medida y
            pointsToLine({w,0}, {0,h1}, l2);//recta que contiene la escalera de medida x
            intersectionPoint(l1, l2, p);//punto de interseccion
            if (p.y > c + EPS) ini = w;//si se cortan por encima de c, hay que ensanchar la calle para que se corten mas abajo
            else fin = w;//en otro caso estrechamos la calle
        }

        cout << fixed << setprecision(3) << fin << '\n';
        cin >> x >> y >> c;
    }
    return 0;
}
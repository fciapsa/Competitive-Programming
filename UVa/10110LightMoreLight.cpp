#include <bits/stdc++.h>

using namespace std;
#define ll long long

//Contar el numero de divisores es demasiado lento para el limite impuesto por el juez
//Dado que si n = p1^n1 x p2^n2 x ... x pk^nk entonces tiene (n1+1)(n2+1)...(nk+1) divisores,
//se tiene que tendra una cantidada impar de divisores si y solo si todos los n_i son pares. Esto equivale
//a que n sea un cuadrado perfecto

int main() {
    std::ios::sync_with_stdio(false);
    unsigned int n;
    cin >> n;
    while (n != 0) {
        if (n == pow((unsigned int)sqrt(n),2)) cout << "yes\n";
        else cout << "no\n";
        cin >> n;
    }
    return 0;
}
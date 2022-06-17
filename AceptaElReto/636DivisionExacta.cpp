#include <bits/stdc++.h>

using namespace std;
#define ll long long

int q;

int f(int x) {
    return (10 * x) % q;
}

pair<int,int> floydCycleFinding(int x0) {
    int tortoise = f(x0), hare = f(f(x0));
    while (tortoise != hare)
        tortoise = f(tortoise), hare = f(f(hare));
    int mu = 0; hare = x0;
    while (tortoise != hare)
        tortoise = f(tortoise), hare = f(hare), mu++;
    int lambda = 1; hare = f(tortoise);
    while (tortoise != hare)
        hare = f(hare), lambda++;
    return { mu, lambda };
}

int main() {
    std::ios::sync_with_stdio(false);
    int x0;
    cin >> x0 >> q;
    while (cin) {
        auto p = floydCycleFinding(x0);
        cout << "0.";
        for (int i = 0; i < p.first; ++i) {
            cout << (10 * x0) / q;
            x0 = (10 * x0) % q;
        }
        if (x0) {
            cout << '|';
            for (int i = 0; i < p.second; ++i) {
                cout << (10 * x0) / q;
                x0 = (10 * x0) % q;
            }
            cout << '|';
        }
        cout << '\n';
        cin >> x0 >> q;
    }

    return 0;
}
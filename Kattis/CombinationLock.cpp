#include <bits/stdc++.h>

using namespace std;
#define ll long long

int cw(int p1, int p2) {
    if (p2 >= p1) return (p2 - p1) * 9;
    else return (40 - p1) * 9 + p2 * 9;
}

int ccw(int p1, int p2) {
    if (p2 <= p1) return (p1 - p2) * 9;
    else return p1 * 9 + (40 - p2) * 9;
}

int main() {
    std::ios::sync_with_stdio(false);
    int p, a, b, c;
    cin >> p >> a >> b >> c;
    while(a != b){
        cout << 1080 + ccw(p, a) + cw(a, b) + ccw(b, c) << '\n';
        cin >> p >> a >> b >> c;
    }
    return 0;
}
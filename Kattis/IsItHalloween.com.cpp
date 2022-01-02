#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string m;
    int d;
    cin >> m >> d;
    if ((m == "DEC" && d == 25) || (m == "OCT" && d == 31)) cout << "yup\n";
    else cout << "nope\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int sol;
string s1, s2;

void sim(int i, int j, int c) {
    if (i < 0 && j < 0) return;

    int aux;
    if (i < 0) aux = int(s2[j]) - int('0') + c;
    else if(j < 0) aux = int(s1[i]) - int('0')  + c;
    else aux = int(s1[i]) - int('0') + int(s2[j]) - int('0') + c;

    if (aux >= 10) {
        ++sol;
        sim(i - 1, j - 1, 1);
    }
    else sim(i - 1, j - 1, 0);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    while (s1 != "0" || s2 != "0") {
        sol = 0;
        sim(s1.size() - 1, s2.size() - 1, 0);
        if (sol == 0) cout << "No carry operation.\n";
        else if (sol == 1) cout << "1 carry operation.\n";
        else cout << sol << " carry operations.\n";
    cin >> s1 >> s2;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long

bool pal(string& s, int a, int b) {
    while (a < b && s[a] == s[b]) {
        ++a;
        --b;
    }
    return b <= a;
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int i = 0, j = s.size() - 1;
    while (i < j && s[i] == '0' && s[j] == '0') {
        ++i;
        --j;
    }
    while (j > i && s[j] == '0') --j;

    if (pal(s, i, j)) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
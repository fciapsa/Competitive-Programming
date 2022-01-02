#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s1, s2, s3, s4, s5;
    cin >> s1 >> s2 >> s3 >> s4 >> s5;
    for (int j = 0; j < 4 * n; j += 4) {
        if (s1[j] == '.') cout << '1';
        else if (s4[j] == '*') cout << '2';
        else cout << '3';
    }
    cout << '\n';
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    while (n > 2) {
        cout << n << " bottles of "<<s << " on the wall, " << n << " bottles of "<< s << ".\n" <<
            "Take one down, pass it around, " << n - 1 << " bottles of "<< s << " on the wall.\n";
        --n;
    }
    if (n == 2) {
        cout << n << " bottles of " << s << " on the wall, " << n << " bottles of " << s << ".\n" <<
            "Take one down, pass it around, " << n - 1 << " bottle of " << s << " on the wall.\n";
        --n;
    }
    cout << n << " bottle of " << s << " on the wall, " << n << " bottle of " << s << ".\n" <<
        "Take it down, pass it around, no more bottles of "<< s << ".\n";


    return 0;
}
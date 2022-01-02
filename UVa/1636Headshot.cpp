#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    int z_after_z, z, p1, p2;
    cin >> s;
    while (cin) {
        z_after_z = z = 0;
        if (s[0] == '0') {
            ++z;
            if (s[s.size() - 1] == '0') ++z_after_z;
        }
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                ++z;
                if(s[i - 1] == '0') ++z_after_z;
            }
        }

        //z_after_z/z < z/n   <====> z_after_z * n < z*z
        p1 = z_after_z * s.size();
        p2 = z * z;

        if (p1 < p2) cout << "ROTATE\n";
        else if (p1 == p2) cout << "EQUAL\n";
        else cout << "SHOOT\n";

        cin >> s;
    }
    return 0;
}
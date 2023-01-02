#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    string s1, s2;
    getline(cin, s1);
    while (tc--) {
        getline(cin, s1);
        getline(cin, s2);
        vector<char> v1(s1.size(), '1'), v2(s2.size(), '1');
        int ind1 = 0, ind2 = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (isalpha(s1[i])) v1[ind1++] = tolower(s1[i]);
        }
        for (int i = 0; i < s2.size(); ++i) {
            if (isalpha(s2[i])) v2[ind2++] = tolower(s2[i]);
        }
        bool same = true;
        int ind = 0;
        for (; ind < v1.size() && ind < v2.size() && same; ++ind) {
            same = v1[ind] == v2[ind];
        }
        if (same && ind < v1.size()) same = v1[ind] == '1';
        if (same && ind < v2.size()) same = v2[ind] == '1';

        if (same) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}
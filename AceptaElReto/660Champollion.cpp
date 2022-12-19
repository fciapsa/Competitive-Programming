#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ll long long

bool vocal(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc, ind;
    string s, w, act;
    cin >> tc;
    getline(cin, s);//dump
    while (tc--) {
        getline(cin, s);
        for (int i = 0; i < s.size(); ++i) s[i] = tolower(s[i]);

        unordered_set<string> conj;
        stringstream ss(s);
        while (ss >> w) {
            ind = 0;
            if (vocal(w[0])) {
                conj.insert(w.substr(0,1));
                ++ind;
            }

            while (ind < w.size()) {
                if ((ind + 3 < w.size() && !vocal(w[ind + 3])) || ind+3 == w.size()) {
                    conj.insert(w.substr(ind, 3));
                    ind += 3;
                }
                else {
                    conj.insert(w.substr(ind, 2));
                    ind += 2;
                }
            }
        }
        
        cout << conj.size() << '\n';

    }

    return 0;
}
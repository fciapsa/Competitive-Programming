#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s, aux, pal;
    cin >> s;

    unordered_set<string> endings;
    for (int i = 0; i < s.size(); ++i) endings.insert(s.substr(i, s.size() - i));
    
    unordered_set<string> rhymes;
    int e;
    cin >> e;
    getline(cin, aux);
    while (e--) {
        getline(cin, aux);
        stringstream ss(aux);

        vector<string> conj;
        bool ok = false;
        while (ss >> pal) {
            conj.push_back(pal);
            if (endings.count(pal)) ok = true;
        }

        if (ok) for (int i = 0; i < conj.size(); ++i) rhymes.insert(conj[i]);
    }

    int p;
    cin >> p;
    getline(cin, aux);
    while (p--) {
        getline(cin, aux);
        stringstream ss(aux);
        while (ss >> pal);
        
        bool found = false;
        for (int i = 0; i < pal.size() && !found; ++i) {
            if (rhymes.count(pal.substr(i, pal.size() - i))) found = true;
        }
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}
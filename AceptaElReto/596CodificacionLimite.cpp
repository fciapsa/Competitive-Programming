#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define ll long long

int hasta;

bool recurs(string const& s, int ind, vector<char>& sol) {
    if (ind > hasta) hasta = ind;
    if (s[ind] == '.') return true;

    bool l = recurs(s, ind + 1, sol);
    bool r = recurs(s, hasta + 1, sol);
    if (l && r) sol.push_back(s[ind]);
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    while (cin) {
        vector<char> sol;
        hasta = 0;
        recurs(s, 0, sol);
        for (int i = 0; i < sol.size(); ++i) cout << sol[i];
        cout << '\n';
    cin >> s;
    }
return 0;
}
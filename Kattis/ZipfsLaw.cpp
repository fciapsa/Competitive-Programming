#include <bits/stdc++.h>

using namespace std;
#define ll long long

void lowcase(string &s) {
    for (int i = 0; i < s.size(); ++i)
        if (isupper(s[i])) s[i] = tolower(s[i]);
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    bool first = true;
    string s, word;
    cin >> n;
    while (cin) {
        getline(cin, s);//consume line
        map<string, int> mp;

        getline(cin, s);
        while (s != "EndOfText") {
            int i = 0;
            while (i < s.size()) {
                int j1 = i, j2;
                while (j1 < s.size() && !isalpha(s[j1])) ++j1;

                j2 = j1;
                if (j1 < s.size()) {
                    while (j2 + 1 < s.size() && isalpha(s[j2 + 1])) ++j2;
                    word = s.substr(j1, j2 - j1 + 1);
                    lowcase(word);
                    ++mp[word];
                }

                i = j2+1;
            }

            getline(cin, s);
        }

        if (first) first = false;
        else cout << '\n';

        bool found = false;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second == n) {
                cout << it->first << '\n';
                found = true;
            }
        }

        if (!found) cout << "There is no such word.\n";

        cin >> n;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    unordered_set<char> hardcs = { 'b','c','d','g','k','n','p','t','B','C','D','G','K','N','P','T' };

    bool start = true;
    char hc;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            if (hardcs.count(s[i - 1])) {
                if ((s[i - 1] < 'k' && s[i - 1] >= 'a') || s[i - 1] < 'K') cout << "ah";
                else if ((s[i - 1] < 't' && s[i - 1] >= 'k') || s[i - 1] < 'T') cout << "oh";
                else cout << "uh";
            }
            cout << ' ';
            start = true;
        }
        else if (s[i] == '-') start = false;
        else {
            if (start) {
                if (i == 0 || s[i - 1] == ' ') {
                    if (!hardcs.count(s[i])) {
                        if (isupper(s[i])) {
                            if (s[i] <= 'B') hc = 'b';
                            else if (s[i] == 'C') hc = 'c';
                            else if (s[i] <= 'E') hc = 'd';
                            else if (s[i] <= 'I') hc = 'g';
                            else if (s[i] <= 'L') hc = 'k';
                            else if (s[i] <= 'O') hc = 'n';
                            else if (s[i] <= 'R') hc = 'p';
                            else hc = 't';
                            cout << char(toupper(hc));
                            s[i] = toupper(hc);
                        }
                        else {//islower
                            if (s[i] <= 'b') hc = 'b';
                            else if (s[i] == 'c') hc = 'c';
                            else if (s[i] <= 'e') hc = 'd';
                            else if (s[i] <= 'i') hc = 'g';
                            else if (s[i] <= 'l') hc = 'k';
                            else if (s[i] <= 'o') hc = 'n';
                            else if (s[i] <= 'r') hc = 'p';
                            else hc = 't';
                            cout << hc;
                            s[i] = hc;
                        }
                    }
                    else {
                        cout << s[i];
                        hc = tolower(s[i]);
                    }
                }
                else cout << s[i];
            }
            else if (hardcs.count(s[i])) {
                cout << hc;
                s[i] = hc;
            }
            else cout << s[i];
        }
    }
    char last = s[s.size() - 1];
    if (hardcs.count(last)) {
        if ((last < 'k' && last >= 'a') || last < 'K') cout << "ah";
        else if ((last < 't' && last >= 'k') || last < 'T') cout << "oh";
        else cout << "uh";
    }
    cout << '\n';

    return 0;
}
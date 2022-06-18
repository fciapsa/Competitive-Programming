#include <bits/stdc++.h>

using namespace std;
#define ll long long

unordered_map<char, int> mp = { {'A',5}, {'B', 9}, {'C', 11}, {'D', 7}, {'E', 1}, {'F', 9}, {'G', 9},
    {'H', 7}, {'I', 3}, {'J', 13}, {'K', 9}, {'L', 9}, {'M', 7}, {'N', 5}, {'O', 11}, {'P', 11},
    {'Q', 13}, {'R', 7}, {'S', 5}, {'T', 3}, {'U', 7}, {'V', 9}, {'W', 9}, {'X', 11}, {'Y', 13}, {'Z', 11},
    {'!', 19}, {'?', 15} };

int main() {
    std::ios::sync_with_stdio(false);

    int n, ans;
    string s;

    cin >> n;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        ans = mp[s[0]];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ' ') ans += 5;
            else {
                ans += mp[s[i]];
                if (s[i - 1] != ' ') ans += 3;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
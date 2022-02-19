#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
#define ll long long

bool found = false;
string s1, s2, s3;
ll sol1, sol2, sol3;

void prueba(map<char, int> mp, int lvl, int row, ll n1, ll n2, ll n3, ll pot, vector<bool> used) {
    if (lvl >= s1.size() && lvl >= s2.size() && lvl >= s3.size()) {
        if (n1 + n2 == n3) {
            found = true;
            sol1 = n1;
            sol2 = n2;
            sol3 = n3;
        }
    }
    else {
        if (row == 0) {
            if (lvl < s1.size()) {
                if (mp.count(s1[lvl])) prueba(mp, lvl, 1, n1 + mp[s1[lvl]] * pot, n2, n3, pot, used);
                else {
                    int x;
                    if (lvl == s1.size() - 1) x = 1;
                    else x = 0;
                    for (; x < 10 && !found; ++x) {
                        if (!used[x]) {
                            used[x] = true;
                            mp[s1[lvl]] = x;
                            prueba(mp, lvl, 1, n1 + mp[s1[lvl]] * pot, n2, n3, pot, used);
                            used[x] = false;
                        }
                    }
                }
            }
            else prueba(mp, lvl, 1, n1 , n2, n3, pot, used);
        }
        else if (row == 1) {
            if (lvl < s2.size()) {
                if (mp.count(s2[lvl])) prueba(mp, lvl, 2, n1, n2 + mp[s2[lvl]] * pot, n3, pot, used);
                else {
                    int x;
                    if (lvl == s2.size() - 1) x = 1;
                    else x = 0;
                    for (; x < 10 && !found; ++x) {
                        if (!used[x]) {
                            used[x] = true;
                            mp[s2[lvl]] = x;
                            prueba(mp, lvl, 2, n1, n2 + mp[s2[lvl]] * pot, n3, pot, used);
                            used[x] = false;
                        }
                    }
                }
            }
            else prueba(mp, lvl, 2, n1, n2, n3, pot, used);
        }
        else {
            if (lvl < s3.size()) {
                if (mp.count(s3[lvl])) {
                    int val = (((n1 + n2) % (10 * pot)) / pot);
                    if(val == mp[s3[lvl]] && (lvl != s3.size() - 1 || val != 0))
                        prueba(mp, lvl + 1, 0, n1, n2, n3 + mp[s3[lvl]] * pot, pot * 10, used);
                }
                else {
                    int val = (((n1 + n2) % (10 * pot)) / pot);
                    if (!used[val]) {
                        if (lvl != s3.size() - 1 || val != 0) {
                            used[val] = true;
                            mp[s3[lvl]] = val;
                            prueba(mp, lvl + 1, 0, n1, n2, n3 + mp[s3[lvl]] * pot, pot * 10, used);
                        }
                    }
                }
            }
            //else prueba(mp, lvl+1, 0, n1, n2, n3, pot*10, used);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> s1 >> s2 >> s3;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(s3.begin(), s3.end());
    map<char, int> mp;
    vector<bool> used(10, false);
    prueba(mp, 0, 0, 0, 0, 0, 1, used);
    if (found) {
        cout << sol1 << '\n';
        cout << sol2 << '\n';
        cout << sol3 << '\n';
    }
    else cout << "UNSOLVABLE\n";
    return 0;
}
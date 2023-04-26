#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX 1000000000

int main() {
    std::ios::sync_with_stdio(false);
    vector<int> tope_niveles = { 1 };
    int tm = 6, prev = 1;
    while (prev < MAX) {
        prev += tm;
        tm += 6;
        tope_niveles.push_back(prev);
    }

    int n;
    cin >> n;
    while (n) {
        vector<int> ans;
        if (n == 1) {
            for (int i = 2; i <= 7; ++i) ans.push_back(i);
        }
        else {
            auto tope = lower_bound(tope_niveles.begin(), tope_niveles.end(), n);
            int fin = *tope;
            int lvl = tope - tope_niveles.begin();
            int tam = 6*lvl;
            int ini = fin - tam + 1;
            int ini_prev = lvl == 1 ? 1 : ini - (tam - 6);
            int ini_next = ini + tam;
            //prev lvl
            if ((n - ini) % lvl == 0) {//then only one neighbor in prev lvl
                int offset = (lvl - 1) * ((n - ini) / lvl);
                ans.push_back(ini_prev + offset);
            }
            else if (n == fin) {
                int offset = (lvl - 1) * ((n - ini) / lvl) + ((n - ini) % lvl - 1);
                ans.push_back(ini_prev);
                ans.push_back(ini_prev + offset);
            }
            else {//two neighbors in prev lvl
                int offset = (lvl - 1) * ((n - ini) / lvl) + ((n - ini) % lvl - 1);
                ans.push_back(ini_prev + offset);
                ans.push_back(ini_prev + offset + 1);
            }
            //same lvl
            if (n == ini) {
                ans.push_back(n + 1);
                ans.push_back(fin);
            }
            else if (n == fin) {
                ans.push_back(ini);
                ans.push_back(n - 1);
            }
            else {
                ans.push_back(n - 1);
                ans.push_back(n + 1);
            }
            //next lvl
            if (n == ini) {
                ans.push_back(ini_next);//1st next lvl
                ans.push_back(ini_next + 1);//2nd next lvl
                ans.push_back(ini_next + tam + 5);//last next lvl
            }
            else if ((n - ini) % lvl == 0) {//then 3 neighbors in next lvl
                int offset = (lvl + 1) * ((n - ini) / lvl);
                ans.push_back(ini_next + offset - 1);
                ans.push_back(ini_next + offset);
                ans.push_back(ini_next + offset + 1);
            }
            else {//only 2 neighbors in next lvl
                int offset = (lvl + 1) * ((n - ini) / lvl) + ((n - ini) % lvl);
                ans.push_back(ini_next + offset);
                ans.push_back(ini_next + offset + 1);
            }
        }

        cout << ans[0];
        for (int i = 1; i < ans.size(); ++i) cout << ' ' << ans[i];
        cout << '\n';

        cin >> n;
    }

    return 0;
}
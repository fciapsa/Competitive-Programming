#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    string s1, s2, w, tag;
    cin >> n;
    getline(cin, s1);//consume line
    while (n--) {
        getline(cin, s1);
        getline(cin, s2);

        stringstream ss(s1);
        vector<string> v1;
        while (ss >> w) {
            v1.push_back(w);
        }

        stringstream ss2(s2);
        vector<string> v2;
        while (ss2 >> w) {
            v2.push_back(w);
        }

        if (v1.size() != v2.size()) cout << "-\n";
        else {
            bool ok = true;
            unordered_map<string, string> mp1, mp2;
            for (int k = 0; k < 100; ++k) {//sweeps
                for (int i = 0; i < v1.size() && ok; ++i) {
                    tag = "";
                    if (v1[i][0] == '<') {
                        tag = v1[i];
                        if (mp1.count(v1[i])) v1[i] = mp1[v1[i]];
                        else if (v2[i][0] != '<') {
                            mp1[v1[i]] = v2[i];
                            v1[i] = mp1[v1[i]];
                        }
                    }

                    if (mp1.count(tag)) {
                        for (int j = 0; j < v1.size(); ++j) {
                            if (v1[j] == tag) v1[j] = mp1[tag];
                        }
                    }

                    tag = "";
                    if (v2[i][0] == '<') {
                        tag = v2[i];
                        if (mp2.count(v2[i])) v2[i] = mp2[v2[i]];
                        else if (v1[i][0] != '<') {
                            mp2[v2[i]] = v1[i];
                            v2[i] = mp2[v2[i]];
                        }
                    }

                    if (mp2.count(tag)) {
                        for (int j = 0; j < v2.size(); ++j) {
                            if (v2[j] == tag) v2[j] = mp2[tag];
                        }
                    }

                    if (v1[i][0] != '<' && v2[i][0] != '<' && v1[i] != v2[i]) ok = false;
                }
            }

            if (!ok) cout << "-\n";
            else {
                if (v1[0][0] != '<') cout << v1[0];
                else cout << "a";

                for (int i = 1; i < v1.size(); ++i) {
                    if (v1[i][0] != '<') cout << ' ' << v1[i];
                    else cout << " a";
                }
                cout << '\n';
            }
        }
    }

    return 0;
}
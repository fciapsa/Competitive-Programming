#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1));
    cout << "? 1" << endl;

    vector<int> ans(n + 1);
    int odd = 0, even = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> ans[i];
        if (ans[i] == 1) mat[1][i] = 1;

        if (ans[i] % 2) ++odd;
        else ++even;
    }

    vector<int> queries;
    if (even <= odd) {
        for (int i = 2; i <= n; ++i) {
            if (ans[i] % 2 == 0) queries.push_back(i);
        }
    }
    else {
        for (int i = 2; i <= n; ++i) {
            if (ans[i] % 2) queries.push_back(i);
        }
    }

    int x;
    for (int q = 0; q < queries.size(); ++q) {
        cout << "? " << queries[q] << endl;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            if (x == 1) {
                if (queries[q] < i) mat[queries[q]][i] = 1;
                else mat[i][queries[q]] = 1;
            }
        }
    }

    cout << "!" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (mat[i][j]) {
                cout << i << ' ' << j << endl;
            }
        }
    }

return 0;
}
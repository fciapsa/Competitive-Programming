#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<vector<string>> art = {
    {"xxxxx", "x...x", "x...x", "x...x", "x...x", "x...x", "xxxxx"},
    {"....x", "....x", "....x", "....x", "....x", "....x", "....x"},
    {"xxxxx", "....x", "....x", "xxxxx", "x....", "x....", "xxxxx"},
    {"xxxxx", "....x", "....x", "xxxxx", "....x", "....x", "xxxxx"},
    {"x...x", "x...x", "x...x", "xxxxx", "....x", "....x", "....x"},
    {"xxxxx", "x....", "x....", "xxxxx", "....x", "....x", "xxxxx"},
    {"xxxxx", "x....", "x....", "xxxxx", "x...x", "x...x", "xxxxx"},
    {"xxxxx", "....x", "....x", "....x", "....x", "....x", "....x"},
    {"xxxxx", "x...x", "x...x", "xxxxx", "x...x", "x...x", "xxxxx"},
    {"xxxxx", "x...x", "x...x", "xxxxx", "....x", "....x", "xxxxx"},
    {".....", "..x..", "..x..", "xxxxx", "..x..", "..x..", "....."},
};

#define NROWS 7
#define WIDTH 5
vector<string> mat(NROWS);

bool equals(int dig, int off_col) {
    bool eq = true;
    for (int i = 0; i < NROWS && eq; ++i) {
        for(int j = 0; j < WIDTH && eq; ++j){
            eq = mat[i][off_col + j] == art[dig][i][j];
        }
    }

    return eq;
}

int main() {
    std::ios::sync_with_stdio(false);
    int a = 0, b = 0;
    for (int i = 0; i < NROWS; ++i) getline(cin, mat[i]);

    int col = 0;
    int* act = &a;
    while (col < mat[0].size()) {
        bool dig = false;
        for (int i = 0; i < 10 && !dig; ++i) {
            if (equals(i, col)) {
                *act *= 10;
                *act += i;
                dig = true;
            }
        }
        col += WIDTH + 1;
        if (!dig) act = &b;
    }

    int ans = a + b;
    vector<int> digs;
    while (ans) {
        digs.push_back(ans % 10);
        ans /= 10;
    }

    vector<string> ans_art(NROWS, "");
    bool first = true;
    for (int i = digs.size() - 1; i >= 0; --i) {
        if (first) first = false;
        else {
            for (int j = 0; j < NROWS; ++j) {
                ans_art[j] += ".";
            }
        }
        for (int j = 0; j < NROWS; ++j) {
            ans_art[j] += art[digs[i]][j];
        }
    }

    for (int i = 0; i < NROWS; ++i) {
        for (int j = 0; j < ans_art[i].size(); ++j) {
            cout << ans_art[i][j];
        }
        cout << '\n';
    }

    return 0;
}
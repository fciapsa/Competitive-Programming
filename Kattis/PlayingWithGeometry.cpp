#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define ll long long
using namespace std;

struct vertex {
    int x, y, id;
};

struct ordX {
    bool operator()(vertex const& v1, vertex const& v2) {
        return v1.x < v2.x;
    }
};

struct ordY {
    bool operator()(vertex const& v1, vertex const& v2) {
        return v1.y < v2.y;
    }
};

struct ordId {
    bool operator()(vertex const& v1, vertex const& v2) {
        return v1.id < v2.id;
    }
};

void rotate90(vector<vertex>& v, int N) {
    int aux;
    for (int i = 0; i < v.size(); ++i) {
        aux = v[i].x;
        v[i].x = N - v[i].y;
        v[i].y = aux;
    }
}

bool same(vector<vertex> const& v1, vector<vertex> const& v2) {
    bool same = true;
    map<int, map<int, int>> mp;
    for (int i = 0; i < v1.size(); ++i) ++mp[v1[i].x][v1[i].y];

    for (int i = 0; i < v1.size() && same; ++i) {
        same = mp[v2[i].x][v2[i].y] == 1;
    }
    return same;
}

int main() {
    std::ios::sync_with_stdio(false);

    int v1, v2, x, y;
    cin >> v1;
    vector<vertex> op1(v1);
    for (int i = 0; i < v1; ++i) {
        cin >> op1[i].x >> op1[i].y;
        op1[i].id = i;
    }

    cin >> v2;
    vector<vertex> op2(v2);
    for (int i = 0; i < v2; ++i) {
        cin >> op2[i].x >> op2[i].y;
        op2[i].id = i;
    }

    if (v1 != v2) cout << "no\n";
    else {
        sort(op1.begin(), op1.end(), ordX());
        sort(op2.begin(), op2.end(), ordX());

        int first, act = 0, newX = 0;
        while (act < op1.size()) {
            first = op1[act].x;
            while (act < op1.size() && op1[act].x == first) {
                op1[act].x = newX;
                ++act;
            }
            ++newX;
        }

        newX = act = 0;
        while (act < op2.size()) {
            first = op2[act].x;
            while (act < op2.size() && op2[act].x == first) {
                op2[act].x = newX;
                ++act;
            }
            ++newX;
        }

        sort(op1.begin(), op1.end(), ordY());
        sort(op2.begin(), op2.end(), ordY());

        int newY = 0;
        act = 0;
        while (act < op1.size()) {
            first = op1[act].y;
            while (act < op1.size() && op1[act].y == first) {
                op1[act].y = newY;
                ++act;
            }
            ++newY;
        }

        newY = act = 0;
        while (act < op2.size()) {
            first = op2[act].y;
            while (act < op2.size() && op2[act].y == first) {
                op2[act].y = newY;
                ++act;
            }
            ++newY;
        }

        /*
        for (int i = 0; i < op1.size(); ++i) cout << op1[i].x << ' ' << op1[i].y << '\n';
        for (int i = 0; i < op2.size(); ++i) cout << op2[i].x << ' ' << op2[i].y << '\n';
        */

        sort(op1.begin(), op1.end(), ordId());
        sort(op2.begin(), op2.end(), ordId());
        if (same(op1, op2)) cout << "yes\n";
        else {
            rotate90(op1, newY - 1);
            if (same(op1, op2)) cout << "yes\n";
            else {
                rotate90(op1, newY - 1);
                if (same(op1, op2)) cout << "yes\n";
                else {
                    rotate90(op1, newY - 1);
                    if (same(op1, op2)) cout << "yes\n";
                    else cout << "no\n";
                }
            }
        }

    }
    return 0;
}
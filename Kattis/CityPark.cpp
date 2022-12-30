#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
#define ll long long
#define um unordered_map

struct UFDS {
    vector<int> p;
    vector<int> setArea;
    UFDS(int n) : p(n, 0), setArea(n, 0) {
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    int find(int x) {
        return (p[x] == x) ? x : p[x] = find(p[x]);
    }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        setArea[a] += setArea[b];
        p[b] = a;
    }
    void setSetArea(int x, int area) {
        setArea[x] = area;
    }
    int maxArea() const {
        int ret = 0;
        for (int i = 0; i < setArea.size(); ++i) {
            if (setArea[i] > ret) ret = setArea[i];
        }
        return ret;
    }
};

struct rect {
    int x, y, w, h;
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, x, y, w, h;
    cin >> n;

    vector<rect> rects(n + 1);
    um<int, int> xMap, yMap;
    set<int> xVals, yVals;
    for (int i = 1; i <= n; ++i) {//numbered from 1 to n
        cin >> rects[i].x >> rects[i].y >> rects[i].w >> rects[i].h;
        xVals.insert(rects[i].x);
        xVals.insert(rects[i].x + rects[i].w);
        yVals.insert(rects[i].y);
        yVals.insert(rects[i].y+ rects[i].h);
    }
    //compress the coordinates
    int nxt = 0;
    for (int curr : xVals) {
        xMap[curr] = nxt++;
    }
    nxt = 0;
    for (int curr : yVals) {
        yMap[curr] = nxt++;
    }

    UFDS uf(n+1);
    um<int, um<int, int>> ptsToSet;
    for(int i = 1; i <= n; ++i){
        x = xMap[rects[i].x];
        y = yMap[rects[i].y];
        w = xMap[rects[i].x + rects[i].w] - x;
        h = yMap[rects[i].y + rects[i].h] - y;
        uf.setSetArea(i, rects[i].w * rects[i].h);
        //traverse its border
        for (int ox = 0; ox <= w; ++ox) {//bottom
            if (ptsToSet[x + ox][y]) uf.join(i, ptsToSet[x + ox][y]);
            else ptsToSet[x + ox][y] = i;
        }
        for (int oy = 1; oy <= h; ++oy) {//right side
            if (ptsToSet[x + w][y+oy]) uf.join(i, ptsToSet[x + w][y+oy]);
            else ptsToSet[x + w][y+oy] = i;
        }
        for (int ox = w-1; ox >= 0; --ox) {//top
            if (ptsToSet[x + ox][y + h]) uf.join(i, ptsToSet[x + ox][y + h]);
            else ptsToSet[x + ox][y + h] = i;
        }
        for (int oy = h - 1; oy > 0; --oy) {//left side
            if (ptsToSet[x][y + oy]) uf.join(i, ptsToSet[x][y + oy]);
            else ptsToSet[x][y + oy] = i;
        }
    }

    cout << uf.maxArea() << '\n';

    return 0;
}
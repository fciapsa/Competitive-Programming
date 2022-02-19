#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <utility>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;
#define ll long long

int n, k;
vector<string> mat(8);

ll sol = 0;
unsigned long long state;
unordered_set<unsigned long long> visited;

struct coord {
    int x, y;
};

void dfs(int num) {//num: num squares left to color red

    if (visited.count(state)) return;//already explored
    visited.insert(state);

    if (num == 0) {
        ++sol;
        return;
    }

    vector<coord> next;
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j){
            if (mat[i][j] == '.') {
                bool red = false;
                if (i > 0 && mat[i - 1][j] == '@') red = true;
                else if (i < n - 1 && mat[i + 1][j] == '@') red = true;
                else if (j%n != n-1 && j < n - 1 && mat[i][j + 1] == '@') red = true;
                else if (j%n && j > 0 && mat[i][j - 1] == '@') red = true;
                if(red) next.push_back({ i,j });
            }
        }
    }
   
    int aux;
    for (coord dest : next) {
        aux = dest.x * n + dest.y;
        state += ((unsigned long long)1 << aux);
        mat[dest.x][dest.y] = '@';
        dfs(num - 1);
        mat[dest.x][dest.y] = '.';
        state -= ((unsigned long long)1 << aux);
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> mat[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == '.') {
                mat[i][j] = '@';
                state = (unsigned long long)1 << (i * n + j);
                dfs(k - 1);
                mat[i][j] = '.';
            }
        }
    }

    cout << sol << '\n';
    
    return 0;
}
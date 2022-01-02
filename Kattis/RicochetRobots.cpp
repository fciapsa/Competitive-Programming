#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define ll long long
using namespace std;

struct pos {
    int x, y;
};

unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int,int>>>>> mp;
int n, c, f, l;
pos goal;

void ramifica(int step, vector<vector<char>>& mat, vector<pos>& rbs, int& sol) {
    vector<int> posr(4,0);
    posr[0] = rbs[0].y + rbs[0].x * c;
    if(n > 1) posr[1] = rbs[1].y + rbs[1].x * c;
    if(n > 2) posr[2] = rbs[2].y + rbs[2].x * c;
    if(n > 3) posr[3] = rbs[3].y + rbs[3].x * c;
    
    ++mp[posr[0]][posr[1]][posr[2]][posr[3]][step];

    if (rbs[0].x == goal.x && rbs[0].y == goal.y) {
        if (step < sol) sol = step;
    }
    else if (step < l) {
        pos start, dest;
        for (int i = 0; i < n; ++i) {
            start.x = rbs[i].x;
            start.y = rbs[i].y;

            //hacia arriba
            dest.x = start.x;
            dest.y = start.y;
            while (dest.x > 0 && mat[dest.x - 1][dest.y] == '.') --dest.x;
            if (dest.x != start.x) {
                rbs[i].x = dest.x;
                rbs[i].y = dest.y;
                posr[i] = dest.y + dest.x * c;
                mat[dest.x][dest.y] = char(int('0') + i + 1);
                mat[start.x][start.y] = '.';

                if (mp[posr[0]][posr[1]][posr[2]][posr[3]][step+1] == 0) ramifica(step + 1, mat, rbs, sol);

                rbs[i].x = start.x;
                rbs[i].y = start.y;
                posr[i] = start.y + start.x * c;
                mat[start.x][start.y] = char(int('0') + i + 1);
                mat[dest.x][dest.y] = '.';
            }

            //hacia abajo
            dest.x = start.x;
            dest.y = start.y;
            while (dest.x < f-1 && mat[dest.x + 1][dest.y] == '.') ++dest.x;
            if (dest.x != start.x) {
                rbs[i].x = dest.x;
                rbs[i].y = dest.y;
                posr[i] = dest.y + dest.x * c;
                mat[dest.x][dest.y] = char(int('0') + i + 1);
                mat[start.x][start.y] = '.';

                if (mp[posr[0]][posr[1]][posr[2]][posr[3]][step+1] == 0) ramifica(step + 1, mat, rbs, sol);
                rbs[i].x = start.x;
                rbs[i].y = start.y;
                posr[i] = start.y + start.x * c;
                mat[start.x][start.y] = char(int('0') + i + 1);
                mat[dest.x][dest.y] = '.';
            }

            //izquierda
            dest.x = start.x;
            dest.y = start.y;
            while (dest.y > 0 && mat[dest.x][dest.y - 1] == '.') --dest.y;
            if (dest.y != start.y) {
                rbs[i].x = dest.x;
                rbs[i].y = dest.y;
                posr[i] = dest.y + dest.x * c;
                mat[dest.x][dest.y] = char(int('0') + i + 1);
                mat[start.x][start.y] = '.';

                if (mp[posr[0]][posr[1]][posr[2]][posr[3]][step+1] == 0) ramifica(step + 1, mat, rbs, sol);
                rbs[i].x = start.x;
                rbs[i].y = start.y;
                posr[i] = start.y + start.x * c;
                mat[start.x][start.y] = char(int('0') + i + 1);
                mat[dest.x][dest.y] = '.';
            }

            //derecha
            dest.x = start.x;
            dest.y = start.y;
            while (dest.y < c-1 && mat[dest.x][dest.y + 1] == '.') ++dest.y;
            if (dest.y != start.y) {
                rbs[i].x = dest.x;
                rbs[i].y = dest.y;
                posr[i] = dest.y + dest.x * c;
                mat[dest.x][dest.y] = char(int('0') + i + 1);
                mat[start.x][start.y] = '.';

                if (mp[posr[0]][posr[1]][posr[2]][posr[3]][step + 1] == 0) ramifica(step + 1, mat, rbs, sol);
                rbs[i].x = start.x;
                rbs[i].y = start.y;
                posr[i] = start.y + start.x * c;
                mat[start.x][start.y] = char(int('0') + i + 1);
                mat[dest.x][dest.y] = '.';
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> c >> f >> l;
    vector<vector<char>> mat(f, vector<char>(c));
    vector<pos> rbs(n);
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> mat[i][j];
            if (mat[i][j] == '1' || mat[i][j] == '2' || mat[i][j] == '3' || mat[i][j] == '4')
                rbs[int(mat[i][j]) - int('0') - 1] = { i,j };

            if (mat[i][j] == 'X') {
                goal = { i,j };
                mat[i][j] = '.';
            }
        }
    }

    int sol = l + 1;
    ramifica(0, mat, rbs, sol);
    if (sol <= l) cout << sol << '\n';
    else cout << "NO SOLUTION\n";

return 0;
}
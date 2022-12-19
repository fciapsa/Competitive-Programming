#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> pots = { 1000000, 100000, 10000, 1000, 100, 10, 1 };
vector<char> rep = { 'H','R','D','F','C','G','T' };

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n) {
        for (int i = 0; i < pots.size(); ++i) {
            while (n >= pots[i]) {
                cout << rep[i];
                n -= pots[i];
            }
        }
        cout << '\n';
        cin >> n;
    }

    return 0;
}
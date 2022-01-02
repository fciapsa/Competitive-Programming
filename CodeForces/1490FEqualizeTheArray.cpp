#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <climits>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, x, sol, aux;
    cin >> tc;
    while (tc--) {
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            ++mp[x];
        }

        vector<int> reps;
        for (auto it = mp.begin(); it != mp.end(); ++it) reps.push_back(it->second);
        sort(reps.begin(), reps.end());
        vector<int> racc(reps.size());
        racc[reps.size() - 1] = reps[reps.size() - 1];
        for (int i = reps.size() - 2; i >= 0; --i) racc[i] = reps[i] + racc[i + 1];
        

        vector<int> accums(reps.size()+1);
        accums[0] = 0;
        for (int i = 1; i <= reps.size(); ++i) accums[i] = reps[i-1] + accums[i - 1];

        sol = INT_MAX;
        for (int i = 0; i < reps.size(); ++i) {
            aux = accums[i] + (racc[i] - (reps.size()-i) * reps[i]);
            if (aux < sol) sol = aux;
        }

        cout << sol << '\n';
    }

    return 0;
}
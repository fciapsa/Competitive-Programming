#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int s0, s1, r0, r1, ss0, ss1, rr0, rr1;
    cin >> ss0 >> ss1 >> rr0 >> rr1;
    while (ss0 != 0) {
        s0 = max(ss0, ss1);
        s1 = min(ss0, ss1);
        r0 = max(rr0, rr1);
        r1 = min(rr0, rr1);

        if (s0 == 2 && s1 == 1) {
            if (r0 == 2 && r1 == 1) cout << "Tie.\n";
            else cout << "Player 1 wins.\n";
        }
        else if (s0 == s1) {
            if(r0 == 2 && r1 == 1) cout << "Player 2 wins.\n";
            else if (r0 == r1) {
                if(s0 > r0)cout << "Player 1 wins.\n";
                else if(s0 == r0) cout << "Tie.\n";
                else cout << "Player 2 wins.\n";
            }
            else cout << "Player 1 wins.\n";
        }
        else {
            if (r0 == 2 && r1 == 1) cout << "Player 2 wins.\n";
            else if(r0 == r1) cout << "Player 2 wins.\n";
            else {
                if(s0 > r0) cout << "Player 1 wins.\n";
                else if (s0 == r0) {
                    if(s1 > r1) cout << "Player 1 wins.\n";
                    else if(s1 == r1) cout << "Tie.\n";
                    else cout << "Player 2 wins.\n";
                }
                else cout << "Player 2 wins.\n";
            }
        }
        cin >> ss0 >> ss1 >> rr0 >> rr1;
    }

    return 0;
}
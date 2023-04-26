#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define LIVES 7

int main() {
    std::ios::sync_with_stdio(false);
    string word, guess;
    cin >> word;
    while (word != ".") {
        cin >> guess;
        set<char> good(word.begin(), word.end()), used;

        int correct = 0, wrong = 0;
        for (int i = 0; i < guess.size() && correct < good.size() && wrong < LIVES; ++i) {
            if (used.count(guess[i])) continue;

            if (good.count(guess[i])) ++correct;
            else ++wrong;
            used.insert(guess[i]);
        }

        if (correct == good.size()) cout << "SALVADO\n";
        else if (wrong == LIVES) cout << "AHORCADO\n";
        else cout << "COLGANDO\n";

        cin >> word;
    }

    return 0;
}
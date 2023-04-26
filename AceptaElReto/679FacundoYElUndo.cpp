#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    string s;
    cin >> tc;
    while (tc--) {
        deque<string> dq;
        stack<string> undone;
        cin >> s;
        while (s != ".") {
            if (s == "<") {
                if (dq.size()) {
                    undone.push(dq.back());
                    dq.pop_back();
                }
            }
            else if (s == ">") {
                if (undone.size()) {
                    dq.push_back(undone.top());
                    undone.pop();
                }
                else if (dq.size()) dq.push_back(dq.back());
            }
            else {
                dq.push_back(s);
                while (undone.size()) undone.pop();
            }
            cin >> s;
        }

        if (dq.size()) {
            cout << dq.front();
            dq.pop_front();
        }
        while (dq.size()) {
            cout << ' ' << dq.front();
            dq.pop_front();
        }
        cout << '\n';
    }

    return 0;
}
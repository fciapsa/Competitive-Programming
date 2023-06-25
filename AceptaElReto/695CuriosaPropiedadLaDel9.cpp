#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string num;
    cin >> num;
    while (num != "0") {
        sort(num.begin(), num.end());
        int num2 = stoi(num);
        sort(num.rbegin(), num.rend());
        int num1 = stoi(num);
        int resta = num1 - num2;
        cout << num1 << " - " << num2 << " = " << resta << " = " << resta / 9 << " x 9\n";

        cin >> num;
    }

    return 0;
}
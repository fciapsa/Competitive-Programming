#include <bits/stdc++.h>

using namespace std;
#define ll long long

map<char, char> mp = {
    {' ', ' '},
    {'1', '`'},
    {'2', '1'},
    {'3', '2'},
    {'4', '3'},
    {'5', '4'},
    {'6', '5'},
    {'7', '6'},
    {'8', '7'},
    {'9', '8'},
    {'0', '9'},
    {'-', '0'},
    {'=', '-'},
    {'W', 'Q'},
    {'E', 'W'},
    {'R', 'E'},
    {'T', 'R'},
    {'Y', 'T'},
    {'U', 'Y'},
    {'I', 'U'},
    {'O', 'I'},
    {'P', 'O'},
    {'[', 'P'},
    {']', '['},
    {'\\', ']'},
    {'S', 'A'},
    {'D', 'S'},
    {'F', 'D'},
    {'G', 'F'},
    {'H', 'G'},
    {'J', 'H'},
    {'K', 'J'},
    {'L', 'K'},
    {';', 'L'},
    {'\'', '\;'},
    {'X', 'Z'},
    {'C', 'X'},
    {'V', 'C'},
    {'B', 'V'},
    {'N', 'B'},
    {'M', 'N'},
    {',', 'M'},
    {'.', ','},
    {'/', '.'},
};

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    while (cin) {
        for (int i = 0; i < s.size(); ++i) {
            s[i] = mp[s[i]];
        }
        cout << s << '\n';
    getline(cin, s);
    }

    return 0;
}
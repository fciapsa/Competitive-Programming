#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <utility>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s1, s2, s3, s4;
    map<string, int> mp;
    cin >> s1 >> s2 >> s3 >> s4;
    ++mp[s1];
    ++mp[s2];
    ++mp[s3];
    ++mp[s4];
    if (mp["H"] && mp["2B"] && mp["3B"] && mp["HR"]) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
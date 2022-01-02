#include <iostream>
#include <string>

int main(){
	std::string s;
	std::cin >> s;
	if (s[2] == s[3] && s[4] == s[5]) std::cout << "Yes\n";
	else std::cout << "No\n";
return 0;
}